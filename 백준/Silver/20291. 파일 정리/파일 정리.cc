#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

int main() {

	int n = 0;
	string s = "";
	string buffer = "";
	map<string, int>mp;
	vector<string>v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		istringstream ss(s);


		while (getline(ss, buffer, '.')) {
			v.push_back(buffer);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (i % 2 != 0) {
			if (mp.find(v[i]) == mp.end()) {
				mp.insert({ v[i], 1 });

			}
			else {
				mp[v[i]]++;
			}
		}

	}

	for (pair<string, int>p : mp) {
		cout << p.first <<' ' << p.second << endl;
	}
	

	return 0;
}