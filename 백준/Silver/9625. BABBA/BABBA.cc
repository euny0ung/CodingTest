#include <iostream>
using namespace std;

int main() {

	int K = 0;
	int A[46] = { 0, };
	int B[46] = { 0, };

	cin >> K;

	A[0] = 1;
	B[0] = 0;

	for (int i = 1; i <= K; i++) {
		A[i] = B[i - 1];
		B[i] = A[i - 1] + A[i];
	}

	cout << A[K] <<" "<< B[K] << "\n";

	return 0;
}