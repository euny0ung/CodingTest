#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int a = 0, b = 0, c = 0;
	int arr[3] = {};

	while (1) {
		cin >> a >> b >> c;
		arr[0] = a, arr[1] = b, arr[2] = c;

		if (a == 0 && b == 0 && c == 0) break;

		sort(arr, arr + 3);

		if (arr[2] >= arr[0] + arr[1]) { 
			cout << "Invalid" << "\n"; 
			continue;
		}
		
		if (a == b && b== c && a==c) cout << "Equilateral" << "\n";
		else if (a == b || b == c || c == a) cout << "Isosceles" << "\n";
		else cout << "Scalene" << "\n";
	}

	return 0;
}