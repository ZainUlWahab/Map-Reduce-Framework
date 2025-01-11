#ifndef SHUFFLE_H
#define SHUFFLE_H

#include <vector>
#include <string>
using namespace std;

extern vector<pair<string, int>> shared_map_data;
extern vector<vector<pair<string, int>>> shuffled_data;
extern pthread_mutex_t map_mutex;

void* shuffle_pairs(void* arg);
#endif