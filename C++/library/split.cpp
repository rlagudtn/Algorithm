#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string tmp;
    while (getline(ss, tmp, delimiter)) result.push_back(tmp);
    return result;
}
