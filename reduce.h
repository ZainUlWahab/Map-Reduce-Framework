#ifndef REDUCE_H
#define REDUCE_H

#include <vector>
#include <string>
using namespace std;

extern vector<pair<string, int>> shared_map_data;
extern vector<vector<pair<string, int>>> shuffled_data;
extern vector<pair<string, int>> reduced_data;
extern pthread_mutex_t map_mutex;

void* reduce_group(void* arg);
void parallel_reduce();

#endif