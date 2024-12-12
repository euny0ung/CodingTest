#include <iostream>
#include <queue>
using namespace std;

bool visited[100001] = { false, };
int dist[100001] = { 0, };
queue<int>q;

int bfs(int start, int end) {
	q.push(start);

	while (!q.empty()) {

		int current = q.front();
		q.pop();

		if (current == end) return dist[current];

		int nextPosition[3] = { current - 1, current + 1, current * 2 };

		for (auto next : nextPosition) {
			if (next >= 0 && next <= 100000 && !visited[next]) {
				q.push(next);
				visited[next] = true;
				dist[next] = dist[current] + 1;
			}
		}
	}

	return -1;
}

int main() {

	int N = 0, K = 0;

	cin >> N >> K;

	visited[N] = true;

	cout<<bfs(N, K)<<"\n";

	return 0;
}