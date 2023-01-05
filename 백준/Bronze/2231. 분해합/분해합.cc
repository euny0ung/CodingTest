#include <iostream>
using namespace std;

int main() {

	int n = 0;
	int result = 0;
	int temp = 0;
	int min = 1000000;

	cin >> n;

	for (int i = n - 54; i < n; i++) {
		
		temp = i;
		result +=temp;
		while (temp != 0) {
			result += (temp % 10);
			temp /= 10;
		}
		if (result == n && i<min) { // 다 더한 수가 입력값과 같고 생성자가 min보다 작은 경우(최소를 구하기 위해)
			min = i;
		}
		result = 0;
	}

	if (min == 1000000) cout << 0 << endl;
	else cout << min << endl;

	return 0;
}