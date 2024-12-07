#include <iostream>
using namespace std;


int N = 0, M = 0;
int arr[8] = { 0, };

void recursive(int idx) {

	if (idx == M) {
		
		for (int i = 0; i < M; i++) cout << arr[i] << " ";

		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		arr[idx] = i;
		recursive(idx + 1);
	}
}


int main() {

	cin >> N >> M;

	recursive(0);

	return 0;
}