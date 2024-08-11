#include <iostream>
#include <vector>
using namespace std;

int main() {

	string str1 = "";
	string str2 = "";

	cin >> str1;
	cin>> str2;

	str1 = "0" + str1;
	str2 = "0" + str2;

	vector<vector<int>>dp;

	dp.resize(str2.length(), vector<int>(str1.length()));

	for (int i = 0; i < str2.length(); i++) {
		for (int j = 0; j < str1.length(); j++) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if (str2[i] == str1[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}	
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[str2.length() - 1][str1.length() - 1] << "\n";

	return 0;
}