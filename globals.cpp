// globals.cpp

#include "globals.h"
vector<pair<string, int>> shared_map_data;
vector<vector<pair<string, int>>> shuffled_data;
vector<pair<string, int>> reduced_data;
pthread_mutex_t map_mutex;