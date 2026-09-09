#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findModes(const vector<int>& arr);

void runTest(string name, vector<int> got, vector<int> expected) {
    cout << name << " -> got { ";
    for (int v : got) cout << v << " ";
    cout << "} : " << (got == expected ? "PASS" : "FAIL") << endl;
}

int main() {
    vector<int> a = {3, 1, 3, 7, 3, 1};
    runTest("Unique mode", findModes(a), {3});

    vector<int> b = {2, 2, 5, 5, 9};
    runTest("Multiple modes", findModes(b), {2, 5});

    vector<int> c;
    runTest("Empty array", findModes(c), {});

    return 0;
}
