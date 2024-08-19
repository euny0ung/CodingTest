#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T = 0, N = 0, K = 0, ID = 0, M = 0;
	int team_id = 0, quest = 0, score = 0;
	int rank = 1;

	cin >> T;

	while (T--) {
		cin >> N >> K >> ID >> M;

		rank = 1;
		
		map<int, vector<pair<int, int>>>mp;
		bool checked[101][101] = {};
		int time[101] = {};
		int submit_num[101] = {};

		for (int i = 1; i <= M; i++) {
			cin >> team_id >> quest >> score;
			submit_num[team_id]++; // 제출 횟수 저장
			time[team_id] = i; // 마지막 제출 시간 저장

			// 이미 제출했다면
			if (checked[team_id][quest]) {
				for (auto& problem : mp[team_id]) {
					if (problem.first==quest && problem.second < score) {
						problem.second = score;
						break;
					}
				}
			}
			else {	
				mp[team_id].push_back({quest, score});
			}
			
			checked[team_id][quest] = true; // 문제 제출 여부 저장
			
		}

		// 우리 팀 총합
		int team_total = 0;

		for (const auto& problem : mp[ID]) {
			team_total += problem.second;
		}

		for (int i = 1; i <= N; i++) {
			int total = 0;
			for (const auto& problem : mp[i]) {
				total += problem.second;
			}

			if (total > team_total) rank++;
			else if (total == team_total) {
				if (submit_num[i] < submit_num[ID]) rank++;
				else if (submit_num[i] == submit_num[ID]) {
					if (time[i] < time[ID]) rank++;
				}
			}
		}

		cout << rank << "\n";
	}

	

	return 0;
}