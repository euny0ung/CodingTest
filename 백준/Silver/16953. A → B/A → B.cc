#include <iostream>
#include <string>
using namespace std;

int main() {

	int a = 0;
	int cnt = 0;
	string b;

	cin >> a >> b;

	int b_int = stoi(b);

	while (1) {
		if (b_int == a) break;
		if (b_int < a) {
			cnt = -1;
			break;
		}
		else {
			if (b[b.size() - 1] == '1') {
				b_int = stoi(b);
				b_int /= 10;
				b.erase(b.size() - 1);
				cnt++;
			}
			else {
				if (b_int % 2 != 0) {
					cnt = -1;
					break;
				}
				b_int /= 2;
				b = to_string(b_int);
				cnt++;
			}
		}

	}

	if (cnt == -1) {
		cout << cnt << "\n";
	}
	else {
		cout << cnt+1 << "\n";

	}

	return 0;
}