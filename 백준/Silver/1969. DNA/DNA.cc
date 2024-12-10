#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define pp pair<char,int>
using namespace std;

bool compare(const pp& a, const pp& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, M = 0, cnt=0;
	string st = "";
	string ans = "";
	vector<string>dna;

	cin >> N >> M;

	
	// DNA 구하기
	for (int i = 0; i < N; i++) {
		cin >> st;

		dna.push_back(st);
	}

	for (int i = 0; i < M; i++) {
		map<char, int>mp;
		char temp = ' ';

		// 아 바보인가; 위에 while(N--)로 해놔서 동작 안한거임;
		for (int j = 0; j < N; j++) {
			
			mp[dna[j][i]]++;

			vector<pp>v(mp.begin(), mp.end());

			sort(v.begin(), v.end(), compare);

			temp = v[0].first;
		}
		ans += temp;
	}

	// 비교
	for (int i = 0; i < dna.size(); i++) {
		for (int j = 0; j < M; j++) {
			if (ans[j] != dna[i][j]) cnt++;
		}
	}

	cout << ans << "\n";
	cout << cnt << "\n";

	return 0;
}