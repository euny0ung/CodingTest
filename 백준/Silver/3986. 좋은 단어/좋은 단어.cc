#include <iostream>
#include <stack>
#include <string>

using namespace std;

int Check(string st, stack<char>s) {
	for (int i = 0; i < st.size(); i++) {
		if (s.empty()) s.push(st[i]);
		else {
			if (s.top() == st[i]) s.pop();
			else s.push(st[i]);
		}
	}

	return s.empty();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	int n = 0;
	string st;
	stack<char>s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> st;
		if (Check(st, s)) cnt++;
	}

	cout << cnt << endl;
	

	return 0;
} 