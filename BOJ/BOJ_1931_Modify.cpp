// BOJ_1931.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

	// Input number of meetings
	int N;
	cin >> N;

	// Pair vectors of meetings
	vector<pair<int, int> > v;

	// Input meetings
	for (int i = 0; i < N; i++) {
		// Input variable
		int start = 0, end = 0;
		cin >> start >> end;

		// Make pair vector (Change first and second)
		v.push_back(pair<int, int>(end, start));
	}

	// Sorted by second
	sort(v.begin(), v.end());

	vector<pair<int, int> >::iterator iter; // iterator : initial meeting
	iter = v.begin();
	int temp = iter->first;

	int count = 1;
	vector<pair<int, int> >::iterator iter2; // iterator2 : remain meetings
	for (iter2 = (iter + 1); iter2 != v.end(); iter2++) {

		// do not overlap each meetings
		if (iter->first <= iter2->second) {
			temp = iter2->first;
			iter = iter2; // Update iterator
			count++;
		}
	}

	// Print result
	cout << count << "\n";

	/* 아래 코드가 잘못된 이유
	시간 제한은 2초
	1초는 대략 100,000,000번 연산

	vector<pair<int, int> >::iterator iter2; // iterator 2
	vector<pair<int, int> >::iterator iter3; // iterator 3

	// 아래와 같이 이중 for문을 구현해버리면
	// N의 최대 값인 100,000일 때는 10,000,000,000번 연산이 되어버림
	// 따라서 시간 초과가 나올 수 밖에 없음
	// 불필요한 연산은 하지 말자!! -> "정렬이 매우 중요"
	for (iter = v.begin(); iter != v.end(); iter++) {
		int count = 1;
		iter3 = iter; // copy iterator

		for (iter2 = iter3 + 1; iter2 != v.end(); iter2++) {
			if (iter3->second <= iter2->first) {
				count++;
				iter3 = iter2;
			}
		}
		res.push_back(count);
	}

	cout << *max_element(res.begin(), res.end()) << endl;
	*/

	return 0;
}