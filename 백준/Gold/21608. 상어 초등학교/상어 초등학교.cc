#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Position {
    int x;
    int y;
    int blank_count;
    int like_count;
};

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int N = 0;
vector<int> v[401];
int arr[20][20] = { 0 };

// 범위 확인 함수
bool isRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// 자리 정하기 함수
void place_student(int student) {
    Position best = {-1, -1, -1, -1}; // 최적의 위치 초기화
    
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (arr[r][c] == 0) { // 빈 칸만 검사
                int blank_count = 0, like_count = 0;
                
                // 인접 칸 탐색
                for (int k = 0; k < 4; k++) {
                    int nextX = r + dx[k];
                    int nextY = c + dy[k];
                    if (isRange(nextX, nextY)) {
                        if (arr[nextX][nextY] == 0) blank_count++; // 빈칸 세기
                        if (find(v[student].begin(), v[student].end(), arr[nextX][nextY]) != v[student].end()) like_count++; // 좋아하는 학생 세기
                    }
                }
                
                // 더 나은 위치를 찾으면 갱신
                if (like_count > best.like_count ||
                    (like_count == best.like_count && blank_count > best.blank_count) ||
                    (like_count == best.like_count && blank_count == best.blank_count && r < best.x) ||
                    (like_count == best.like_count && blank_count == best.blank_count && r == best.x && c < best.y)) {
                    best = {r, c, blank_count, like_count};
                }
            }
        }
    }
    
    // 최적의 위치에 학생 배치
    arr[best.x][best.y] = student;
}

// 만족도 계산 함수
int calculate_satisfaction() {
    int total_satisfaction = 0;
    
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int student = arr[r][c];
            int like_count = 0;
            
            // 인접 칸에 좋아하는 학생이 있는지 확인
            for (int k = 0; k < 4; k++) {
                int nextX = r + dx[k];
                int nextY = c + dy[k];
                if (isRange(nextX, nextY) && find(v[student].begin(), v[student].end(), arr[nextX][nextY]) != v[student].end()) {
                    like_count++;
                }
            }
            
            // 만족도 계산
            if (like_count == 1) total_satisfaction += 1;
            else if (like_count == 2) total_satisfaction += 10;
            else if (like_count == 3) total_satisfaction += 100;
            else if (like_count == 4) total_satisfaction += 1000;
        }
    }
    
    return total_satisfaction;
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N * N; i++) {
        int student;
        cin >> student;
        for (int j = 0; j < 4; j++) {
            int like_student;
            cin >> like_student;
            v[student].push_back(like_student);
        }
        place_student(student);
    }
    
    // 만족도 계산 및 출력
    cout << calculate_satisfaction() << endl;
    
    return 0;
}