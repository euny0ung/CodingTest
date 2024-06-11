#include <iostream>
#include <vector>

using namespace std;

bool map[12][12] = { false, };
bool final[12][12] = { false, };
int nx[] = { -1, 0, 1, 0 };
int ny[] = { 0, 1, 0, -1 };

// 50년 후 섬의 모습
void changeMap(int R, int C) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j]) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nextX = i + nx[k];
					int nextY = j + ny[k];
					if (!map[nextX][nextY]) cnt++;
				}
				if (cnt < 3) final[i][j] = true;
			}
		}
	}
}

int main() {

	int R = 0, C = 0;
	char input = ' ';

	cin >> R >> C;

	// X면 해당 위치는 true
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> input;
			if (input == 'X') map[i][j] = true;
		}
	}

	changeMap(R, C);

	// 50년 후 섬의 모습에서 섬의 크기를 다시 구하여 출력
	int startX = R;
	int startY = C;
	int endX = 0;
	int endY = 0;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (final[i][j]) {
				startX = min(startX, i);
				startY = min(startY, j);
				endX = max(endX, i);
				endY = max(endY, j);
			}
		}
	}

	for (int i = startX; i <= endX; i++) {
		for (int j = startY; j <= endY; j++) {
			if (final[i][j]) cout << "X";
			else cout << ".";
		}
		cout << "\n";
	}

	return 0;
}