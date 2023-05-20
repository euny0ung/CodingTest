#include <iostream>
#include <vector>
using namespace std;

int gr[51][51];
int w = 0, h = 0;

bool dfs(int x, int y) {

	if (x < 0 || x >= h || y < 0 || y >= w) return false;

	if (gr[x][y] == 1) {
		gr[x][y] = 0;
		/*cout << x << y << endl;*/
		dfs(x + 1, y); //하
		dfs(x - 1, y); //상
		dfs(x, y + 1); //우
		dfs(x, y - 1); // 좌
		dfs(x + 1, y + 1);
		dfs(x + 1, y - 1);
		dfs(x - 1, y + 1);
		dfs(x - 1, y - 1);
		// 대각선을 재려면 상우, 상좌, 하우, 하좌도 체크해야함.

		return true;
	}
	return false;
}

int main() {



	while (1) {

		w = 0, h = 0;
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> gr[i][j];
			}
		}

		int result = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (dfs(i, j)) {
					result++;
				}
			}
		}

		cout << result << endl;
	}



	return 0;
}
