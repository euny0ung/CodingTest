#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N = 0, L = 0, R = 0, ans=0;
int arr[50][50] = { 0, };
bool visited[50][50] = { false, };

struct Point {
	int x, y;

	Point(int x, int y) : x(x), y(y) {}
};

queue<Point>q;
queue<Point>store;

bool isRange(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }

bool bfs(int x, int y) {
	q.push({ x,y });
	store.push({ x,y });
	int result = arr[x][y], cnt = 1;
	bool moved = false;

	while (!q.empty()) {

		Point p = q.front();
		q.pop();
		visited[p.x][p.y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];

			if (isRange(nx, ny) && !visited[nx][ny]) {
				int diff = abs(arr[p.x][p.y] - arr[nx][ny]);

				if (diff >= L && diff <= R) {
					q.push({ nx, ny });
					store.push({ nx, ny });
					visited[nx][ny] = true;
					result += arr[nx][ny];
					cnt++;
					moved = true;
				}
			}
		}
	}

	
	
		int value = result / cnt;
		while (!store.empty()) {
			Point p = store.front();

			store.pop();

			arr[p.x][p.y] = value;
		}


	return moved;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	while (true) {
		bool flag = false;
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					if(bfs(i,j)) flag = true; // 한번이라도 true였으면
				}
			}
		}

		if (!flag) break;
		ans++;
	}

	cout << ans << "\n";

	return 0;
}