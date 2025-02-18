#include <iostream>
#include <queue>
using namespace std;

int N, input;
priority_queue<long long, vector<long long>, greater<long long>>q;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N * N; i++) {
		cin >> input;
		if (i < N) q.push(input);
		else {
			if (q.top() < input) {
				q.pop();
				q.push(input);
			}
		}
	}

	cout << q.top() << "\n";

	return 0;
}