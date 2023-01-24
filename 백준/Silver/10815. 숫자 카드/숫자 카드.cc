#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;

int Check(int num, int start, int end) {
	

	while (start<=end) {
		
		int mid = (start+end) / 2; // mid을 while 안에 넣어서 갱신했어야하는데....
	
		if (num < v[mid]) end = mid - 1;
		else if (num > v[mid])start = mid + 1;
		else if(num==v[mid]) return 1;
		
	}
	return 0;
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	long long input = 0, input2 = 0;


	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}

	int start = 0, end = v.size();

	sort(v.begin(), v.end());

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> input2;
		cout<<Check(input2, start, end)<<' ';
	}
	

	return 0;
} 

// 또 시간초과남...^^ 벡터를 밖으로 빼는 방법 시도. 이거 안되면 안푼다