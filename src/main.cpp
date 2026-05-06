#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <algorithm>

using namespace std;
using namespace chrono;

using Matrix = vector<vector<int>>;

extern Matrix generateMatrix(int n);
extern Matrix multiplyStandard(const Matrix&, const Matrix&);
extern Matrix strassen(const Matrix&, const Matrix&);

double median(vector<double>& v){
	int n = v.size();
	if(n%2 == 0)
		return (v[n/2 - 1] + v[n/2]) / 2.0;
	else
		return v[n/2];
}

double measureStandard(int n) {
    Matrix A = generateMatrix(n);
    Matrix B = generateMatrix(n);

    auto start = high_resolution_clock::now();
    Matrix C = multiplyStandard(A, B);
    auto end = high_resolution_clock::now();

    return duration<double, milli>(end - start).count();
}

double measureStrassen(int n) {
    Matrix A = generateMatrix(n);
    Matrix B = generateMatrix(n);

    auto start = high_resolution_clock::now();
    Matrix C = strassen(A, B);
    auto end = high_resolution_clock::now();

    return duration<double, milli>(end - start).count();
}

int main() {
	srand(time(0));
	vector<int> sizes = {2, 4, 8, 16, 32, 64, 128};

	for (int n : sizes) {
        vector<double> t1, t2;
        int runs = 20;

 		for (int i = 0; i < runs; i++) {
            		t1.push_back(measureStandard(n));
            		t2.push_back(measureStrassen(n));
        	}
   
	cout << n <<" "
		<< median(t1) << " "
		<<median(t2)
		<<endl;
	}
	return 0;
}
