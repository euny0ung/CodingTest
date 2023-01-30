#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n = 0;
	long long result = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		
		result += i;
		if (result > n) { 
			cout << i - 1 << endl;
			break; 
		}
        else if(result==n){
            cout<<i<<endl;
            break;
        }
	}

	return 0;
} 