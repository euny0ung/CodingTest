#include <iostream>
using namespace std;

long A = 0, B = 0, C = 0;

long calc(long A, long exp) {
	
	// 지수가 1일 때
	if (exp == 1) {
		return A%C;
	}

	int temp = calc(A, exp / 2);

	// 지수가 짝수일 때
	if (exp % 2 == 0) {
		return temp%C * temp%C;
	}
	// 지수가 홀수일 때
	else {
		return temp%C * temp%C * A%C;
	}
}

int main() {

	cin >> A >> B >> C;

	cout<<calc(A, B)<<"\n";


	return 0;
}