#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, V=0, node=0;
	int ans = 0;
	

	cin >> N;
	vector<vector<pair<int, int>>>graph(N+1);
	vector<bool>visited(N + 1);
	stack<pair<int, int>>st;

	cin.ignore();

	for (int i = 0; i < N; i++) {
		string line = "";
		getline(cin, line);
		istringstream iss(line);

		int node = 0, connected_node=0, connected_len=0;
		iss >> node;

		while (iss >> connected_node && connected_node != -1) {
			iss >> connected_len;
			graph[node].push_back({ connected_node, connected_len });
		}
	}

	// 시작점 찾기
	st.push({ 1, 0 });
	visited[1] = true;
	int startNode = 0, len=0;
	while (!st.empty()) {
		int currentNode = st.top().first;
		int currentLen = st.top().second;
		st.pop();

		// 리프노드인 경우 (아.. 여기서 실수함. 양방향이라 size가 0일 경우는 없음..)
		/*if (graph[currentNode].size() == 1) {
			if(currentLen > len) startNode = currentNode;
		}*/
		if (currentLen > len) {
			startNode = currentNode;
			// 생각 못한 부분. 여기 때문에 틀렸음
			len = currentLen;
		}

		for (int i = 0; i < graph[currentNode].size(); i++) {
			if (!visited[graph[currentNode][i].first]) {
				st.push({graph[currentNode][i].first, currentLen+graph[currentNode][i].second});
				visited[graph[currentNode][i].first] = true;
			}
	
		}
	}
	
	// 거리 구하기
	while (!st.empty()) {
		st.pop();
	}

	fill(visited.begin(), visited.end(), false);

	st.push({ startNode, 0 });
	visited[startNode] = true;

	while (!st.empty()) {
		int currentNode = st.top().first;
		int currentLen = st.top().second;
		st.pop();

		// 리프노드인 경우 (여기서 또 실수... 더 이상 못가는 경우를 구해야지 리프노드가 아니고)
		ans = max(ans, currentLen);

		for (int i = 0; i < graph[currentNode].size(); i++) {
			if (!visited[graph[currentNode][i].first]) {
				st.push({ graph[currentNode][i].first, currentLen + graph[currentNode][i].second });
				visited[graph[currentNode][i].first] = true;
			}
			
		}
	}

	cout << ans << "\n";

	return 0;
}