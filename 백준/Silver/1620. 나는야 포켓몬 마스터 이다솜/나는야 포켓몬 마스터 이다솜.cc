#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int>um;
string arr[100001];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n = 0, m = 0;
	string input = " ";
	string problem = "";

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> input;
		um[input] = i;
		arr[i] = input;
	}

	for (int i = 0; i < m; i++) {
		cin >> problem;
		// 문자열이면

		if ('A' <= problem[0] && problem[0] <= 'Z') {
			cout << um[problem] << "\n";
		}
		else {
			cout << arr[stoi(problem)] << "\n";
		}
	}

	return 0;
}