#include <iostream>
#include <vector>
using namespace std;

int N = 0, K = 0, input = 0, ans=0;
int arr[9] = { 0, };
bool visited[9] = { false, };
vector<int>v;

void recursive(int idx) {
	if (idx == N) {
		int strength = 500;

		// 계산
		for (int i = 0; i < N; i++) {
			strength +=arr[i]-K;
			if (strength < 500) return;
		}
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[idx] = v[i];
			recursive(idx + 1);
			visited[i] = false;
		}
	}
}

int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	recursive(0);

	cout << ans << "\n";

	return 0;
}