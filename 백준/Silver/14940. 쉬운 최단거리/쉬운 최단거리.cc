#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int bfs_cnt = 0;
int N = 0, M = 0;

queue<pair<int,int>>q;

bool isRange(int x, int y) {
	if (x < N && x >= 0 && y < M && y >= 0) return true;
	return false;
}

void bfs() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
				int nextX = dx[i]+x;
				int nextY = dy[i]+y;

				// 범위를 넘지 않고 -1이면 값 변경, 큐에 넣기
				if (isRange(nextX, nextY) && arr[nextX][nextY] == -1) {
					arr[nextX][nextY] = arr[x][y] + 1;
					q.push(make_pair(nextX, nextY));
				}
			}
	}

	
}

int main() {
	int input;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			if (input == 2) {
				q.push(make_pair(i, j));
			}
			// 3퍼에서 틀렸을 때 else 조건 넣으니까 90퍼까지 올랐음...
			else {
				arr[i][j] = input - 2;
			}
			
		}
	}

	bfs();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 원래 갈 수 있는 땅이지만 도달 못했을 경우 -1 출력
			if (arr[i][j] == -2) cout << "0 ";
			else if (arr[i][j] == -1) cout << "-1 ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}