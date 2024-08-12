#include <iostream>
using namespace std;

int main() {
	int T = 0, T_NUM = 0;
	int arr[20] = {};

	cin >> T;

	while (T--) {
		ios_base::sync_with_stdio(false);
		cin.tie(0);

		int result = 0;

		cin >> T_NUM;
		for (int i = 0; i < 20; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i < 20; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[i] < arr[j]) result++;
			}
		}

		cout << T_NUM << " " << result << "\n";
	}

	return 0;
}