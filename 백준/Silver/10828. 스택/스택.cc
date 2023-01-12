#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int num = 0;
	string input;
	stack<int>st;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;

		if (input == "push") {
			cin >> num;
			st.push(num);
		}
		else if (input == "top") {
			if (st.empty()) cout << -1 << endl;
			else cout << st.top() << "\n";
		}
		else if (input == "size") {
			cout << st.size() << "\n";
		}
		else if (input == "empty") {
			cout << st.empty() << "\n"; //반환값이 뭔가?
		}
		else if (input == "pop") {
			if(st.empty()) cout << -1 << endl;
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
	}
	

	 
	
	return 0;
}