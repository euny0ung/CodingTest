#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;
string input;

map < string, string >numbers = {
	{"####.##.##.####", "0"},
	{"###..#####..###", "2"},
	{"###..####..####","3"},
	{"#.##.####..#..#","4"},
	{"####..###..####", "5"},
	{"####..####.####", "6"},
	{"###..#..#..#..#", "7"},
	{"####.#####.####", "8"},
	{"####.####..####", "9"},
};

int main() {

	cin >> N >> input;

	vector<string>v;

	for (int i = 0; i < N; i += N / 5) {
		v.push_back(input.substr(i, N / 5));
	}

	int plus = 1;
	string answer = "";

	for (int i = 0; i < N/5; i+=plus) {

		plus = 1;

		// 숫자이면 15칸 다 저장하고 아니면 1 출력
		if (v[0][i] == '#') {
			// 1인 경우
			string result = "";
			if (i==N/5-1 || v[0][i + 1] == '.' && v[3][i] == '#') {
				answer += '1';
			}
			// 1이 아닌 경우
			else {
				for (int j = 0; j < 5; j++) {
					result += v[j].substr(i, 3);
				}
				plus = 3;
				if (numbers.find(result) != numbers.end()) {
					answer += numbers[result];
				}
			}

			
		}
		
	}

	cout << answer << "\n";

	return 0;
}