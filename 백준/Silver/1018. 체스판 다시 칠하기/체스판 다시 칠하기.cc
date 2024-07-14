#include <iostream>
using namespace std;


int arr[50][50] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, M = 0;
	char input = ' ';

	cin >> N >> M;

	int minCnt = N*M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			if (input == 'W') arr[i][j] = 1;
			else arr[i][j] = 2;
		}
	}

	// 시작점 범위
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int cnt = 0;
			int cnt2 = 0;
			// 탐색 범위
			for (int a = i; a < i + 8; a++) {
				for (int b = j; b < j + 8; b++) {

					int start = arr[i][j];

					// [짝수][짝수]는 모두 start, [홀수][홀수]는 모두 start. 나머지는 start이 아니어야함. 
					// 그렇지 않으면 카운트
						if ((a+b)%2 == 0) {
							if (arr[a][b] != start) cnt++;
						}
						else {
							if (arr[a][b] == start) cnt++;
						}

					// 반대의 경우 (시작점을 바꿔야하는 경우)
						if ((a + b) % 2 == 0) {
							if (arr[a][b] == start) cnt2++;
						}
						else {
							if (arr[a][b] != start) cnt2++;
						}
				}
			}

			minCnt = min(minCnt, min(cnt, cnt2));
		}
	}

	cout << minCnt << "\n";
	

	return 0;
}