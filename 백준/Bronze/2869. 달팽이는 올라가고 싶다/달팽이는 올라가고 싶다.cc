#include <iostream>
#include <cmath>
using namespace std;

int main() {

	double a = 0, b = 0, v = 0;
	int day = 0;

	cin >> a >> b >> v;

	day = ceil((v - b) / (a - b));

	cout << day << endl;

	return 0;
}

// 수학 공식을 생각해내야함.
// ceil 함수 사용 방법 알아야함.