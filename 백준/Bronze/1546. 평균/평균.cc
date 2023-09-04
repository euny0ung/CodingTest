#include<iostream>
#include <vector>
using namespace std;

int main() {

	int N = 0;
	double input = 0;
	double result = 0;
	double secondResult = 0;
	double max = 0;

	cin >> N;

	vector<double>v;

	for (int i = 0; i < N; i++) {
		cin >> input;
		//result += input;
		v.push_back(input);
		if (max < input) max = input;
	}

	//result /= N;

	for (int i = 0; i < N; i++) {
		secondResult += v[i] / max * 100;
	}

	printf("%lf", secondResult/N);


	return 0;
}