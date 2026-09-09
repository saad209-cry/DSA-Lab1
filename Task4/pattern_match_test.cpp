#include <iostream>
#include <string>
using namespace std;

int naiveSearch(const string& text, const string& pattern);

void runTest(string name, int got, int expected) {
    cout << name << " -> got " << got << ", expected " << expected
         << " : " << (got == expected ? "PASS" : "FAIL") << endl;
}

int main() {
    string text = "algorithmsarefun";

    runTest("Pattern at beginning (algo)", naiveSearch(text, "algo"), 0);
    runTest("Pattern at end (fun)", naiveSearch(text, "fun"), 13);
    runTest("Pattern not present (tree)", naiveSearch(text, "tree"), -1);
    runTest("Empty pattern", naiveSearch(text, ""), 0);

    return 0;
}
