#include <iostream>
#include <string>
using namespace std;


string st = "", temp = "";
string result = "";

string solve(string st) {

	int len = 0;

	for (char ch : st) {
		if (ch == 'X') temp += "X";
		else {
			len = temp.length();

			if (len % 2 != 0) {
				return "-1";
			}
			result += string(len / 4 * 4, 'A') + string(len % 4, 'B');
			result += '.';
			temp = "";
		}
	}

	if (!temp.empty()) {
		len = temp.length();

		if (len % 2 != 0) {
			return "-1";
		}
		result += string(len / 4 * 4, 'A') + string(len % 4, 'B');
	}

	return result;
}

int main() {

	cin >> st;

	cout<< solve(st)<<"\n";

	return 0;
}