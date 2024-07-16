#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int>pq;

	int N = 0, input=0;

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> input;
		if (input == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else { 
				cout << pq.top() << "\n"; 
				pq.pop();
			}
		}
		else {
			pq.push(input);
		}
	}
}