#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0;
vector<int>v;

int main() {


	int input = 0;

	map<int, int>mp;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
		mp.insert({ input,0 });
	}


	int i = 0;

	for (pair<int, int>p : mp) {
		if (mp.find(p.first) != mp.end()){
			mp[p.first] = i++;
		}
	}

	for (auto a : v) {
		cout << mp[a] << "\n";
	}

	return 0;
}
