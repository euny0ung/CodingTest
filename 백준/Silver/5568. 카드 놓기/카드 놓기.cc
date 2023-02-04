#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;



//int main() {
//
//	int n = 0, k = 0;
//	int card = 0;
//    int cnt = 0;
//	vector<int>v;
//	
//
//	cin >> n >> k;
//	vector<int>res(k,0);
//
//	for (int i = 0; i < n; i++) {
//		cin >> card;
//		v.push_back(card);
//	}
//
//    vector<int> tempVector;
//
//    for (int i = 0; i < k; i++)
//    {
//        tempVector.push_back(1);
//    }
//
//    for (int i = 0; i < v.size() - k; i++)
//    {
//        tempVector.push_back(0);
//    }
//
//    /*cout << "사이즈: " << tempVector.size();*/
//
//    sort(tempVector.begin(), tempVector.end());
//    //sort(v.begin(), v.end());
//
//    do
//    {
//        for (int i = 0; i < tempVector.size(); i++) // 0 0 1 1 // 1 2 12 1
//        {
//            if (tempVector[i] == 1)
//            { // 실제값 출력
//                cout << v[i] << " ";
//            }
//        }
//
//        cout << endl;
//
//    } while (next_permutation(tempVector.begin(), tempVector.end()));
//
//   /* cout << "개수는 " << cnt << endl;*/
//
//	return 0;
//}

int main() {

	int n = 0, k = 0;
	int input = 0;
	

	cin >> n >> k;

	vector<int>v;
	set<string>s;

	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	do {
		string st="";
		for (int i = 0; i < k; i++) {
			st += to_string(v[i]);
			
		}
		s.insert(st); // 중복제거
	} while (next_permutation(v.begin(), v.end()));

	cout << s.size() << endl;
}
