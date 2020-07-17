#include <iostream>
#include <queue>
using namespace std;

int main(void) {

	int N;
	queue<int> q; // Queue 선언

	// N의 값 입력 받음
	cin >> N;

	// Queue에 숫자를 넣는 과정
	for (int i = 1; i <= N; i++) {
		q.push(i); // 낮은 숫자가 front, 높은 숫자가 back
	}

	while (q.size() != 1) {
		q.pop(); // 맨위에 쌓인 원소를 제거
		// 가장 위에 있는 숫자를 아래로 내리는 과정
		int temp = q.front();
		q.push(temp);
		q.pop();
	}
	
	cout << q.front(); // 원소가 한개여서 front던 back이던 상관 없음

	return 0;
}