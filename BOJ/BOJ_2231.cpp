// BOJ_2231.cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {

	// Input Positive Integer
	int N;
	cin >> N;

	// Find Digits
	int temp, digits = 0;
	temp = N;
	while (temp > 0) {
		temp /= 10;
		digits++;
	}

	// Find Smallest Generator
	int mod, sum, num;
	vector<int> v;
	for (int i = 1; i <= 9 * digits; i++) {
		num = N - i;
		sum = num;

		while (num > 0) {
			mod = num % 10;	// Modulo
			num /= 10;	// Downgrade Digits
			sum += mod;
		}

		if (sum == N)
			v.push_back(N -i);
	}

	// N does not have any generators
	if (v.size() < 1)
		cout << '0';
	// N has multiple generators
	else
		cout << *min_element(v.begin(), v.end()) << endl;
	
	return 0;
 }