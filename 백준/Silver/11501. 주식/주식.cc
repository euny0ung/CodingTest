#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T = 0, day=0;

	cin >> T;

	while (T--) {
		cin >> day;
		int* arr = new int[day];

		for (int i = 0; i < day; i++) {
			cin >> arr[i];
		}
		
		int maxPrice=0;
		long long ans = 0;
		
		for (int i = day - 1; i >= 0; i--) {
			if (arr[i] > maxPrice) maxPrice = arr[i];
			else ans += maxPrice - arr[i];
		}
		cout << ans << "\n";
	}

	return 0;
}