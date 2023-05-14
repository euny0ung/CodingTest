#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n = 0;
	int t = 0;
	
	cin >> t;
	
	int arr[10][10] = { 0, };

	for (int t_num = 1; t_num <= t; t_num++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
				for (int j = 0; j <= i; j++) {
					if (i == 0 || j == 0) {
						arr[i][j] = 1;
			
					}
					else {
						arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			
					}
				}
			}


		cout <<"#" << t_num << endl;
			for (int i = 0; i < n; i++) {
				
				for (int j = 0; j <= i; j++) {
					cout << arr[i][j] <<' ';
				}
				cout << "\n";
			}
	}

	

	return 0;
}