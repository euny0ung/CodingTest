#include <iostream>
#include <map>
using namespace std;

int main() {

	int n = 0;
	string st;
	int cnt = 0;

	map<string, int>mp;
	int arr[1001];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> st;
		mp.insert({ st,i });
	}

	st = "";

	for (int j = 0; j < n; j++) {
		cin >> st;
		int order = mp[st];
		arr[j] = order;
	}

	for (int i = 0; i < n- 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				cnt++;
				break;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}