#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int num = 0;
	string input;
	queue<int>q;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;

		if (input == "push") {
			cin >> num;
			q.push(num);
		}
		else if (input == "front") {
			if (q.empty()) cout << -1 << endl;
			else cout << q.front() << "\n";
		}
		else if (input == "back") {
			if (q.empty()) cout << -1 << endl;
			else cout << q.back() << "\n";
		}
		else if (input == "size") {
			cout << q.size() << "\n";
		}
		else if (input == "empty") {
			cout << q.empty() << "\n"; //반환값이 뭔가?
		}
		else if (input == "pop") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
	}




	return 0;
}