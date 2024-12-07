#include <iostream>
#include <set>
using namespace std;

int main() {

	string s;
	set<string>st;

	cin >> s;

	int len = s.length();

	for (int i = 0; i < len; i++) {
		for (int j = 1; i+j <=len; j++) {
			st.insert(s.substr(i, j));
		}
	}

	cout << st.size() << "\n";

	return 0;
}