#include <iostream>
#include <vector>
#include<stack>
using namespace std;

int main() {

	int n = 0, p = 0;
	int cnt = 0;
	int num = 0, p_num = 0;
	vector<stack<int>>v(7);

	cin >> n >> p;

	for (int i = 0; i < n; i++) {
		cin >> num >> p_num;

		
		

			// 2 -1 . peek값이 현재보다 크다면 더 이상 큰 값이 안나올때까지 pop해주고 현재값을 push cnt+2
			if (!v[num].empty()  && v[num].top() > p_num) {
				while (!v[num].empty() && v[num].top() > p_num) {
					
					v[num].pop();
					cnt++;
				}
				
				
			}
			// 2-2. peek값이 현재와 같다면 아무런 행동을 하지 않음
	
		// 1. 스택이 비어있는 경우엔 무조건 삽입 cnt+1
		// 2. peek값이 현재 값보다 작으면 삽입 cnt+1
		if (v[num].empty() || v[num].top() < p_num) {
			v[num].push(p_num);
			cnt++;
		}

		
		

		
	}
	cout << cnt << endl;
	return 0;
}