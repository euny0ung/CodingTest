#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	int max = 0;
	string st = "";
	string result = "";
	map<string, int>mp;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> st;
		if (mp.find(st) == mp.end()) { // 값이 없는 경우
			mp.insert({ st,1 });
		}
		else {
			mp[st]++;
		}
		
	}

	for (pair<string, int>p : mp) {
		if (max < p.second) {
			max = p.second;
			result = p.first;
		}
	}

	cout << result;

	return 0;
}