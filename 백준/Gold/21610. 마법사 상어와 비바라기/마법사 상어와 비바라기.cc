#include <iostream>
#include <vector>
using namespace std;

int N = 0, moveNum = 0;

bool isRange(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int dir = 0, distance = 0;
	int map[50][50] = { 0, };
	bool visited[50][50] = { false, };

	int dx[8] = { 0,-1,-1,-1,0,1,1,1};
	int dy[8] = {-1,-1,0,1,1,1,0,-1};                                                                                                                      

	vector<pair<int, int>>cloud;

	cin >> N >> moveNum;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin>>map[i][j];
		}
	}

	// 초기 구름 위치 저장
	for (int i = 0; i <= 1; i++) {
		for (int j = 1; j <= 2; j++) {
			cloud.push_back({ N - i-1, j-1 });
		}
	}

	while (moveNum--) {
		cin >> dir >> distance;

		for (int i = 0; i < cloud.size(); i++) {
			cloud[i].first = (cloud[i].first + dx[dir-1] * distance + N *distance) % N;
			cloud[i].second = (cloud[i].second + dy[dir-1] * distance +N * distance) % N;
			map[cloud[i].first][cloud[i].second]++;
			visited[cloud[i].first][cloud[i].second] = true;
		}

		// 대각선 물복사
		for (int i = 0; i < cloud.size(); i++) {
			for (int j = 1; j <= 7; j += 2) {
				if (!isRange(cloud[i].first + dx[j], cloud[i].second + dy[j])) continue;
				if(map[cloud[i].first + dx[j]][cloud[i].second + dy[j]]>0) map[cloud[i].first][cloud[i].second]++;
			}
		}

		// 구름 생성
		cloud.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && map[i][j] >= 2) {
					cloud.push_back({ i,j });
					map[i][j] -= 2;
				}
				// 기존 구름 해제
				if (visited[i][j]) visited[i][j] = false;
			}
		}

	}

	int result = 0;

	// 결과
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result += map[i][j];
		}
	}

	cout << result << "\n";

	return 0;
}