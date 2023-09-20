#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long>v;
int m = 0, n = 0;
int ans = 0;

int binarySearch(int start, int end) {

	while (start <= end) {
		
		int result = 0;

		int middle = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			result += v[i] / middle;
			
		}
		
		if (result >= m) {
			ans = middle;
			start = middle + 1;
		}
		else {
			end = middle - 1;
		}
	}

	return ans;
}

int main() {

	//조카, 과자개수

	long maxValue = 0;
	long snack_length = 0;

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		cin >> snack_length;
		v.push_back(snack_length);
		maxValue = max(snack_length, maxValue);

	}


	// 주의.. 어떤 막대과자를 주는지는 상관없음. 1인당 떨어지는 잘린 막대과자 길이가 똑같으면 됨
	// 딱히 정렬할 필요가 없음


	int start = 1, end = maxValue;
	
	cout << binarySearch(start, end) << endl;

	return 0;
}