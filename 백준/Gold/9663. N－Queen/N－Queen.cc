#include <iostream>
#include <math.h>
using namespace std;


int N = 0;
int row[15] = { 0, };
int cnt = 0;

// x는 열
void dfs(int x) {

	// 마지막 행까지 탐색한 경우
	if (x == N) {
		cnt++;
		return;
	}


	// 0행~n행까지 모든 이전 열들을 검사 후 조건에 맞으면 다음 행에 퀸 놓기
	for (int i = 0; i < N; i++) {
		bool isSafe = true;

		row[x] = i;

		// 모든 이전 열
		for (int j = 0; j < x; j++) {
			if (row[x] == row[j] || abs(x - j) == abs(row[x] - row[j])) {
				isSafe = false;
				break;
			}
		}

		if (isSafe) {
			dfs(x + 1);
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	dfs(0);

	cout << cnt << "\n";

	return 0;
}