#include <iostream>
#include <algorithm>
#include <vector>
#define INF 12345678987654321
using namespace std;

// start, end의 합의 절대값이 기존 결과보다 작으면 start, end를 저장
int main() {

	int N = 0;
	long long result = INF;
	
	cin >> N;

	int start = 0, end = N-1;
	int ans1 = 0, ans2 = 0;

	vector<long>v(N,0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

		while (start < end) {
				long calc = v[start] + v[end];
				if (abs(calc) < result) { 
					ans1 = v[start], ans2 = v[end];
					result = abs(calc);
					if(calc==0) break; // 합이 0인 경우 더 이상 계산할 필요가 없다
				}
				if (calc < 0) {
					start++;
				}
				else if (calc > 0) {
					end--;
				}
		}
	
	cout << ans1 <<" " << ans2 << "\n";

	return 0;
}