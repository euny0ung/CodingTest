#include <iostream>
using namespace std;

int main() {

	int arr[301][301] = { 0, };

	int n = 0, m = 0;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int k = 0;
	
	cin >> k;

	int i = 0, j = 0, x = 0, y = 0;
	

	for (int z = 0; z < k; z++) {
		int result = 0;
		cin >> i >> j >> x >> y;
		for (int a = i - 1; a < x; a++) {
			for (int b = j - 1; b < y; b++) {
				result += arr[a][b];
			}
		}
		cout << result<<endl;
	}

	return 0;
}