#include <iostream>
#include <vector>
#include <pthread.h>
#include "split_sentence.h"
#include "globals.h"
void* split_sentence(void* arg) 
{
    string sentence = *(string*)arg;
    vector<string>* list_of_words = new vector<string>();
    string temp_word = "";

    for (int i = 0; sentence[i] != '\0'; i++) 
    {
        if (sentence[i] == ' ') 
        {
            list_of_words->push_back(temp_word);
            temp_word = "";
        } 
        else 
        {
            temp_word += sentence[i];
        }
    }
    if (!temp_word.empty()) 
    {
        list_of_words->push_back(temp_word);
    }
    pthread_exit((void*)(list_of_words));
}
