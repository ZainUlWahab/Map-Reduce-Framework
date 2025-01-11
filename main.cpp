#include <iostream>
#include <pthread.h>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include "globals.h"
using namespace std;

void* split_sentence(void* arg);
void* split_sentence(void* arg);
void* add_to_map(void* arg);
void* shuffle_pairs(void* arg);
void parallel_reduce();

int main() 
{
    string input;
    ifstream file("test1.txt");
    if (file.is_open()) 
    {
        getline(file, input, '\0');
        file.close();
        if (input.empty()) 
        {
            cerr << "File is empty. Bye Bye!" << endl;
            return 1;
        }
        string cleaned_input;
        for (char c : input) 
        {
            if (isalnum(c) || isspace(c))
            {
                cleaned_input += c;
            }
        }
        input = cleaned_input;
    }
    else 
    {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }
    cout<<input<<endl;
    pthread_mutex_init(&map_mutex, NULL);

    cout << "Splitting Phase... " << endl;
    pthread_t split_sentence_tid;
    pthread_create(&split_sentence_tid, nullptr, split_sentence, &input);

    void* result;
    pthread_join(split_sentence_tid, &result);
    vector<string>* words = (vector<string>*) result;

    int word_count = words->size();
    int part_size = word_count / 3;

    vector<string> part1(words->begin(), words->begin() + part_size);
    vector<string> part2(words->begin() + part_size, words->begin() + 2 * part_size);
    vector<string> part3(words->begin() + 2 * part_size, words->end());

    cout << "Splitting Phase Finished... " << endl;

    cout << endl << "Mapping Phase..." << endl;

    pthread_t thread1, thread2, thread3;
    pthread_create(&thread1, nullptr, add_to_map, &part1);
    pthread_create(&thread2, nullptr, add_to_map, &part2);
    pthread_create(&thread3, nullptr, add_to_map, &part3);

    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);
    pthread_join(thread3, nullptr);

    cout << "Shared map data (key and value):" << endl;
    for (const auto& pair : shared_map_data) 
    {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Mapping Phase finished..." << endl;

    cout << endl << "Shuffling Phase started..." << endl;

    pthread_t shuffle_thread;
    pthread_create(&shuffle_thread, nullptr, shuffle_pairs, nullptr);
    pthread_join(shuffle_thread, nullptr);

    cout << "Shuffled key-value groups:" << endl;
    for (const auto& group : shuffled_data) 
    {
        for (const auto& kv : group) 
        {
            cout << kv.first << ": " << kv.second << " ";
        }
        cout << endl;
    }

    cout << "Shuffling Phase finished..." << endl;

    cout << endl << "Reducing Phase started..." << endl;
    parallel_reduce();

    cout << "Reduced key-value pairs:\n";
    for (const auto& kv : reduced_data) 
    {
        cout << kv.first << ": " << kv.second << endl;
    }
    cout << "Reducing Phase finished..." << endl;

    cout << endl << "Final Output:" << endl;
    for (size_t i = 0; i < reduced_data.size(); ++i) 
    {
        cout << "(" << reduced_data[i].first << ", " << reduced_data[i].second << ")";
        if (i < reduced_data.size() - 1) 
        {
            cout << endl;
        }
    }
    cout<<endl;
    delete words;
    pthread_mutex_destroy(&map_mutex);

    return 0;
}