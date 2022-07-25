#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main() {

	int n=0, find=0, cnt=0, n_2=0;
	cin >> n >> find;

	vector<int>v;

	for (int i = 1; i <= n; i++) {
		n_2 = i;
		if (i < 10) {
			v.push_back(i);
		}
		else {
			while (n_2 != 0) {
				v.push_back(n_2 % 10);
				n_2 /= 10;
			}
		}
		
	}

	for (int i = 0; i < v.size(); i++) {
		
		if (v[i] == find) {
			cnt++;
		}
		
	}
	cout << cnt << endl;
	

	return 0;
}