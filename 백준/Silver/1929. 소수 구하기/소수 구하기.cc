#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n1=0, n2=0;
	int cnt = 0;

	cin >> n1>>n2;


	for (int i = n1; i <= n2; i++) {

		if (i == 1) continue;

		for (int j = 1; j*j <= i; j++) {
				if (i % j == 0) cnt++;
				if (cnt > 1)break;
			}
		if (cnt == 1) cout << i << "\n";
		cnt = 0;
	}

	return 0;
}

// 1. for문을 사용하여 나누어 떨어지는 경우 count++. count가 2인 경우에만 출력
// 이렇게 하면 시간초과 뜸..
// 2. 루트 이용
// 3. 1은 소수가 아님... 이 부분을 놓쳤음