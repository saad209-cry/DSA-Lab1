#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix naiveMultiply(const Matrix& A, const Matrix& B);
Matrix strassenMultiply(const Matrix& A, const Matrix& B);

void printMatrix(Matrix M) {
    for (vector<int> row : M) {
        cout << "    ";
        for (int v : row) cout << v << "\t";
        cout << endl;
    }
}

void compareTest(string name, Matrix A, Matrix B, bool show) {
    Matrix s = strassenMultiply(A, B);
    Matrix n = naiveMultiply(A, B);

    cout << name << " -> Strassen == naive : " << (s == n ? "PASS" : "FAIL") << endl;

    if (show) {
        cout << "  Strassen result:" << endl;
        printMatrix(s);
        cout << "  Naive result:" << endl;
        printMatrix(n);
    }
}

Matrix randomMatrix(int n) {
    Matrix M(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = rand() % 10;
    return M;
}

int main() {
    srand(42);

    Matrix A2 = {{1, 2},
                 {3, 4}};
    Matrix B2 = {{5, 6},
                 {7, 8}};
    compareTest("2x2 matrices", A2, B2, true);

    Matrix A4 = {{1, 2, 3, 4},
                 {5, 6, 7, 8},
                 {9, 1, 2, 3},
                 {4, 5, 6, 7}};
    Matrix B4 = {{2, 0, 1, 3},
                 {1, 4, 0, 2},
                 {3, 1, 5, 0},
                 {0, 2, 1, 4}};
    compareTest("4x4 matrices", A4, B4, false);

    for (int n : {2, 4, 8}) {
        Matrix A = randomMatrix(n);
        Matrix B = randomMatrix(n);
        compareTest("Random " + to_string(n) + "x" + to_string(n) + " matrices", A, B, false);
    }

    return 0;
}
