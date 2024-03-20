#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <chrono>
#include <filesystem>
#include <vector>

typedef long long int llint;
using namespace std;
using namespace chrono;
using namespace filesystem;


vector<string> get_name_matrix(const string& path);
size_t comp_time(const system_clock::time_point& start);
int get_size_matrix(const string& path);
void read_matrix(const string& path_file, llint* mat);
void write_matrix(const string& filename, llint* res, int size);
