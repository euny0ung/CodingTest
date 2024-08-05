#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

vector<pair<int, int>>v[50001];
int dist[50001];

void dijkstra(int start) {
	priority_queue<pair<int, int>>pq;

	pq.push({ 0, start });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;

		pq.pop();

		if (dist[node] < cost) continue;

		for (int i = 0; i < v[node].size(); i++) {
			int next_cost = v[node][i].first + cost;
			int next_node = v[node][i].second;

			if (dist[next_node] > next_cost) {
				dist[next_node] = next_cost;
				pq.push({ -next_cost, next_node });
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, M = 0;
	int start = 0, end = 0, weight = 0;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> start >> end >> weight;
		v[start].push_back({ weight, end });
		v[end].push_back({ weight, start });
	}

	fill(dist, dist + 50001, INF);

	dijkstra(1);

	cout << dist[N] << "\n";


	return 0;
}