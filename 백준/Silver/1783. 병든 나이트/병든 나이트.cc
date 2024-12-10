#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, M = 0, result=0;

	cin >> N >> M;

	if (N == 1) result = 1;
	else if (N == 2) {
		if (M < 7) result = (M + 1) / 2;
		else result = 4;
	}
	else {
		if (M <= 6) result = min(4, M);
		else result = M - 2;
	}

	cout << result << "\n";

	return 0;
}