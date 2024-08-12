#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int H = 0, W = 0, N = 0, M = 0;

	cin >> H >> W >> N >> M;

	int res1 = 0, res2 = 0;
	int ans1 = 0, ans2 = 0;

	while (res1 < H) {
		ans1++;
		res1 = ans1 * (N + 1);
	}

	while (res2 < W) {
		ans2++;
		res2 = ans2 * (M + 1);
	}

	cout << ans1 * ans2 << "\n";

	return 0;
}