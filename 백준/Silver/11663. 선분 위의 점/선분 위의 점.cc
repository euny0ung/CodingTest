#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;

int Min(int a) {
	int start = 0, end = v.size()-1;
	int min = 0;
	while (start <= end) {
		
		int middle = (start + end)/2;
		if (a > v[middle]) start = middle + 1;
		else end = middle - 1;
	}
	return end+1; // 왜 +1??
}

int Max(int b) {
	int start = 0, end = v.size() - 1;
	int min = 0;
	while (start <= end) {
		
		int middle = (start + end) / 2;
		if (b >= v[middle]) start = middle + 1;
		else end = middle - 1;
	}

	return end; // 왜 end를 리턴해야하지??
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	int input = 0;
	int a = 0, b = 0;
	

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout<< Max(b) - Min(a)+1 << "\n";
	}
	
	return 0;
} // 이해가 안된다...
