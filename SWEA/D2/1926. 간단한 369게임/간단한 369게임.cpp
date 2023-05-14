#include <iostream>
#include <string>
using namespace std;

int main() {

	string n;

	cin >> n;
	

	for (int i = 1; i <= stoi(n); i++) {
		string target = to_string(i);
		int cnt = 0;
		if (target.find("3") != string::npos || target.find("6") != string::npos || target.find("9") != string::npos) {
			for (int j = 0; j < target.length(); j++) {
				if (target[j] == '3' || target[j] == '6' || target[j] == '9') {
					cnt++;
				}
			}
			for (int k = 0; k < cnt; k++) {
				cout << "-";
			}
			cout << " ";
		}
		else {
			cout << i << ' ';
		}
	}

	return 0;
}