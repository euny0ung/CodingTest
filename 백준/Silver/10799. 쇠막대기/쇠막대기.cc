#include <iostream>
#include <stack>
using namespace std;

string str;
char pre;
stack<char>s;

int main() {

	int ans = 0;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		// 레이저일때
		if (str[i]==')' && str[i-1]=='(') {
			s.pop();
			ans += s.size();
		}
		else if(str[i]=='(') {
			s.push(str[i]);
		}
		else {
			ans++;
			s.pop();
		}
	}

	cout << ans << "\n";

	return 0;
}