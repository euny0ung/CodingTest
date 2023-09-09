#include <iostream>
#include <stack>
 
using namespace std;
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
 
    stack<pair<int, int> > s;  // pair<int, int> : index, height
    int num, height;
    cin >> num;
 
    for (int i = 0; i < num; i++) {
        cin >> height;
 
        while (!s.empty()) {
            //수신탑 발견했을 때
            if (height < s.top().second) { // s.top().second
                cout << s.top().first << " ";
                break;
            }
            //수신탑 찾을 때까지 계속 pop
            s.pop();
        }
        //수신 탑이 없다면
        if (s.empty()) {
            cout << 0 << " ";
        }
        //현재 높이를 스택에 푸쉬
        s.push(make_pair(i + 1, height));
    }
     
    return 0;
}