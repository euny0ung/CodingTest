#include <iostream>
#include <queue>
using namespace std;

int dx[8] = { 2,1,2,1,-2,-1, -2,-1 };
int dy[8] = { 1,2,-1,-2,-1,-2,1,2 };
int T = 0, X = 0, Y = 0, targetX = 0, targetY = 0, sz = 0;
int cnt = 1;
bool visited[300][300] = {};
int map[300][300];

queue < pair<int, int>>q;

bool isRange(int x, int y, int sz) {
	if (x < sz && x >= 0 && y < sz && y >= 0) return true;
	return false;
}

void bfs(int startX, int startY) {

	while (!q.empty()) {
	
		int nowX = q.front().first;
		int nowY = q.front().second;

		visited[nowX][nowY] = true;
		
		q.pop();

		if (nowX == targetX && nowY == targetY) {
			cout << map[nowX][nowY] << "\n";
			
			return;
		}

		for (int i = 0; i < 8; i++) {
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];
			
			// 범위 체크
			if (isRange(nextX, nextY, sz) && !visited[nextX][nextY]) {
				visited[nextX][nextY] = true;
				q.push({ nextX, nextY });
				map[nextX][nextY] =map[nowX][nowY]+ 1;
			}
		}
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> sz;
		cin >> X >> Y;
		cin >> targetX >> targetY;

		q.push({ X, Y });

		bfs(X, Y);


		for (int i = 0; i < 300; i++) {
			fill(visited[i], visited[i] + 300, false);
			fill(map[i], map[i] + 300, 0);
		}

		while (!q.empty()) {
			q.pop();
		}

	}

}