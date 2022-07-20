#include <iostream>
#include <string>
using namespace std;

int main() {

	int n;
	string word;
	int count = 0;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> word;
		bool arr[26] = { false, };
		arr[(int)(word[0] - 97)] = true;

		for (int j = 1; j < word.length(); j++) { // 문자열 검사
			if (word[j] != word[j - 1]) { // 앞의 문자와 다른 경우
				if (arr[(int)(word[j]-97)] == false) { // false인 경우
					arr[(int)(word[j] - 97)] = true;
				}
				else { // true인 경우
					count++;
					break;
				}
			}
		}
	}
	
	cout << n - count << endl;

	return 0;
}