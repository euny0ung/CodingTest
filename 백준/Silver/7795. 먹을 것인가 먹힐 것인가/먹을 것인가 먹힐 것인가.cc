#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int tc = 0;
	

	cin >> tc;

	for (int i = 0; i < tc; i++) {
		
		int n = 0, m = 0;
		int result = 0;
		int input = 0;

		vector<int>n_vec;
		vector<int>m_vec;
		
		cin >> n >> m;

		for (int j = 0; j < n; j++) {
			cin >> input;
			n_vec.push_back(input);
		}
		for (int j = 0; j < m; j++) {
			cin >> input;
			m_vec.push_back(input);
		}

		int size = m_vec.size();

		sort(m_vec.begin(), m_vec.end());
		
		for (int i = 0; i < n; i++) {
			int ub = upper_bound(m_vec.begin(), m_vec.end(), n_vec[i])-m_vec.begin();
			
			if (ub != 0) {
				
				if (n_vec[i] != m_vec[ub - 1]) {
					//cout << n_vec[i] << " " << ub << endl;
					result += ub;
				}
				else {
					//lower_bound-1 더하기
					int lb = lower_bound(m_vec.begin(), m_vec.end(), n_vec[i]) - m_vec.begin();
					if(lb!=0) result += lb;
					/*cout << n_vec[i] << " " << lb << endl;*/

				}
				
			}
			
		}

		cout << result << endl;
	}



	return 0;
}