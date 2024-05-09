#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n = 0, list=0;
	int result = 0;
	

	cin >> n;

	int *a = new int[n];
	int* b = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> list;
		a[i] = list;
	}
	for (int i = 0; i < n; i++) {
		cin >> list;
		b[i] = list;
	}

	sort(a, a + n, greater<>());
	sort(b, b + n);

	
	for (int i = 0; i < n; i++) {
		result += a[i] * b[i];
	}

	cout << result << endl;

	return 0;
}