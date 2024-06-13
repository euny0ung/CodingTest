#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string S, E, Q, inputTime, name;

int main() {

	int cnt = 0;

	unordered_map<string, int>user;

	cin >> S >> E >> Q;

	while (1) {

		if (cin.eof()) break;
		cin >> inputTime >> name;

		// 입장 먼저 체크
		if (inputTime <= S) {
			user[name] = 1;
		}
		// 퇴장 체크
		else if (E <= inputTime && Q>=inputTime) {
			// 입장했을 경우에만 카운트.
			if (user[name] == 1) {
				cnt++;

				// 여러번 채팅을 할 수 있으니 중복체크
				user[name] = 2;
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}