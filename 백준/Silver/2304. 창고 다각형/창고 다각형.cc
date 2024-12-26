#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0, pivot=0, result = 0;
vector<pair<int, int>>v;

void searchLeft(int middle, int middleLoc) {

	if (middle == 0) return;

	int target = 0, targetIdx=0, targetLoc = 0;
	for (int i = middle-1; i >=0; i--) {
		if (target <= v[i].second) {
			target = v[i].second;
			targetIdx = i;
			targetLoc = v[i].first;
		}
	}

	result += (middleLoc - targetLoc)*target;

	searchLeft(targetIdx, targetLoc);
}

void searchRight(int middle, int middleLoc) {

	// cout << middle <<" " << middleLoc << "\n";

	if (middle == N-1) return;

	int target = 0, targetIdx = 0, targetLoc=0;
	for (int i = middle + 1; i < N; i++) {
		if (target <= v[i].second) {
			target = v[i].second;
			targetIdx = i;
			targetLoc = v[i].first;
		}
	}

	result += (targetLoc - middleLoc)*target;

	searchRight(targetIdx, targetLoc);
}

int main() {
	
	int loc=0, height=0, pivotIdx=0, pivotLoc=0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> loc >> height;

		v.push_back({ loc, height });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		if (pivot < v[i].second) {
			pivot = v[i].second;
			pivotLoc = v[i].first;
			pivotIdx = i;
		}
	}

	result += pivot;

	// 왼쪽
	searchLeft(pivotIdx, pivotLoc);

	// 오른쪽
	searchRight(pivotIdx, pivotLoc);

	cout << result << "\n";
}