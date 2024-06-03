#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>  // pentru std::accumulate
using namespace std;

int main() {
	ifstream inputFile("compresie.in");
	ofstream outputFile("compresie.out");
	int n, m;
	std::vector<int> A, B;
	inputFile >> n;
	A.resize(n);
	for (int i = 0; i < n; ++i) {
		inputFile  >> A[i];
	}
	inputFile  >> m;
	B.resize(m);
	for (int i = 0; i < m; ++i) {
		inputFile  >> B[i];
	}

	// do sum of A and sum of B
	int sumA = std::accumulate(A.begin(), A.end(), 0);
	int sumB = std::accumulate(B.begin(), B.end(), 0);
	if(sumA != sumB) {
	outputFile << -1;
} else {
	int i = 0, j = 0;
	int count = 0;
	loop_start:
	if(i < n && j < m) {
		if(A[i] == B[j]) {
			i++;
			j++;
			count++;
			goto loop_start;
		} else {
			if(A[i] < B[j]) {
				A[i+1] += A[i];
				i++;
			} else {
				B[j+1] += B[j];
				j++;
			}
			goto loop_start;
		}
	}
	outputFile << count;
}

	inputFile.close();
	outputFile.close();
	return 0;
}
