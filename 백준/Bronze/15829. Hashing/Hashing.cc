#include<iostream>
#include <cmath>
using namespace std;

int main() {

	char ch;
	int n;
	int cnt = 0;
	int result = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> ch;
		result += ((int)ch - 96) * pow(31, cnt);
		result %= 1234567891;
		// 모듈러 연산은 정수만 가능한데 pow때문에 double형됨.

		cnt++;
	}

	cout << result << endl;

	

	return 0;
}