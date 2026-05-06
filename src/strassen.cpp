#include <vector>
#include <cmath>

using Matrix = std::vector<std::vector<int>>;

int STRASSEN_BASE = 64;

extern Matrix addMatrix(const Matrix&, const Matrix&);
extern Matrix subtractMatrix(const Matrix&, const Matrix&);
extern Matrix multiplyStandard(const Matrix&, const Matrix&);

Matrix subMatrix(const Matrix& A, int row, int col, int size) {
    Matrix result(size, std::vector<int>(size));
    for (int i = 0; i < size; i++)
    	for (int j = 0; j < size; j++)
            result[i][j] = A[i + row][j + col];
    return result;
}

void joinMatrix(Matrix& C, const Matrix& P, int row, int col) {
	    int size = P.size();
    for (int i = 0; i < size; i++)
    	for (int j = 0; j < size; j++)
            C[i + row][j + col] = P[i][j];
}

Matrix strassen(const Matrix& A, const Matrix& B) {
	int n = A.size();

	if(n<= STRASSEN_BASE)
		return multiplyStandard(A, B);
	int k = n/2;

	Matrix A11 = subMatrix(A, 0, 0, k);
   	Matrix A12 = subMatrix(A, 0, k, k);
    	Matrix A21 = subMatrix(A, k, 0, k);
    	Matrix A22 = subMatrix(A, k, k, k);

    	Matrix B11 = subMatrix(B, 0, 0, k);
    	Matrix B12 = subMatrix(B, 0, k, k);
   	Matrix B21 = subMatrix(B, k, 0, k);
   	Matrix B22 = subMatrix(B, k, k, k);

	Matrix M1 = strassen(addMatrix(A11, A22), addMatrix(B11, B22));
    	Matrix M2 = strassen(addMatrix(A21, A22), B11);
    	Matrix M3 = strassen(A11, subtractMatrix(B12, B22));
   	Matrix M4 = strassen(A22, subtractMatrix(B21, B11));
    	Matrix M5 = strassen(addMatrix(A11, A12), B22);
    	Matrix M6 = strassen(subtractMatrix(A21, A11), addMatrix(B11, B12));
    	Matrix M7 = strassen(subtractMatrix(A12, A22), addMatrix(B21, B22));

	Matrix C(n, std::vector<int>(n));

	Matrix C11 = addMatrix(subtractMatrix(addMatrix(M1, M4), M5), M7);
    	Matrix C12 = addMatrix(M3, M5);
    	Matrix C21 = addMatrix(M2, M4);
    	Matrix C22 = addMatrix(subtractMatrix(addMatrix(M1, M3), M2), M6);

	joinMatrix(C, C11, 0, 0);
	joinMatrix(C, C12, 0, k);
	joinMatrix(C, C21, k, 0);
	joinMatrix(C, C22, k, k);

	return C;
}
