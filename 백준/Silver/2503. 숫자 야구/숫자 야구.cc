#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int num = 0;
	int input = 0;
	int my_strike = 0, my_ball = 0;
	int cnt = 0;
	int check = 0;

	bool arr[1000]={ false };

	//bool arr[3] = { false }; // 모두 false로 초기화
	//bool arr[3] = { true }; //맨 처음 값만 true 나머지는 default false.. 이거 몰라서 계속 틀렸다ㅋㅋㅋ

	vector<int>v;
	vector<int>v2;
	

	cin >> num;

	for (int i = 0; i < num; i++) {
		
		cin>> input >> my_strike >> my_ball;

		while (input != 0) {
			v.insert(v.begin(),input % 10);
			input /= 10;
		} // OK

		


		for (int j = 123; j <= 987; j++) { //0이랑 중복되는 숫자 안걸러내서 틀렸다^^...
			int strike = 0, ball = 0;
			int target = j;
			int remain = target % 10;
			int remain2 = target / 10 %10;
			int remain3 = target /10 /10 % 10;

			if (remain == 0 || remain2 == 0 || remain3 == 0) { // 아니 이 부분 true 말고 continue로 하면 왜 결과 이상해짐???
				arr[j] = true;
					/*continue;*/
			} // 0이 있으면 다시
			if (remain == remain2 || remain2 == remain3 || remain3 == remain) {
				arr[j] = true;
					/*continue;*/
			}

			while (target != 0) {
				
				v2.insert(v2.begin(), target%10);
				target /= 10;
			}

			
		
			for (int my_index = 0; my_index < 3; my_index++) {
				for (int index = 0; index < 3; index++) {
					if (v[my_index]  == v2[index] && my_index == index) strike++;
					else if (v[my_index]  == v2[index]) ball++; // 값만 같은 경우
				}
			} // 두 수 모두 비교

			

			if ((strike != my_strike) || (ball != my_ball)) {
				arr[j] = true; 
			}
			

			v2.clear();
			}

		v.clear();	
	}

	
		
	

	for (int i = 123; i <= 987; i++) {
		/*cout << arr[i] << endl;*/
		if (!arr[i]) {
			cnt++;
		}
	}

	cout << cnt << endl;

	// 입력 받고 123~987까지 비교. a[index]과 값이 같고 index까지 같다면 strike. 비교하는 숫자들도 arr에 넣어줘야함.
}