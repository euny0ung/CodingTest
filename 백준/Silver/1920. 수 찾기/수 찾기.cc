#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>v;

int Find(int input, int s, int e, int m) {
	while (s <= e) {
		m = (s + e) / 2;
		
		if (input < v[m]) {
			e = m - 1; //mid-1
		}
		else if (input > v[m]) {
			s = m + 1; //mid+1
		}
		else if (input == v[m]) {
			return 1;
		}
	}
	return 0;

}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	int input = 0;

	cin >> N;
	int start = 0, end = N-1, middle = 0;


	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> input;
		int check = Find(input, start, end, middle);
		cout << check << ' ';
	}



	return 0;
}