#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, M = 0;
	int maxLen = 0;

	cin >> N;
	cin >> M;

	vector<double>v(M+2, 0);

	for (int i = 1; i <= M; i++) {
		cin >> v[i];
	}

	v[M+1] = N;

	// 시작점, 끝점 범위
	maxLen = max(maxLen, (int)(v[M + 1] - v[M]));
	maxLen = max(maxLen, (int)(v[1] - v[0]));

	// 사이 간격
	for (int i = 0; i < M+1; i++) {
		maxLen = max(maxLen, (int)ceil((v[i + 1] - v[i])/2));
	}
	
	cout << maxLen << "\n";

	return 0;
}