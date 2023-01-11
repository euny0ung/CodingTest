#include <iostream>
using namespace std;

int result = 1, cnt=0; // 아무곳도 가지 못하면 1이므로 1로 초기화
int r = 0, c = 0;

char alpha[26] = { };
char arr[21][21];

int dx[4] = { 1,-1,0,0 }; // 하 상 우 좌
int dy[4] = { 0,0,1,-1 };

void DFS(int x, int y, int cnt) {

	int nx = 0, ny = 0;

	result = max(result, cnt); // 최대값 갱신

	for (int i = 0; i < 4; i++) {
		nx = dx[i] + x;
		ny = dy[i] + y;

		if (0 <= nx && nx < r && 0 <= ny && ny < c) { // 범위 안일때
			if (!alpha[arr[nx][ny] - 'A']) { // 방문하지 않은 곳
				alpha[arr[nx][ny] - 'A'] = true; 
				DFS(nx, ny, cnt + 1);
				alpha[arr[nx][ny] - 'A'] = false; // 백트래킹 해야하므로 false 처리
			}
		}

	}

}

int main() {



	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	alpha[arr[0][0] - 'A'] = true; // 첫 시작점 방문처리

	DFS(0, 0, 1);

	cout << result << endl;

	return 0;
}

// dfs 백트래킹