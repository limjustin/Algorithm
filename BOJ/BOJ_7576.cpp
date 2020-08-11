// BOJ_7576.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M; // Height and Width
int ripenDay; // Check maximum days do tomatoes all ripen

vector<int> graph[1001]; // Tomato Box
queue<pair<int, int> > q; // Queue used in BFS

bool visited[1001][1001]; // visited array
int day[1001][1001]; // Check how many days do tomatoes all ripen


int dx[4] = { -1, 0, 1, 0 }; // Clockwise Search
int dy[4] = { 0, 1, 0, -1 }; // Left, Down, Right, Up



void input() {
	// Input Variables
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// Input Graph
			int temp;
			cin >> temp;
			graph[i].push_back(temp);
			
			// Where is ripen tomato
			if (graph[i][j] == 1) { // If tomatoes are ripen
				q.push(make_pair(i, j)); // Push into Queue
				visited[i][j] = true; // make visited true
			}
		}
	}
}

bool IsAllRipen() {
	vector<int> findmax; // To find max ripen day
	bool flag = true; // Tomatoes are all ripen, true or false?

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// Push into vector
			findmax.push_back(day[i][j]);

			// If any unripe tomatoes are find
			if (graph[i][j] == 0)
				flag = false; // Make flag false
		}
	}

	ripenDay = *max_element(findmax.begin(), findmax.end()); // find max ripen day

	return flag; // Return flag
}

int RipenTomato() {

	while (!q.empty()) {
		int n = q.front().first;
		int m = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int cx = n + dx[i]; // Change Direction
			int cy = m + dy[i];

			// Clockwise Direction Search
			if (cx < 0 || cx > N - 1 || cy < 0 || cy > M - 1) // not in range
				continue;

			// Find not ripen tomato
			else if (graph[cx][cy] == 0) {
				q.push(make_pair(cx, cy)); // Push into Queue
				visited[cx][cy] = true; // make visited true
				graph[cx][cy] = 1; // Make Tomato ripen
				day[cx][cy] = day[n][m] + 1; // Check ripen days
			}
		}
	}

	// Check all tomatoes are ripen
	if (IsAllRipen())
		return ripenDay; // Return whole ripen day

	return -1; // Return -1
}

int main(void) {
	// Input Function
	input();

	// RipenTomato Function
	cout << RipenTomato();

	return 0;
}

/*
문제 풀때 어려웠던 점
- Queue에 Pair를 어떤 방식으로 넣고, 사용해야 하는지
	- Queue.push() 함수 사용
	- 사용할 때는 특정 값을 꺼내올 수 없으므로, Queue.front()로 일단 값 가져오기
	- Queue.front().first 혹은 Queue.front().second 와 같은 방식으로 사용할 수 있는거 처음 알음

- 상하좌우 탐색을 어떤 방식으로 진행해야 하는지
	- (-1, 0), (0, 1), (1, 0), (0, -1)을 어떤식으로 진행해야 하는지
	- cx, cy 배열 사용해서 for문 활용하여 좌표 값을 계산하면 가능

- 1차원 배열의 최댓값 찾기 쉬움, 2차원 배열은...?
	- STL vector에 다 때려 넣어서 1차원 배열(vector)로 만들기
	- 그러고 나서 *max_element() 사용해서 최댓값 찾는 아이디어 좋았음
	- 2차원 배열을 1차원 배열로 만들 수도 있다는 사실 꼭 알아두기
*/