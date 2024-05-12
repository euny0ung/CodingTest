#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string a, string b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	string name = " ";
	vector<string>str;
	vector<string>str2;
	vector<string>str3;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name;
		str.push_back(name);
		str2.push_back(name);
		str3.push_back(name);
	}

	sort(str2.begin(), str2.end()); //오름차순 정렬
	sort(str3.begin(), str3.end(), compare); //내림차순 정렬

	if (str == str2) {
		cout << "INCREASING" << "\n";
	}
	else if (str == str3) {
		cout << "DECREASING" << "\n";
	}
	else {
		cout << "NEITHER" << "\n";
	}

	return 0;
}