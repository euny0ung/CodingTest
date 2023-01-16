#include <iostream>
#include <stack>
#include <vector>
#include<string>
using namespace std;

int main() {

	int n = 0;
	cin >> n;

	string st;
	stack<double>s;
	vector<int>v;
	int num = 0;
	
	cin >> st;

	for (int i = 0; i < n; i++) { 
		cin >> num; 
		v.push_back(num);
	}

	

	for (int i = 0; i < st.length(); i++) {
		if(st[i]>='A' && st[i] <= 'Z') {
				s.push(v[st[i]-65]);
		}
		else {
			
				double b = s.top();
				s.pop();
				double a = s.top();
				s.pop();
				if (st[i] == '+') s.push(a + b);
				else if (st[i] == '*') s.push(a * b);
				else if (st[i] == '-') s.push(a - b);
				else if (st[i] == '/') s.push(a / b);
			
			
		}
		
	}

	printf("%.2f", s.top());

	return 0;
} // 숫자 대입 아이디어 X