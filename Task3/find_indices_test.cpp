#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findAllIndices(const vector<int>& arr, int key);

void runTest(string name, vector<int> got, vector<int> expected) {
    cout << name << " -> got { ";
    for (int v : got) cout << v << " ";
    cout << "} : " << (got == expected ? "PASS" : "FAIL") << endl;
}

int main() {
    vector<int> a = {4, 7, 2, 7, 9, 7};
    runTest("Multiple occurrences (key = 7)", findAllIndices(a, 7), {1, 3, 5});

    vector<int> b = {1, 2, 3, 4};
    runTest("Key not present (key = 10)", findAllIndices(b, 10), {});

    vector<int> c;
    runTest("Empty array (key = 5)", findAllIndices(c, 5), {});

    return 0;
}
