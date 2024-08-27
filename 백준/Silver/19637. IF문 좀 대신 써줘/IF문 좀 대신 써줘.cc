#include <iostream>
#include <vector>
using namespace std;

int binary_search(const vector<int>& standard, int power) {
	int left = 0, right = standard.size() - 1;

	while (left < right) {
		int middle = (left + right) / 2;

		if (standard[middle] >= power) {
			right = middle;
		}
		else {
			left = middle+1;
		}
	}

	return left;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, M = 0;
	string str = "";
	int power=0;

	cin >> N >> M;

	vector<string>titles(N);
	vector<int>standard(N);

	for (int i = 0; i < N; i++) {
		cin >> titles[i] >> standard[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> power;

		int idx= binary_search(standard, power);
		cout << titles[idx] << "\n";
	}

	return 0;
}