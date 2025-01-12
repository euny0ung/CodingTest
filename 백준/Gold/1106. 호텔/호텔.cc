#include <iostream>
#include <vector>
using namespace std;

struct Promotion {
	int cost, customer;
};

int main() {

	int C = 0, N = 0;
	int a = 0, b = 0;
	int dp[1090];

	fill(dp, dp + 1090, 100001);
	vector<Promotion>v;

	cin >> C >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}

	dp[0] = 0;

	for (auto& ele : v) {
		for (int i = ele.customer; i <= 1089; i++) {
			dp[i] = min(dp[i - ele.customer] + ele.cost, dp[i]);
		}
	}

	// '적어도' C명에서의 최소값임.
	// cout << dp[C] << "\n";
	int ans = dp[C];
	for (int i = C + 1; i <= 1089; i++) {
		ans = min(ans, dp[i]);
	}

	cout << ans << "\n";

	return 0;
}