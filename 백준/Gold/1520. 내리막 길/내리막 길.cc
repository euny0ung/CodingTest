#include <iostream>
using namespace std;

int arr[501][501] = { 0, };
int dp[501][501] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N = 0, M = 0;

bool isRange(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}

int dfs(int x, int y) {

	// 마지막 칸인 경우
	if (x == N - 1 && y == M - 1) return 1;
	// 이미 방문한 경우
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (isRange(nextX, nextY) && arr[nextX][nextY] < arr[x][y]) {
			dp[x][y] += dfs(nextX,nextY);
		}
	}

	return dp[x][y];
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0, 0)<< "\n";
}