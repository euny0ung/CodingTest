#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main() {

	int N = 0;
	int T = 0, P = 0;
	int tCount = 0;
	int size[6] = { 0, };


	cin >> N;

	for (int i = 0; i < 6; i++) {
		cin >> size[i];
	}

	cin >> T >> P;

	for (int i = 0; i < 6; i++) {
	
		if (size[i] % T == 0) tCount += size[i] / T;
		else tCount += size[i] / T+1;
	}

	cout << tCount << "\n";
	cout << N / P << " " << N % P;


	return 0;
}