// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include <pthread.h>
#include <string>
using namespace std;

extern vector<pair<string, int>> shared_map_data;
extern vector<vector<pair<string, int>>> shuffled_data;
extern vector<pair<string, int>> reduced_data;
extern pthread_mutex_t map_mutex;
#define MAX_THREADS 20

#endif // GLOBALS_H