#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int n = 0, m = 0;
int ans = 0;
vector<int>v;

int BinarySearch(int start, int end) {

	int ans = 0;

	while (start <= end) {
		int middle = (start + end) / 2;
		int sum = 0, cnt = 0;

		for (int i = 0; i < n; i++) {
			if (sum + v[i] > middle) {
				sum = 0;
				cnt++;
			}
			sum += v[i];
		}

		if (sum != 0) cnt++;

		if (cnt > m) {
			start = middle + 1;
		}
		// 개수가 m보다 작거나 같을때 정답이 될 수 있음
		else{
			end = middle - 1;
		}
	}
	return start;
}

int main() {

	
	int input = 0;
	int left = 0, right = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
		right += input;
		left = max(left, input);
		
	}

	cout << BinarySearch(left, right-1) << endl;

	return 0;
}