#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int firstCompare(const vector<int>& a, const vector<int>& b) {
	return a[0] < b[0];
}

int secondCompare(const vector<int>& a, const vector<int>& b) {
	return a[1] < b[1];
}

int main() {

	// N은 끊어진 줄 개수, M은 브랜드 개수
	// M만큼 6줄 패키지 가격, 낱개 가격이 주어짐
	// 적어도 N개를 사기 위해 필요한 최소 금액

	int N = 0, M = 0;
	int set = 0, each = 0;

	cin >> N >> M;

	vector<vector<int>>v(M, vector<int>(2, 0));

	for (int i = 0; i < M; i++) {
		cin >> v[i][0] >> v[i][1];
	}

	// 패키지 가격이 개별 가격보다 비쌀거라는 보장이 없다
	// 6*x > N일때까지 total에 v[i][0](가장 저렴한거) 더하기. 각 개별 가격 * N해서 비교
	// 근데 혼합도 있음.. 그럼
	// 가장 저렴한 세트 0개 + 나머지 가장 싼 개별가격, 세트 1개 + 나머지 가장 싼 개별가격 이렇게 하면 되겠다

	// 가장 저렴한 세트
	sort(v.begin(), v.end(), firstCompare);
	int pickedSet = v[0][0];

	// 가장 싼 개별가격
	sort(v.begin(), v.end(), secondCompare);
	int pickedEach = v[0][1];

	int totalCnt = 0, ans=1e9, money;


		while (totalCnt<=(N+5)/6) {
			money = totalCnt * pickedSet + max(0 , N - totalCnt * 6) * pickedEach;
			ans = min(ans, money);
		
			totalCnt++;
		}

	

	cout << ans << "\n";

	return 0;
}