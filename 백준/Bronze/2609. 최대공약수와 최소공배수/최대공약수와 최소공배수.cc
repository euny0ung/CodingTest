#include<iostream>
#include <cmath>
using namespace std;

int main() {

	int n = 0, m = 0;
	int a = 0, b = 0;
	int max = 0;

	cin >> n >> m;

	int num = min(n, m);

	for (int i = 1; i <= num; i++) {
		if (n % i == 0 && m % i == 0) {
			if (max < i) a = i;
		} //최대 공약수
		
	}

	b = a * (n / a) * (m / a); //최소 공배수

	cout << a << endl;
	cout << b << endl;

	return 0;
}