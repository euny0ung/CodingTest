#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;

int Search(long long start, long long end, int target) {
	long long middle = 0;
	long long result = 0;

	while (start <= end) {
		int cnt = 0;
		middle = (start + end) / 2; //middle값이 int범위 넘길수도

		for (int i = 0; i < v.size(); i++) {
			cnt += v[i] / middle;
		}
		if (cnt >= target) {
			result = middle;
			start = middle + 1;
		}
		else {
			end = middle - 1;
		}
	}
	
	return result;
	
} //N개보다 많이 만드는 것도 N개를 만드는 것에 포함됨.

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k = 0, n = 0;
	int input = 0;

	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		cin >> input;
		v.push_back(input);
	}
	
	sort(v.begin(), v.end());
	int max = *max_element(v.begin(), v.end());

	cout << Search(1, max, n) << endl;

	return 0;
} 
