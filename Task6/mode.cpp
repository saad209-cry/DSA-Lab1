#include <vector>
#include <map>
using namespace std;

vector<int> findModes(const vector<int>& arr) {
    vector<int> modes;
    if (arr.empty()) return modes;

    map<int, int> frequency;
    for (int v : arr) {
        frequency[v]++;
    }

    int highest = 0;
    for (auto entry : frequency) {
        if (entry.second > highest) highest = entry.second;
    }

    for (auto entry : frequency) {
        if (entry.second == highest) modes.push_back(entry.first);
    }
    return modes;
}
