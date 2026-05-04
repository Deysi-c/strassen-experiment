#include <vector>

using Matrix = std::vector<std::vector<int>>;

Matrix multiplyStandard(const Matrix& A, const Matrix& B) {
	int n = A.size();
	Matrix C(n, std::vector<int>(n,0));

	for(int i=0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
}
