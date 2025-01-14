#include <iostream>
#include <stack>
using namespace std;

string str;
int num;

int main() {

	while (1) {
		num++;
		int ans = 0;
		stack<char>st;
		cin >> str;
		if (str.find('-') != string::npos) break;
		for (int i = 0; i < str.length(); i++) {
			// 스택이 비어있을 경우
			if (st.empty()) st.push(str[i]);
			// 스택이 안 비어있고 입력값이 }, top이 { 인 경우
			else {
				if (str[i] == '}' && st.top() == '{') st.pop();
				else st.push(str[i]);
			}
		}

		while (!st.empty()) {
			int first = st.top();
			st.pop();
			int second = st.top();
			st.pop();

			if (first == second) ans++;
			else ans += 2;
		}

		cout <<num <<". "  << ans << "\n";
	}

}