#include <iostream>
using namespace std;

int main() {

	int N = 0, K=0;
	int idx = 0, g = 0, s = 0, b = 0;
	int rank = 1;

	cin >> N >> K;

	int gold[1001] = {};
	int silver[1001] = {};
	int bronze[1001] = {};

	for (int i = 1; i <= N; i++) {
		cin >> idx >> g >> s >> b;
		gold[idx] = g;
		silver[idx] = s;
		bronze[idx] = b;
	}

	for (int i = 1; i <= N; i++) {
		if (gold[i] > gold[K]) rank++;
		else if (gold[i] == gold[K]) {
			if (silver[i] > silver[K]) rank++;
			else if (silver[i] == silver[K]) {
				if (bronze[i] > bronze[K]) {
					rank++;
				}
			}
		}
	}

	cout << rank << "\n";

	return 0;
}