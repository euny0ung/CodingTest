#include <iostream>
using namespace std;

bool isVowel(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

bool isContain(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (isVowel(s[i])) return true;
	}
	return false;
}

// 여기서 out of bound가 떴는데 문자가 세글자 미만일 경우를 생각하지 못했다...
bool isContinuous(string s) {

	if (s.length() < 3) return false;

	for (int i = 0; i < s.length()-2; i++) {
		// 모음이 연속 3개
		if (isVowel(s[i]) && isVowel(s[i + 1]) && isVowel(s[i + 2])) return true;

		// 자음이 연속 3개
		if (!isVowel(s[i]) && !isVowel(s[i + 1]) && !isVowel(s[i + 2])) return true;
	}

	return false;
}

bool isSame(string s) {
	for (int i = 0; i < s.length()-1; i++) {
		if (s[i] == s[i + 1] && (s[i] != 'e' && s[i] != 'o')) return true;
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;

	while (cin >> str) {
		if (str == "end") break;

		if (isContain(str) && !isContinuous(str) && !isSame(str)) {
			cout << "<" << str << ">" << " is acceptable." << "\n";
		}
		else cout << "<" << str << ">" << " is not acceptable." <<"\n";
	}

	return 0;
}