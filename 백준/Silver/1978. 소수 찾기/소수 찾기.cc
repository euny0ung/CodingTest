#include <iostream>
using namespace std;

int main() {
	int n = 0;
	int input = 0;
	int cnt = 0;
	int result = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == 1) continue;

		for (int j = 2; j * j <= input; j++) {
			if (input % j == 0) cnt++;
		}
		if (cnt == 0) result++;
		cnt = 0;
	}

	cout << result << endl;
}
// cnt를 0으로 초기화해주지 않아서 계속 틀렸다고 떴음..