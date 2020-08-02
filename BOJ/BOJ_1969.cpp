// BOJ_1969.cpp
#include <iostream>
#include <map>
using namespace std;

int main(void) {

	// Input number of DNA and length
	int N, M;
	cin >> N >> M;
	char str[1001][51]; // Put all character type of nucleotides

	// Result of this Code
	int total = 0; // Smallest sum of the Hamming Distance

	// Input DNA
	for (int i = 0; i < N; i++)
			cin >> str[i];

	// Hamming Distance
	map<char, int> m; // nucleotides map
	map<char, int>::iterator iter;
	for (int j = 0; j < M; j++) {

		// Make nucleotides map
		m['A'] = 0;
		m['C'] = 0;
		m['G'] = 0;
		m['T'] = 0;

		// Count the number of nucleotides
		for(int i = 0; i < N; i++)
			m.find(str[i][j])->second++;

		// Find the largest number of nucleotides
		int max = 0; char temp = ' ';
		for (iter = m.begin(); iter != m.end(); iter++) {
			if (max < iter->second) {
				max = iter->second;
				temp = iter->first;
			}
		}

		// Making Result
		cout << temp;
		total += (N - max);
	}

	// Print Result
	cout << "\n" << total << "\n";

	return 0;
}