#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N = 0;
	int cand[50] = { 0, };
	int index=0;
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cand[i];
	}

	int me = cand[0];

	if (N == 1) {
		cout << 0 << "\n";
	}
	else {
		while (1) {
				int maxValue = 0;
				for (int i = 1; i < N; i++) {
					if (maxValue < cand[i]) {
						index = i;
						maxValue = cand[i];
					}
				}
				if (maxValue < me) break;
				cand[index]--;
				me++;
				
			}
	
		cout << me - cand[0] << "\n";
	}


	return 0;
}