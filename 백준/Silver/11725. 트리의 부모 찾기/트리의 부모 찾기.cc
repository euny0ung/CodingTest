#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

vector<int>v[MAX];
bool visited[MAX];
int answer[MAX];
queue<int>q;

void bfs() {
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int parent = q.front();
		q.pop();

		for (int i = 0; i < v[parent].size(); i++) {
			int child = v[parent][i];
			if (!visited[child]) {
				answer[child] = parent;
				visited[child] = true;
				q.push(child);
			}
		}
	}
}

int main() {

	cin.tie(NULL);

	int N = 0;
	int a = 0, b = 0;

	cin >> N;

	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs();

	for (int i = 2; i < MAX; i++) {
		if (visited[i]) {
			cout << answer[i] << "\n";
		}
	}

	return 0;
}