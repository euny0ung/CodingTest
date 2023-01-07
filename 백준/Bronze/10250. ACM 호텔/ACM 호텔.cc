#include <iostream>
using namespace std;

int main() {

	int t = 0;
	int h = 0, w = 0, n = 0;
	int cnt = 1;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> h >> w >> n;
		while (n > h) {
			n -= h;
			cnt++;
		}
		cout << n*100+cnt << endl;
		cnt = 1;
	}

	return 0;
}