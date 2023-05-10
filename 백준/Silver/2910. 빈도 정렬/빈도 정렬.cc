#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int>mp;
map<int, int>mp_ord;

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) {
		return mp_ord[a.first] < mp_ord[b.first];
	}
	return a.second > b.second;
}

int main() {

	int n = 0, c = 0;
	int input = 0;
	
	

	cin >> n >>c;

	for (int i = 0; i < n; i++) {
		cin >> input;
		
		if (mp.find(input) == mp.end()) {
			mp.insert({ input,1 });
			mp_ord.insert({ input, i });
		}
		else {
			mp[input]++;
		}
	}

	vector<pair<int, int>>v(mp.begin(),mp.end());

	sort(v.begin(), v.end(), cmp);

	for (auto a : v) {
		for (int i = 0; i < a.second; i++) {
			cout << a.first << endl;
		}
	}


	return 0;
}