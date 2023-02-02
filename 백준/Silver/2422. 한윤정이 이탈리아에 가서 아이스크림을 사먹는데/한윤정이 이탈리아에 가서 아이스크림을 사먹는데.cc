#include <iostream>
using namespace std;

int main() {

	int n = 0, m = 0;
	int num1 = 0, num2;
	int cnt = 0;
	int arr[201][201] = { 0, };

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> num1 >> num2;
		arr[num1][num2] = arr[num2][num1] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (arr[i][j]) continue;
			for (int k = j+1; k <= n; k++) {
				if (arr[j][k] == 1 || arr[k][i] == 1) continue;
				
				cnt++;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}