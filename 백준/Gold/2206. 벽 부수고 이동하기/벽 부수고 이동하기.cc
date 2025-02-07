#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

struct Position {
	int x, y, bomb;
};

int N, M;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int dist[1001][1001][2];
int map[1001][1001];
queue<Position>q;

bool isRange(int x, int y) {
	return x >= 0 && x < N&& y >= 0 && y < M;
}

int bfs(int x, int y) {
	q.push({ x,y,0 });

	while (!q.empty()) {
		int nowX = q.front().x;
		int nowY = q.front().y;
		int bomb = q.front().bomb;
		q.pop();

		// 도착지점인 경우 (bomb때문에 여기서 return 해야할듯)
		if (nowX == N - 1 && nowY == M - 1) return dist[nowX][nowY][bomb];

		for (int i = 0; i < 4; i++) {
			int nx = nowX + dx[i];
			int ny = nowY + dy[i];
			if (!isRange(nx, ny)) continue;
			// 벽이 아니고 아직 방문하지 않은 경우
			if (dist[nx][ny][bomb] == 0 && map[nx][ny]==0) {
				q.push({ nx, ny, bomb });
				dist[nx][ny][bomb] = dist[nowX][nowY][bomb] + 1;
			}
			// 벽을 안부순 상태에서 벽을 만났을 경우 bomb 바꿈
			else if(bomb==0 && dist[nx][ny][bomb]==0 && map[nx][ny]==1) {
				q.push({ nx, ny, 1 });
				dist[nx][ny][1] = dist[nowX][nowY][0] + 1;
			}
		}
	}

	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	string input;

	cin.ignore();

	for (int i = 0; i < N; i++) {
		getline(cin, input);
		for (int j = 0; j < M; j++) {
			map[i][j] = input[j] - '0';
		}
	}

	dist[0][0][0] = 1;

	cout<< bfs(0, 0)<<"\n";



	return 0;
}