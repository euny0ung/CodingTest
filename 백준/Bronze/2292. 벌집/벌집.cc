#include <iostream>
using namespace std;

int main() {

	int n = 0;

	cin >> n;

	int start = 2, end = 7;
	int multi = 6;
	int cnt = 1;
	
	while (1) {
		if (n == 1) {
			cout << cnt << endl;
			break;
		}
		else if (n >= start && n <= end) {
			cnt++;
			cout << cnt << endl;
			break;
		}
		else {
			cnt++;
			multi = 6 * cnt;
			start = end + 1;
			end = end + multi;
		}
	}
	

	return 0;
}