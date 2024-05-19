#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <chrono>
#include <filesystem>
#include <vector>

using namespace std;
using namespace chrono;
using namespace filesystem;


vector<string> get_name_matrix(const string& path);
int comp_time(const system_clock::time_point& start);
int get_size_matrix(const string& path);
void read_matrix(const string& path_file, int* mat);
void write_matrix(const string& filename, int* res, int size);
