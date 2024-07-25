#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	// a^a - b^b가 G가 되는 경우의 수(a) 구하기

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int G = 0;

	cin >> G;

	// 자연수만 가능
	int start = 1, end = 1;
	int arr[100001] = { 0, };

	vector<int> v;

	for (int i = 1; i <= G; i++) arr[i] = i;

	while (end < G) {
		// 결과값이 G보다 크면 start++
		// 결과값이 G와 같으면 end 값 저장
		// 결과값이 G보다 작으면 end++
		int result = arr[end] * arr[end] - arr[start] * arr[start];

		if (result > G) start++;
		else if (result == G) {
			v.push_back(end);
			start++;
		}
		else end++;
		
	}
		
	

	if (v.empty()) {
		cout << "-1" << "\n";
	}
	else {
		sort(v.begin(), v.end());
		for (auto value : v) cout << value << "\n";
	}


	return 0;
}