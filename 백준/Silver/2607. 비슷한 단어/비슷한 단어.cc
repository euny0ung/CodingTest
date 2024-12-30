#include <iostream>
#include <cmath>
using namespace std;

string words[100];
int counting[100][26];

int main() {

	int N = 0, ans=0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> words[i];
		for (int j = 0; j < words[i].length(); j++) {
			counting[i][words[i][j] - 'A']++;
		}
	}

	for (int i = 1; i < N; i++) {
		int cnt = 0;
		bool diff = false;
		for (int j = 0; j < 26; j++) {
			if (counting[0][j] != counting[i][j]) {
				if (abs(counting[0][j] - counting[i][j]) != 1) { // 알파벳 개수가 2개 이상 차이나면 비슷한 단어가 아님
					diff = true;
					break;
				}
				cnt++;
			}
		}
		if (diff) continue;
		if (cnt == 0) ans++; // 두 단어의 구성이 완전히 동일한 케이스
		else if (cnt == 2 && words[0].length() == words[i].length()) ans++; // CAT과 CAG 같은 케이스
		else if (cnt == 1 && (words[0].length() - words[i].length() == 1 || words[0].length() - words[i].length() == -1)) ans++; // CAT과 CA 같은 케이스
	}
	
	cout << ans << "\n";

	return 0;
}