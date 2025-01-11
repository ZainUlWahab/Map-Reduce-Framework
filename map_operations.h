#ifndef MAP_OPERATIONS_H
#define MAP_OPERATIONS_H

#include <vector>
#include <string>

using namespace std;

extern vector<pair<string, int>> shared_map_data;
extern pthread_mutex_t map_mutex;
void* add_to_map(void* arg);

#endif
