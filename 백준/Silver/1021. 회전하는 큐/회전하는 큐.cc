#include <iostream>
#include <deque>
using namespace std;

int main() {

	int n = 0, m = 0;
	int input = 0;
	int cnt = 0;
	int loc = 0;
	

	cin >> n >> m;

	deque<int>d;

	for (int i = 1; i <= n; i++) {
		d.push_back(i);
	} // 덱에 숫자 넣어줌

	for (int j = 0; j < m; j++) {
		int k = 0;
		cin >> input;

		while(k<d.size()){
			if (input == d[k]) { 
				loc = k;
				break; 
			}// 인덱스 구하기
			// 아니 왜 loc이 계속 0만 나오냐고.. 대괄호 안넣어서 그런거였음;;
			k++;
		}

		if ( loc <= d.size() / 2) { // 마지막 예제 여기에 = 넣어주니까 풀렸는데 왜지??
			while (1) {
				if(d.front() != input){
					d.push_back(d.front());
					d.pop_front();
					cnt++;
				}
				else {
					d.pop_front();
					break;
				}
				
			}
		} // input이 들어있는 위치가 n/2보다 작으면 왼쪽으로 밀기 cnt++ ㅂ
		else {
			while (1) {
				if(d.front() != input){
					d.push_front(d.back());
					d.pop_back();
					cnt++;		
				}
				else {
					d.pop_front();
					break;
				}
				
			}
		}	// input이 들어있는 위치가 n/2보다 크면 오른쪽으로 밀기 cnt++
	
		
	}
	cout << cnt << endl;
	return 0;
}