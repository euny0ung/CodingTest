#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[501][501];
bool visited[501][501];
queue<pair<int,int>>q;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool isRange(int x, int y) {
	return x >= 0 && x < N&& y >= 0 && y < M;
}

int bfs(int x, int y) {
	int width = 1;
	q.push({ x,y });
	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = nowX + dx[i];
			int ny = nowY + dy[i];
			if (isRange(nx, ny) && !visited[nx][ny] && arr[nx][ny]==1) {
				width++;
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
	return width;
}

int main() {

	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0, maxWidth=0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				cnt++;
				visited[i][j] = true;
				int res = bfs(i, j);
				maxWidth=max(maxWidth, res);
			}
		}
	}

	cout << cnt << "\n";
	cout << maxWidth << "\n";

	return 0;
}