// BOJ_1065.cpp
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	
	// Input Positive Integer
	int N;
	cin >> N;

	// Result Value
	int result;

	// Classification by number of digits
	if (N < 100)
		result = N; // only print their number
	else {
		vector<int> res;
		// In case of more than triple digits
		// just repeat for-statement until 100 
		for (int i = 0; i <= N - 100; i++) {
			int num = N - i;
			int mod;
			vector<int> v;

			// Divide digits
			while (num > 0) {
				mod = num % 10;
				v.push_back(mod);
				num /= 10;
			}

			// In case of three digits
			// vector index 0 ~ 2
			if (v.size() == 3 && (2 * v[1] == v[0] + v[2]))
				res.push_back(N - i);

			// In case of four digits
			// vector index 0 ~ 3
			else if (v.size() == 4 && (v[3]-v[2] == v[2]-v[1]) && (v[2]-v[1] == v[1]-v[0]) && (v[3]-v[2] == v[1]-v[0]))
				res.push_back(N - i);
		}

		result = 99 + res.size(); // plus 99, because they already include two digits number
	}

	// Print result
	cout << result << "\n";

	return 0;
}