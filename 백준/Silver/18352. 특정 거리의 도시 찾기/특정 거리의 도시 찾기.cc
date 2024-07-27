#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// bfs 버전

queue <int>q;
vector<vector<int>>v; // 그래프
vector<int>dist;

void bfs(int start) {
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < v[node].size(); i++) {
			// 다음 노드
			int nextNode = v[node][i];
			// 아직 탐색 안했다면
			if (dist[nextNode] == -1) {
				dist[nextNode] = dist[node] + 1;
				q.push(nextNode);
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 도시개수, 도로개수, 거리정보, 출발도시, 시작노드, 도착노드
	int N = 0, M = 0, K = 0, X = 0, A = 0, B = 0;
	vector<int>result;

	cin >> N >> M >> K >> X;

	dist = vector<int>(N + 1, -1);
	v = vector<vector<int>>(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		v[A].push_back(B);
	}

	bfs(X);

	// 거리가 K인 노드 저장
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) result.push_back(i);
	}
	

	if (result.empty()) {
		cout << "-1" << "\n";
	}
	else {
		sort(result.begin(), result.end());
		for (auto r : result) cout << r << "\n";
	}

	

	return 0;
}