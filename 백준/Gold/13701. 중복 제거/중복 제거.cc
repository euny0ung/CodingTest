#include <iostream>
#include <bitset>
#include <string>
using namespace std;

bitset<33554432> bs;


int main() {

	bs.reset();

	int n = 0;

	while (~scanf("%d", &n)) {
		
		if (!bs[n]) cout << n << ' ';
		bs[n] = 1;
	}

	return 0;
}