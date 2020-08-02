// BOJ_11047.cpp
#include <iostream>
using namespace std;

int main(void) {

	// Input N and K
	int N, K;
	cin >> N >> K;

	int coins[10];
	int count = 0;

	// Input coins
	for (int i = N - 1; i >= 0; i--)
		cin >> coins[i];

	// minimum value of the number of coins needed to make K-Won
	for (int i = 0; i < N; i++) {
		// If it can be divided
		while (K - coins[i] >= 0) {
			K = K - coins[i]; // Subtract coin
			count++; // Increase count
		}
	}

	// Print Result
	cout << count;

	return 0;
}