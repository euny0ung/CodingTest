#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int>up[501];
vector<int>down[501];
bool visited[501];

int depth;

void dfs(vector<int>v[], int start) {

	visited[start] = true;

	int result = 0;

	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (!visited[next]) {
			// 깊이 +1
			depth++;
			dfs(v, next);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, M = 0, a = 0, b = 0, result=0;

	cin >> N >> M;

	// 입력
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		down[b].push_back(a);
		up[a].push_back(b);
	}

	// 모든 노드에서 dfs 돌리기
	for (int i = 1; i <=N; i++) {
		depth = 0;
		memset(visited, 0, sizeof(visited));
		dfs(down, i);
		memset(visited, 0, sizeof(visited));
		dfs(up, i);

		// 자기 자신은 제외
		if (depth == N-1) result++;
	}

	cout << result << endl;

	return 0;
}