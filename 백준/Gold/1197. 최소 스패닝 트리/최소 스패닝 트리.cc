#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>>v;
int parent[10001];

int find(int num) {
	if (parent[num] == num) return num;
	else return parent[num] = find(parent[num]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	parent[y] = x;
}

bool sameparent(int x, int y) {
	x = find(x);
	y = find(y);
	return x == y;
}

int main() {

	int V = 0, E = 0;
	int from = 0, to = 0, cost = 0;

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		cin >> from >> to >> cost;
		v.push_back({ cost, {from, to} });
	}

	int ans = 0;

	sort(v.begin(), v.end());
	for (int i = 1; i <= V; i++) parent[i] = i;
	for (int i = 0; i < v.size(); i++) {
		if (!sameparent(v[i].second.first, v[i].second.second)) {
			uni(v[i].second.first, v[i].second.second);
			ans += v[i].first;
		}
	}

	cout << ans << "\n";

	return 0;
}