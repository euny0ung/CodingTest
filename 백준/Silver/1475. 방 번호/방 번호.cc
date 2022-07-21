#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {

	string str;
	int result = 0;
	int max = 0;
	cin >> str;

	int arr[10]={0,};

	for(int i = 0; i < str.length(); i++) {
		if (str[i] - '0' == 9) {
			arr[6]++;
		}
		else {
			arr[str[i] - '0']++;
		}
		
	}
	
	if (arr[6] % 2 == 1) {
		arr[6] = arr[6] / 2 + 1;
	}
	else {
		arr[6] = arr[6] / 2;
	}



	for(int i = 0; i < 10; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	cout << max;

	return 0;
}