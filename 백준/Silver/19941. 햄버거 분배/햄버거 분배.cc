#include <iostream>
#include <math.h>
using namespace std;

int N = 0, K = 0;
int arr[20001] = {};
string str = "";

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt = 0;
	
	cin >> N >> K;
	cin >> str;

	int sz = str.length();

	for (int i = 0; i < sz; i++) {
		if (str[i] == 'H') arr[i] = 1;
		else arr[i] = 2;
	}

	for (int i = 0; i < sz; i++) {
		// 사람이면
		if (arr[i] == 2) {
			// 왼쪽부터 탐색
			for (int j = i-K; j <= i+K; j++) {
				if (arr[j] == 1 && (j>=0 && j<sz)) {
					arr[j] = 0;
					cnt++;
					break;
				}
			}
		}
	}

	cout << cnt << "\n";
}