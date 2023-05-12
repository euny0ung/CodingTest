#include <iostream>
#include <queue>
using namespace std;

int main() {

	int n = 0, m = 0;
	int apple = 0;
	int apple_num = 0;
	int cnt = 0;
	queue<int>q;

	cin >> n >> m;

	int basket_front = 1;
	int basket_back = m;

	cin >> apple_num;

	for (int i = 0; i < apple_num; i++) {
		cin >> apple;
		q.push(apple);
	}

	while (!q.empty()) {
		int apple_idx = q.front();
		if (apple_idx > basket_back) {
			cnt+= apple_idx - basket_back;
			basket_back = apple_idx;
			basket_front= apple_idx - m+1;
			
		}
		else if(apple_idx<basket_front) {
			cnt+= basket_front - apple_idx;
			basket_front= apple_idx;
			basket_back = basket_front +m-1;
			
			
		}
		q.pop();
	}

	cout << cnt << endl;
	return 0;
}
