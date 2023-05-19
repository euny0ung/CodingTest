#include <iostream>
using namespace std;

int main() {

	int x=0;

	cin >> x;

	int i = 1;
	while (x > i) {
		x -= i;
		i++;
		/*cout << x << ' ' << i << endl;*/
	}
	if (i % 2 == 0) {
		cout << x << "/" << i+1-x<<endl;
	}
	else {
		cout << i+1-x << "/" << x << endl;
	}

	return 0;
}