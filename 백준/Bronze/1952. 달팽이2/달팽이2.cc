#include <iostream>
using namespace std;

// 범위를 넘어가거나 이미 방문한 곳이면 cnt++
// 오른쪽, 아래, 왼쪽, 위 순서로 방문

int main() {

	int M = 0, N = 0;
	int dr[4] = { 0,1,0,-1 }; // 좌우
	int dc[4] = { 1,0,-1,0 }; // 상하
	int map[100][100] = { 0, };

	int cnt = 1, d=0, ans=0;
	int r = 0, c = 0;

	cin >> M >> N;

	map[0][0] = 1;

	// map 체크를 다 안하고 cnt==M*N으로 체크하는게 아이디어

	while (1) {
		if (cnt == M * N) break;

		// 다음 위치
		int nx = r + dr[d];
		int ny = c + dc[d];

		// 범위를 넘어가거나 방문한 곳이면
		if (map[nx][ny] == 1 || nx > M-1 || ny > N-1 || nx < 0 || ny<0) {
			// 방향 바꿈
			if (d == 3) d = 0;
			else d++;
			ans++;
		}
		else {
			// 방문처리
			map[nx][ny]=1;
			// 현재 위치 변경
			r = nx;
			c = ny;
			cnt++;
		}
	}

	cout << ans << "\n";

	return 0;
}