#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	char game=' ';
	string name = " ";

	map<char, int>m = { {'Y',2}, {'F', 3}, {'O', 4} };
	set<string>s;

	cin >> N >> game;

	for (int i = 0; i < N; i++) {
		cin >> name;
		s.insert(name);
	}

	int result = s.size() / (m[game] - 1);

	cout << result << "\n";

	return 0;
}