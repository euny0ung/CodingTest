#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string input1 = "", input2="";
	int cnt1[26] = { 0, };
	int cnt2[26] = { 0, };
	int ans = 0;

	cin >> input1 >> input2;


	for (int i = 0; i < input1.length(); i++) {
		cnt1[input1[i] - 'a']++;
	}

	for (int i = 0; i < input2.length(); i++) {
		cnt2[input2[i] - 'a']++;
	}


	for (int i = 0; i < 26; i++) {
		if (cnt1[i] != cnt2[i]) {
			ans += abs(cnt1[i] - cnt2[i]);
		}
	}

	cout << ans << "\n";

	return 0;
}