#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int MOD = 20170805;
int DP[510][510][2];

int solution(int m, int n, vector<vector<int>> city_map) {
    memset(DP, 0, sizeof(DP));  // DP 배열 초기화
    DP[1][1][0] = DP[1][1][1] = 1;  // 시작 위치 설정

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;  // 시작점 건너뛰기

            if (city_map[i-1][j-1] == 0) {  // 자유로운 이동 가능
                DP[i][j][0] = (DP[i][j][0] + DP[i-1][j][0] + DP[i][j-1][1]) % MOD;
                DP[i][j][1] = (DP[i][j][1] + DP[i-1][j][0] + DP[i][j-1][1]) % MOD;
            }
            else if (city_map[i-1][j-1] == 1) {  // 통행 금지
                DP[i][j][0] = DP[i][j][1] = 0;
            }
            else {  // 직진만 가능
                DP[i][j][0] = DP[i-1][j][0] % MOD;
                DP[i][j][1] = DP[i][j-1][1] % MOD;
            }
        }
    }
    
    return DP[m][n][0] % MOD;
}
