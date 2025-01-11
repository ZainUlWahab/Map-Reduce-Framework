#include <iostream>
#include <pthread.h>
#include <vector>
#include <map>
#include "reduce.h"
#include "globals.h"

void* reduce_group(void* arg) 
{
    vector<pair<string, int>>* group = (vector<pair<string, int>>*)arg;
    map<string, int> key_count;

    for (const auto& kv : *group) 
    {
        key_count[kv.first] += kv.second;
    }

    pthread_mutex_lock(&map_mutex);

    for (const auto& kv : key_count) 
    {
        reduced_data.push_back({kv.first, kv.second});
    }

    pthread_mutex_unlock(&map_mutex);

    return nullptr;
}

void parallel_reduce() 
{
    vector<pthread_t> threads;
    int num_groups = shuffled_data.size();
    // int num_threads = min(MAX_THREADS, num_groups);

    for (int i = 0; i < num_groups; ++i) 
    {
        pthread_t tid;
        pthread_create(&tid, nullptr, reduce_group, &shuffled_data[i]);
        threads.push_back(tid);
    }

    for (auto& tid : threads) 
    {
        pthread_join(tid, nullptr);
    }
}