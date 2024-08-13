#include <iostream>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str, num_str;
	int num = 0, idx=0;

	cin >> str;

	while (num++ < 30000) {

		num_str = to_string(num);
		for (int i = 0; i < num_str.length(); i++) {
			if (str[idx] == num_str[i]) {
				idx++;
			}
			if (idx == str.length()) {
				cout << num << "\n";
				return 0;
			}
		}
	}

	

	return 0;
}