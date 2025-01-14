#include <iostream>
#include <string>
using namespace std;

string L, R;
int ans;

int main() {

	cin >> L >> R;

	if (L.length() == R.length()) {
		for (int i = 0; i < L.length(); i++) {
			if (L[i] == '8' && R[i] == '8') {
				ans++;
			}
			else {
				// 두 수가 8이 아닌데 다르면 break
				if (L[i] != R[i]) break;
				else continue;
				// 두 수가 8이 아닌데 같으면 continue
			}
		}
		
	}

	cout << ans << "\n";

	return 0;
}