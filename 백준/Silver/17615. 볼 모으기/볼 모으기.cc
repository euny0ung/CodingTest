#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N = 0, cnt=0;
int ans = INF;
bool exist=false;

void reset() {
	ans = min(ans, cnt);
	exist = false;
	cnt = 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	vector<char>v(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	// 빨간색을 오른쪽으로 모으기
	for (int i = N-1; i >=0; i--) {
		if (v[i] == 'B') exist = true;
		if (exist && v[i] == 'R') cnt++;
	}

	reset();

	// 빨간색을 왼쪽으로 모으기
	for (int i = 0; i < N; i++) {
		if (v[i] == 'B') exist = true;
		if (exist && v[i] == 'R') cnt++;
	}

	reset();

	// 파란색을 오른쪽으로 모으기
	for (int i = N - 1; i >= 0; i--) {
		if (v[i] == 'R') exist = true;
		if (exist && v[i] == 'B') cnt++;
	}

	reset();

	// 파란색을 왼쪽으로 모으기
	for (int i = 0; i <N; i++) {
		if (v[i] == 'R') exist = true;
		if (exist && v[i] == 'B') cnt++;
	}

	reset();

	cout << ans << "\n";

	return 0;
}