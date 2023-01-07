#include <iostream>
#include <string>
using namespace std;

int main() {

	int n = 0;
	int title = 666;
	int cnt = 0;
	
	cin >> n;

	while (1) {
		if (to_string(title).find("666")!=string::npos) cnt++;
		if (cnt == n) break;
		title++;
	}

	cout << title << endl;

	return 0;
}