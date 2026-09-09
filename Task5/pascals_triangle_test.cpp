#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> generatePascalsTriangle(int n);

void printTriangle(vector<vector<int>> t) {
    for (vector<int> row : t) {
        cout << "    ";
        for (int v : row) cout << v << " ";
        cout << endl;
    }
}

void checkRows(string name, vector<vector<int>> t, int expectedRows) {
    cout << name << " -> " << t.size() << " row(s) : "
         << ((int)t.size() == expectedRows ? "PASS" : "FAIL") << endl;
}

int main() {
    vector<vector<int>> t0 = generatePascalsTriangle(0);
    checkRows("n = 0", t0, 0);

    vector<vector<int>> t1 = generatePascalsTriangle(1);
    checkRows("n = 1", t1, 1);
    printTriangle(t1);

    vector<vector<int>> t5 = generatePascalsTriangle(5);
    checkRows("n = 5", t5, 5);
    printTriangle(t5);

    vector<int> row5 = {1, 4, 6, 4, 1};
    bool ok = (t5.size() == 5 && t5[4] == row5);
    cout << "Row 5 == {1, 4, 6, 4, 1} : " << (ok ? "PASS" : "FAIL") << endl;

    return 0;
}
