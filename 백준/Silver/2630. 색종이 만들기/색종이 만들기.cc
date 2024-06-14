#include <iostream>
#include <vector>
using namespace std;

int N, input;
int blue, white;
vector<vector<int>>v;

void div_func(int x, int y, int N) {
	int cnt = 0;
	// 조건 검사
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (v[i][j] == 1) cnt++;
		}
	}
	// 조건에 부합한 경우
	if (cnt == N * N) blue++;
	else if (cnt == 0) white++;
	// 조건에 부합하지 않으면 자르기
	else {
		div_func(x, y, N / 2);
		div_func(x + N / 2, y, N / 2);
		div_func(x, y + N / 2, N / 2);
		div_func(x + N / 2, y + N / 2, N / 2);
	}
	return;
}

int main() {

	cin >> N;

	v = vector<vector<int>>(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	div_func(0, 0, N);

	std::cout << white << "\n";
	std::cout << blue << "\n";

	return 0;
}