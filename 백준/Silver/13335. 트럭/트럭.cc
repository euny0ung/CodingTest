#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

	int N = 0, W = 0, L = 0, input=0;
	queue<int>q;
	vector<int>v;

	cin >> N >> W >> L;

	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	int sum = 0, time=0;

	for (int i = 0; i < v.size(); i++) {
		while (1) {

			if (q.size() == W) {
				sum -= q.front();
				q.pop();
			}
			if (sum + v[i] <= L) break;
			q.push(0);
			time++;
		}

		q.push(v[i]);
		sum += v[i];
		time++;
	}

	time += W;

	cout << time << "\n";

	return 0;
}