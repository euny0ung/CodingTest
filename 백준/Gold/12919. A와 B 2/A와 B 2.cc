#include <iostream>
#include <algorithm>
using namespace std;

int flag = 0;
string temp;

void start(string s, string t) {
	if (s == t) {
		flag = 1;
		return;
	}

	if (s.length() >= t.length()) return;

			if (t[0] == 'B') {
				temp = t;
				temp.erase(temp.begin());
				reverse(temp.begin(), temp.end());
				start(s, temp);
			}
			if (t[t.length() - 1] == 'A') {
				temp = t;
				temp.erase(temp.end() - 1);
				start(s, temp);
			}
			
}

int main() {

	string S, T;

	cin >> S >> T;

	// 아 진짜 바보짓했다 T 길이로 루프돌면 T 길이가 줄어들면서 동작 안하지....

	start(S, T);

	cout << flag << "\n";

	return 0;
}