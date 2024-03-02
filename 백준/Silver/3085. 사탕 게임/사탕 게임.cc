#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {

	int n = 0;
	int result = 0;

	cin >> n;

	vector<vector<char>>v(n, vector<char>(n));
	vector<vector<char>>v_clone(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	// 모든 경우의 수를 따져서 두 자리를 바꿈

	// 행 변경
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			v_clone.assign(v.begin(), v.end());
			int temp = v_clone[i][j];
			v_clone[i][j] = v_clone[i][j+1];
			v_clone[i][j + 1] = temp;

			int cnt = 0;

			// 행 검사
			for (int k = 0; k < n; k++) {
				for (int z = 0; z < n-1; z++) {
					if (v_clone[k][z] == v_clone[k][z+1]) {
						cnt++;result = max(cnt, result);
					}
					else {
						
						cnt = 0;
					}
				}
				cnt = 0;
			}

			// 열 검사
			for (int k = 0; k < n; k++) {
				for (int z = 0; z < n - 1; z++) {
					if (v_clone[z][k] == v_clone[z + 1][k]) {
						
						cnt++;
						result = max(cnt, result);
					}
					else {
						
						cnt = 0;
					}
				}
				cnt = 0;
			}
		}
		
	}

	// 열 변경
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			v_clone.assign(v.begin(), v.end());
			int temp = v_clone[i][j];
			v_clone[i][j] = v_clone[i+1][j];
			v_clone[i+1][j] = temp;


			// 행 검사
			for (int k = 0; k < n; k++) {
				for (int z = 0; z < n-1; z++) {
					if (v_clone[k][z] == v_clone[k][z+1]) {	
						cnt++;
						result = max(cnt, result);
					}
					else {	
						cnt = 0;
					}
				}
				cnt = 0;
			}

			// 열 검사
			for (int k = 0; k < n; k++) {
				for (int z = 0; z < n-1; z++) {
					if (v_clone[z][k] == v_clone[z + 1][k]) {
						cnt++;
						result = max(cnt, result);
					}
					else {	
						cnt = 0;
					}
				}
				cnt = 0;
			}
			
		}
	}

	cout << result+1 << endl;

}