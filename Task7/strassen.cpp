#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix naiveMultiply(const Matrix& A, const Matrix& B) {
    int n = (int)A.size();
    Matrix C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    return C;
}

Matrix add(const Matrix& A, const Matrix& B) {
    int n = (int)A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix subtract(const Matrix& A, const Matrix& B) {
    int n = (int)A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Matrix getQuadrant(const Matrix& M, int r, int c, int size) {
    Matrix Q(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            Q[i][j] = M[r + i][c + j];
    return Q;
}

void setQuadrant(Matrix& M, const Matrix& Q, int r, int c) {
    int size = (int)Q.size();
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            M[r + i][c + j] = Q[i][j];
}

Matrix strassenMultiply(const Matrix& A, const Matrix& B) {
    int n = (int)A.size();

    if (n == 1) {
        return Matrix(1, vector<int>(1, A[0][0] * B[0][0]));
    }

    int h = n / 2;

    Matrix A11 = getQuadrant(A, 0, 0, h);
    Matrix A12 = getQuadrant(A, 0, h, h);
    Matrix A21 = getQuadrant(A, h, 0, h);
    Matrix A22 = getQuadrant(A, h, h, h);

    Matrix B11 = getQuadrant(B, 0, 0, h);
    Matrix B12 = getQuadrant(B, 0, h, h);
    Matrix B21 = getQuadrant(B, h, 0, h);
    Matrix B22 = getQuadrant(B, h, h, h);

    Matrix M1 = strassenMultiply(add(A11, A22), add(B11, B22));
    Matrix M2 = strassenMultiply(add(A21, A22), B11);
    Matrix M3 = strassenMultiply(A11, subtract(B12, B22));
    Matrix M4 = strassenMultiply(A22, subtract(B21, B11));
    Matrix M5 = strassenMultiply(add(A11, A12), B22);
    Matrix M6 = strassenMultiply(subtract(A21, A11), add(B11, B12));
    Matrix M7 = strassenMultiply(subtract(A12, A22), add(B21, B22));

    Matrix C11 = add(subtract(add(M1, M4), M5), M7);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = add(subtract(add(M1, M3), M2), M6);

    Matrix C(n, vector<int>(n, 0));
    setQuadrant(C, C11, 0, 0);
    setQuadrant(C, C12, 0, h);
    setQuadrant(C, C21, h, 0);
    setQuadrant(C, C22, h, h);

    return C;
}
