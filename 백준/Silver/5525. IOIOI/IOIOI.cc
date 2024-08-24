#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, M = 0;
	string str;

	cin >> N >> M >> str;

	int ans = 0;

	for (int i = 0; i < M; i++) {
		int k = 0;

		if (str[i] == 'I') {
			while (str[i + 1] == 'O' && str[i + 2] == 'I') {
				k++;
				if (k == N) {
					ans++;
					k--;
				}
				i += 2;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}