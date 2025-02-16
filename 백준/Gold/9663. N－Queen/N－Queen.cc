#include <iostream>
using namespace std;

int N, ans;
int map[16];

void queen(int cnt) {

	if (cnt == N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		map[cnt] = i;
		int check = true;
		for (int j = 0; j < cnt; j++) {
			if (map[cnt] == map[j] || cnt == j || (abs(cnt - j) == abs(map[cnt] - map[j]))) {
				check = false;
				break;
			}
		}
		if (check) queen(cnt + 1);
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		map[0] = i;
		queen(1);
	}

	cout << ans << "\n";

	return 0;
}