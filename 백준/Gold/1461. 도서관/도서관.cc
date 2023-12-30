#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N=0, M=0, input=0, pivot=0;
	int ans = 0;

	cin >> N >> M;

	vector<int>v;

	// 0인 지점을 찾기 위해 0 삽입
	v.push_back(0);

	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	// 각 벡터끼리 정렬 - 같이 하고 나서 0인 지점을 구하는게 더 효율적.. (다른 사람 코드 참고)
	sort(v.begin(), v.end());

	for (int i = 0; i <= N; i++) {
		if (v[i] == 0) {
			pivot = i;
			break;
		}
	}

	// 가장 큰 수 + 인덱스 0 될때까지 m씩 건너 뛰면서 * 2
	// 가장 큰 수가 음수라면 +m씩 건너뛰기, 양수라면 -m씩 건너뛰기
	// => 일단 뒤에서부터 m씩 건너뛰면서 *2하고 마지막에 가장 큰 수 한번 빼주는게 더 효율적. 이걸 생각 못했네...

	// 음수 파트
	for (int i = 0; i < pivot; i+=M) {
		ans += abs(v[i])*2;
	}
	
	// 양수 파트
	for (int i = N; i > pivot; i -= M) {
		ans += v[i]*2;
	}

	int maxValue = max(abs(v[0]), v[N]);

	ans -= abs(maxValue);

	cout << ans << "\n";
	

	return 0;
}