#include <iostream>

using namespace std;

int count_trailing_zeros(int N) {
    int count = 0;
    for (int i = 5; N / i >= 1; i *= 5) {
        count += N / i;
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    cout << count_trailing_zeros(N) << endl;
    return 0;
}