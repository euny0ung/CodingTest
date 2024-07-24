#include <iostream>
#include <set>
#include <math.h>
#include <algorithm>
#define INF 2000000000
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	long M = 0, result=0, ans=INF;
	long arr[100000] = { 0, };

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int start = 0, end = 0;

	sort(arr, arr + N);

	// start와 end가 같은 값일 수 있어서 start < N인가? start<end라고 생각하고 풀었는데
	while (start < N && end < N) {

		result = arr[end] - arr[start];
		
		if (result < M) {
			end++;
		}
		else {
			ans=min(ans, result);
			start++;
		}

		
	}

	cout << ans << "\n";


	return 0;
}