#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 10001

int main() {
	vector<int>v;
	
	vector<int> arr;
	
	for (int i = 1; i < MAX; i++) {
		v.push_back(i);
	}
	for (int j = 0; j < MAX-1; j++) {
		int target = 0;
		string s=to_string(v[j]);
		for (int k = 0; k < s.length(); k++) {
				target += s[k]-'0';
			}
		target += stoi(s);
		arr.push_back(target);
	}
	for (auto a : arr) { // arr에 있는 수가 v에 있으면 삭제
		if (find(v.begin(), v.end(), a) != v.end()) {
			
			v.erase(remove(v.begin(), v.end(), a), v.end());
		}
	}

	for (auto a :v) {
		cout << a << endl;
	}
	return 0;
}