#include <iostream>
using namespace std;

int main() {

	int N = 0, M = 0;
	int a = 0, b = 0;
	int map[101][101] = { 0, };

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			// 자기 자신이 아니고 이어지지 않았으면
			if (i != j && map[i][j] != 1) {
				map[i][j] = 1000000;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (map[i][j] + map[i][k] < map[j][k]) {
					map[j][k] = map[j][i] + map[i][k];
				}
			}
		}
	}

	int val = 1000000;
	int result = 0;

	for (int i = 1; i <= N; i++) {
		int temp = 0;

		for (int j = 1; j <= N; j++) {
			temp += map[i][j];
		}
		if (temp < val) {
			val = temp;
			result = i;
		}
	}

	cout << result << "\n";

	return 0;
}