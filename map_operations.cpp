#include <iostream>
#include <pthread.h>
#include "map_operations.h"
#include "globals.h"
void* add_to_map(void* arg) 
{
    vector<string>* part = (vector<string>*)arg;

    pthread_mutex_lock(&map_mutex);

    for (const auto& word : *part) 
    {
        shared_map_data.push_back({word, 1});
    }

    pthread_mutex_unlock(&map_mutex);
    return nullptr;
}
