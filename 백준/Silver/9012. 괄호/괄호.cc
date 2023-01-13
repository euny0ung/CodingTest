#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool CheckVPS(string str) {

	stack<char>s;
	int len = (int)str.length();

	for (int i = 0; i < len; i++) {
		char ch = str[i];

		if (ch == '(') {
			s.push(str[i]);
		}
		else {
			if (!s.empty()) {
				s.pop();
			}
			else {
				return false; //도중에 비어있으면 false?
			}
		}
	}
	return s.empty(); //다 끝나고 비어있으면 true
}

int main(){

	int T;
	string str;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> str;
		if (CheckVPS(str)) {
			cout << "YES" << endl;
			}
		else {
			cout << "NO" << endl;
			}
		
	}

	
	

	return 0;
}