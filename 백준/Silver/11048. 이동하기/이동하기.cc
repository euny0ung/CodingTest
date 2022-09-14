#include<iostream>
using namespace std;
#define range 1001

int arr[range][range] = { 0 };


int Max(int a, int b) {
		if (a > b) return a; return b;
	}

int main() {

	int N = 0, M = 0;
	int input = 0;
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> input;
			arr[i][j] = input;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			arr[i][j] += Max(Max(arr[i][j-1], arr[i - 1][j]), arr[i - 1][j - 1]);
			
		}
	}

	

	cout << arr[N][M] << endl;



	return 0;
}