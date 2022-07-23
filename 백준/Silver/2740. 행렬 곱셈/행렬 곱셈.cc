#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int** f_arr = new int*[n];

	for (int i = 0; i < n; i++) {
		f_arr[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> f_arr[i][j];
		}
	}


	int k, z;
	cin >> k >> z;

	int** s_arr = new int* [k];


	for (int i = 0; i < k; i++) {
		s_arr[i] = new int [z];
		for (int j = 0; j < z; j++) {
			cin >> s_arr[i][j];
		}
	}

	int **rst_arr = new int* [n];

	for (int i = 0; i < n; i++) {
		rst_arr[i] = new int[z];
		for (int j = 0; j < z; j++) {
			rst_arr[i][j] = 0;
			 for (int k = 0; k < m; k++){
				rst_arr[i][j] += f_arr[i][k] * s_arr[k][j];
			/*	k와 j 순서를 바꾸고 rst_arr를 계속 0으로 초기화하는 코드를 넣어 해결*/
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < z; j++) {
			cout << rst_arr[i][j]<< " ";
		}
	}

	return 0;
}