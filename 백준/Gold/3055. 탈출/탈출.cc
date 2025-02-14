#include <iostream>
#include <queue>
using namespace std;

int R, C;
int cnt;
bool flag;
char map[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int,int>>dochi;
queue<pair<int, int>>water;

bool isRange(int x, int y) {
	return x >= 0 && x < R && y >= 0 && y < C;
}

void bfs() {
	while (!dochi.empty()) {
		cnt++;

		int sz = water.size();

		for (int i = 0; i < sz; i++) {
			int waterX = water.front().first;
			int waterY = water.front().second;
			water.pop();

			for (int j = 0; j < 4; j++) {
				int nx = waterX + dx[j];
				int ny = waterY + dy[j];
				if (isRange(nx, ny) && map[nx][ny] == '.') {
					map[nx][ny] = '*';
					water.push({ nx, ny });
				}
			}
		}


		int dochiSz = dochi.size();

		for (int i = 0; i < dochiSz; i++) {

			int dochiX = dochi.front().first;
			int dochiY = dochi.front().second;
			dochi.pop();

			for (int j = 0; j < 4; j++) {
				int nx = dochiX + dx[j];
				int ny = dochiY + dy[j];

				if (isRange(nx, ny) && map[nx][ny] == 'D') {
					flag = true;
					return;
				}
				
				if (isRange(nx, ny) && map[nx][ny] == '.') {
					map[nx][ny] = 'S';
					dochi.push({ nx, ny });
				}
			}
		}

	}
}

int main() {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			map[i][j] = str[j];
			if (str[j] == 'S') {
				dochi.push({ i,j });
			}
			else if (str[j] == '*') {
				water.push({ i, j });
			}
		}
	}

	bfs();

	if (flag) cout << cnt << "\n";
	else cout << "KAKTUS" << "\n";

	return 0;
}