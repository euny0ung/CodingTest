#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int>q;
	string st;

	int n = 0;
	int input = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> st;

		if (st == "push_front") {
			cin >> input;
			q.insert(q.begin(), input);
		}
		if (st == "push_back") {
			cin >> input;
			q.push_back(input);
		}
		if (st == "pop_front") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.erase(q.begin());
			}
			
		}
		if (st == "pop_back") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.back() << endl;
				q.erase(q.end()-1);
			}
			
		}
		if (st == "size") {
			cout << q.size() << endl;
		}
		if (st == "empty") {
			cout << q.empty() << endl;
		}
		if (st == "front") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
			}
		}
		if (st == "back") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.back() << endl;
			}
		}
	}

	return 0;
}