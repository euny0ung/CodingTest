#include <iostream>
#include <vector>
using namespace std;

/*
아이디어
- 백트래킹 재귀함수 안에서 for문을 돌며 숫자 선택 (방문여부도 확인)
- 재귀함수에서 M개를 선택할 경우 cout

*/


int n = 0, m = 0;
int arr[9] = { 0, };
bool checked[9] = { false, };

void recursive(int num) {
	
	
		if (num == m) {
			for (int i = 0; i < m; i++) {
				cout << arr[i] <<" ";
			}
			cout << "\n";
			return;
		}
		for (int i = 1; i < n + 1; i++) {
			if (!checked[i]) {
				checked[i] = true;
				arr[num] = i;
				recursive(num + 1);
				checked[i] = false;
			}
		}
	}

int main() {

	
	

	cin >> n >> m;

	recursive(0);

	return 0;
}