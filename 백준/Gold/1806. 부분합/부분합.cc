#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N=0;
    long S=0;
    cin >> N >> S;

    int arr[100000];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long sum = 0;
    int minLength = N + 1; // 초기값은 불가능한 큰 값으로 설정

    int start = 0, end = 0;
    while (end < N) {
        // sum에 arr[end]를 더하고 end를 증가시킨다
        while (sum < S && end < N) {
            sum += arr[end];
            end++;
        }

        // sum이 S 이상이 되면 start를 증가시키며 최소 길이를 찾는다
        while (sum >= S) {
            minLength = min(minLength, end - start);
            sum -= arr[start];
            start++;
        }
    }

    // minLength가 초기값 그대로이면 부분 배열을 찾을 수 없는 경우이다
    if (minLength == N + 1) {
        cout << 0 << endl;
    } else {
        cout << minLength << endl;
    }

    return 0;
}