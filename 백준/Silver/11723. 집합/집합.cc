#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int>v;

void add(int x) {
	if (find(v.begin(), v.end(), x) == v.end()) {
		v.push_back(x);
	}
}

void remove(int x) {
	auto it = find(v.begin(), v.end(), x);
	if (it != v.end()) {
		v.erase(it);
	}
}

int check(int x) {
	if (find(v.begin(), v.end(), x) == v.end()) return 0;
	else return 1;
}

void toggle(int x) {
	auto it = find(v.begin(), v.end(), x);
	if (it != v.end()) {
		v.erase(it);
	}
	else {
		v.push_back(x);
	}
}

void empty(){
	v.clear();
}

void all() {
	v.clear();
	v.insert(v.end(), { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19, 20 });
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, input=0;
	
	string str;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;


		if (str != "empty" && str != "all") {
			cin >> input;
		}

		if (str == "add") add(input);
		else if (str == "check") cout<<check(input)<<"\n";
		else if (str == "remove") remove(input);
		else if (str == "toggle") toggle(input);
		else if (str == "all") all();
		else if (str == "empty") empty();
	}

	return 0;
}