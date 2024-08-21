#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string S;
	int zero_cnt = 0, one_cnt = 0;
	int zero = 0, one = 0;

	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '0') zero_cnt++;
		else one_cnt++;
	}

	int i = 0;

	while (one < one_cnt / 2) {
		if (S[i] == '1') {
				S.erase(S.begin() + i);
				one++;
		}
		else {
			i++;
		}
		
	}

	int j = S.length() - 1;
	while (zero < zero_cnt / 2) {
		if (S[j] == '0') {
			S.erase(S.begin() + j);
			zero++;
		}
		j--;
	}

	cout << S << "\n";

}