#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	long kids = 0, jewel = 0;
	int colors = 0;
	long mx=0;
	int result = 0;

	vector<long>v;

	cin >> kids >> colors;

	for (int i = 0; i < colors; i++) {
		cin >> jewel;
		v.push_back(jewel);
		mx = max(mx, jewel);
	}

	

	int start = 1, end = mx;

	while (start <= end) {
		
		int middle = (start + end) / 2;
		int cnt = 0;

		for (int i = 0; i < colors; i++) {
			// 나머지가 있으면
			if (v[i] % middle != 0) {
				cnt += v[i] / middle+1;
			}
			// 나머지가 없으면
			else {
				cnt += v[i] / middle;

			}
		}

		if (cnt <= kids) {
			end = middle - 1;
			result = middle;
		}
		else {
			start = middle + 1;
		}

		
		
	}
	cout << result << endl;
	
	return 0;
}