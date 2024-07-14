#include <iostream>
#include <vector>
using namespace std;

bool visited[10001] = { false, };
vector<pair<int, int>>node[10001];

int maxValue=0, maxNode = 0;

void DFS(int x, int value) {
	int size = node[x].size();
	visited[x] = true;

	if (maxValue < value) {
		maxValue = value;
		maxNode = x;
	
	}

	for (int i = 0; i < size; i++) {
		if (!visited[node[x][i].first]) {
			DFS(node[x][i].first, value+node[x][i].second);
			
		}
	}
}

int main() {

	int N = 0;
	int S = 0, E = 0, W = 0;

	cin >> N;

	for (int i = 0; i < N-1; i++) {
		cin >> S >> E >> W;
		node[S].push_back(make_pair(E, W));
		node[E].push_back(make_pair(S, W));
	}

	DFS(1, 0);

	maxValue=0;
	

	for (int i = 0; i <= N; i++) {
		visited[i] = false;
	}

	DFS(maxNode, 0);

	cout << maxValue << "\n";

	return 0;
}