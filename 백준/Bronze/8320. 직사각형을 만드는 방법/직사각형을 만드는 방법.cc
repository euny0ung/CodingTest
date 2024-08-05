#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, cnt=0;

	cin >> N;

	for (int i = 1; i*i <= N; i++) {
		for (int j = i; i * j <= N; j++) {
			cnt++;
		}
	}


	cout << cnt << "\n";

	return 0;
}