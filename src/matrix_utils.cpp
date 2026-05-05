#include <vector>
#include <cstdlib>

using Matrix = std::vector<std::vector<int>>;

Matrix generateMatrix(int n){
	Matrix mat(n, std::vector<int>(n));
	for(int i = 0; i <n; i++){
		for(int j = 0; j < n; j++){
			mat [i][j] = rand() % 10;
		}
	}
	return mat;
}

Matrix addMatrix(const Matrix& A, const Matrix& B) {
	int n = A.size();
	Matrix C(n, std::vector<int>(n));

	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	return C;
}

Matrix subtractMatrix( const Matrix& A, const Matrix& B){
	int n = A.size();
	Matrix C(n, std::vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	return C;
}
