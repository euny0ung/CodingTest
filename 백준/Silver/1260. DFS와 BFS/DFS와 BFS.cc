#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> gr[1001] = {};
bool check_1[1001] = { false };
bool check_2[1001]= { false };
vector<int>v1;
vector<int>v2;
queue<int>q;

void DFS(int n) {
	check_1[n] = true;

	int sz = gr[n].size();

	

	for (int i = 0; i < sz; i++) {
		int y = gr[n][i];
		if (!check_1[y]) {
			v1.push_back(y);

			
			
			DFS(y);
			
			
		}
	}

}

void BFS(int n) {
	
	check_2[n] = true;
	q.push(n);

	

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		

		for (int i = 0; i < gr[x].size(); i++) {
				
				int y = gr[x][i];


				if (!check_2[y]) {
					
					q.push(y);
					v2.push_back(y);

					check_2[y] = true;
					
					
				}
			}
	}
	
	
	
}

int main() {
	
	int n = 0, m = 0, v = 0;
	int a = 0, b = 0;

	cin >> n >> m >> v;

	if ((n >= 1 && n<=1000)&&(m>=1&&m<=10000)) {
			for (int i = 0; i < m; i++) {
				cin >> a >> b;
				gr[a].push_back(b);                                   
				gr[b].push_back(a);
		
		} 

		for (int i = 1; i <=n; i++) {
			
				sort(gr[i].begin(), gr[i].end());
			
			
		} //완전 치명적인 부분 발견... i를 1로 바꿔야 연결된 애들끼리 정렬을 한다... 아무생각없이 코딩하지말자
		//?? 정렬 때문에 예제 하나에서 걸렸는데 i<m을 i<=n으로 바꿔주니까 된다! 아하 n은 6 m은 5인데 내가 v가 6이라서 안됐던것

		/*for (int i = 0; i < n; i++) {
			if (!check_1[i]) {
				v1.push_back(v);
				DFS(v);
			
			}
			if (!check_2[i]) {
				v2.push_back(v);
				BFS(v);
			
			}
		
		}*/

		

		v1.push_back(v);
		v2.push_back(v);

		DFS(v);
		BFS(v);

	
	
		for (int i =0; i <v1.size(); i++) {
			cout << v1[i] <<' ';
		
		}
		cout << "\n";

		for (int i = 0; i < v2.size(); i++) {
			cout << v2[i] << ' ';
		
			}
	}
	else {

	}
	
	

	return 0;
}