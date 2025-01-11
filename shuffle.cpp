#include <iostream>
#include <pthread.h>
#include <vector>
#include <algorithm>
#include "shuffle.h"
#include "globals.h"

void* shuffle_pairs(void* arg) 
{
    pthread_mutex_lock(&map_mutex);

    sort(shared_map_data.begin(), shared_map_data.end());

    vector<pair<string, int>> current_group;

    for (size_t i = 0; i < shared_map_data.size(); ++i) 
    {
        if (current_group.empty() || shared_map_data[i].first == current_group.back().first) 
        {
            current_group.push_back(shared_map_data[i]);
        } 
        else 
        {
            shuffled_data.push_back(current_group);
            current_group.clear();
            current_group.push_back(shared_map_data[i]);
        }
    }

    if (!current_group.empty()) 
    {
        shuffled_data.push_back(current_group);
    }

    pthread_mutex_unlock(&map_mutex);

    return nullptr;
}
