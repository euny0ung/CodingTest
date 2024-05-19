#include <iostream>
#include <stack>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int input = 0;
	int result = 0;
	stack<int>st;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == 0) st.pop();
		else st.push(input);
	}

	while(!st.empty()) {
		result += st.top();
		st.pop();
	}

	cout << result << endl;

	

	return 0;
}