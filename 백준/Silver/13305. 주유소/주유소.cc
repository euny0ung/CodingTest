#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	long long price = 0;

	cin >> N;

	vector<long>road(N+1, 0);
	vector<long>node(N, 0);

	for (int i = 1; i < N; i++) {
		cin >> road[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> node[i];
	}

	long now = node[0];
	price += road[1] * now;

	// 두번째 노드부터 검사 시작
	for (int i = 1; i < N; i++) {
		if (node[i] < now) {
			now = node[i];

		}
		price += road[i + 1] * now;
	}


	cout << price << "\n";

	return 0;
}