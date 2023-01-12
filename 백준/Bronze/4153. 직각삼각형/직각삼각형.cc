#include <iostream>
#include <algorithm>
using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int arr[3] = { 0, };
	int a = 0, b = 0, c = 0;

	
	while (1) {
		for (int i = 0; i < 3; i++) cin >> arr[i];
		sort(arr, arr + 3);

		a = arr[0];
		b = arr[1];
		c = arr[2];

		if (a == 0 && b==0 &&c==0) break;
		if (c * c == a * a + b * b) cout << "right" << endl;
		else cout << "wrong" << endl;
	}

	return 0;
}