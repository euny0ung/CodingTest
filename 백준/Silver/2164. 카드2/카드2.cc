#include <iostream>
#include <queue>
using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int>q;

	int n = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front() << endl;

	// 큐 관련 함수의 기능을 알아야함

	return 0;
}