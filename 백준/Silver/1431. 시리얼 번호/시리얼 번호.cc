#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

map<string, int>mp;

bool cmp(pair<string, int>a, pair<string, int>b) {
	if (a.first.size() != b.first.size()) {
		return a.first.size() < b.first.size();
	}
	else {
		if (mp[a.first] != mp[b.first]) {
			return mp[a.first] < mp[b.first];
		}
		else {
			return a.first < b.first;
		}
	}

}

int main() {
	int n = 0;
	int add = 0;
	string st;


	cin >> n;

	for (int i = 0; i < n; i++) {
		add = 0;
		cin >> st;
		for (int j = 0; j < st.size(); j++) {
			if (st[j] >= '0' && st[j] <= '9') {
				add += st[j] - '0';
			}
		}
	
		mp.insert({ st,add });
	}

	vector<pair<string, int>>v(mp.begin(), mp.end());

	sort(v.begin(), v.end(), cmp);

	for (auto a : v) {
		cout << a.first << endl;
	}
}