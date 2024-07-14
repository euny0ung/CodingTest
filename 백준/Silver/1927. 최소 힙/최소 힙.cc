#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	long input = 0;
	priority_queue<int, vector<int>, greater<int>>minHeap;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;

		if (input == 0) {
			if (minHeap.empty()) {
				cout << "0" << "\n";
			}
			else {
				cout << minHeap.top() << "\n";
				minHeap.pop();
			}
		}
		else {
			minHeap.push(input);
		}
	}

	return 0;
}