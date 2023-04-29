#include <iostream>
#include <map>
using namespace std;

int main() {

	int T = 0;
	
	map<string, int>um;
	
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int n = 0;
		int cnt = 0;
		string st1, st2 = "";
		int result = 1;
		um.clear();
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> st1 >> st2;
			
			if (um.find(st2) == um.end()) { //없는 경우

				um.insert({ st2, 1 });
			}
			else {
				um[st2] += 1; // 있으면 value값 ++
			}
			
		}

		for (pair<string, int>pa : um) {
			result *= (pa.second + 1);
		}

		cout << result - 1 << endl;
		
	}

	return 0;
}