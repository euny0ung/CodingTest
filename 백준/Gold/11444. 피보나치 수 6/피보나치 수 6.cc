#include <iostream>
#include <unordered_map>
#define DIV 1000000007LL
using namespace std;

unordered_map<long long, long long> map;

long long fibo(long long x) {
	if (x == 0) return 0;
	if (x == 1) return 1;

	if (map.count(x) > 0) return map[x];

	long long k = x / 2;
	
	// 짝수일때
	if (x % 2 == 0) {
		
		map[x] = fibo(k)*((fibo(k) + 2 * fibo(k - 1)) % DIV)%DIV;
		return map[x];
	}
	
	map[x] = ((fibo(k) * fibo(k)) % DIV + (fibo(k + 1) * fibo(k + 1)) % DIV) % DIV;
	return map[x];
	
}


int main() {

	long long N = 0;


	cin >> N;

	cout << fibo(N) << "\n";

	return 0;
}