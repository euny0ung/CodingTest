#include <iostream>
using namespace std;



int main() {

	int H = 0, M = 0, real_time=0, my_time=0, my_H=0, my_M=0;

	cin >> H >> M;

	if (H == 0) {
		H = 24;
	}
	if (M == 0) {
		H--;
		M = 60;
	}

	real_time = H * 60 + M;

	my_time = real_time - 45;
	my_H = my_time / 60;
	my_M = my_time % 60;

	if (my_H >= 24) {
		my_H -= 24;
	}
	if (my_M == 60) {
		my_M = 0;
	}
	cout << my_H << ' ' << my_M << endl;

	return 0;
}