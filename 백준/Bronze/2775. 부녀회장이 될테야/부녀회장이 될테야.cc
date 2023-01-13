#include <iostream>

using namespace std;



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	int k = 0, n = 0;
	int arr[15][15] = {};

	cin >> T;

	for (int i = 0; i < 14; i++) arr[0][i] = i + 1; //0층

	for (int i = 1; i <= 14; i++) {
		for (int j = 0; j < 14; j++) {
			for (int k = 0; k <= j; k++) {
				arr[i][j] += arr[i - 1][k];
			}
		}
	}


	for (int i = 0; i < T; i++) {
		cin >> k;
		cin >> n;
		cout << arr[k][n-1] << endl;
	}
	


	

	return 0;
}