// BOJ_1260.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, V; // Variables
vector<int> graph[1001]; // Graph
bool visited[1001]; // Visited array
queue<int> q; // Queue in BFS

void input() {
	// Input Variable
	cin >> N >> M >> V;

	// Input Vertices
	for (int i = 0; i < M; i++) {
		// Start vertex and End vertex
		int start_vtx, end_vtx;
		cin >> start_vtx >> end_vtx;

		// Non-directed Graph
		graph[start_vtx].push_back(end_vtx);
		graph[end_vtx].push_back(start_vtx);
	}

	// Sorting Vertices
	for (int j = 1; j <= N; j++) {
		sort(graph[j].begin(), graph[j].end());
	}
}

void DFS(int v) {

	// Change to visited
	visited[v] = true;
	cout << v << " ";

	// Vertices in Graph
	for (int s = 0; s < graph[v].size(); s++) {
		if (!visited[graph[v][s]]) // Not visit yet
			DFS(graph[v][s]); // Core of DFS : Implementing a stack with a 'Recursive Function'
	}
}

void BFS(int v) {
	// Input vertex in Queue
	q.push(v);
	visited[v] = true; // Change to visited

	while (q.empty() == false) { // Core of BFS : Using a 'Queue'

		// Point to the front of the Queue
		int qptr = q.front();
		cout << qptr << " ";
		q.pop(); // Pop it

		// Vertices in Graph
		for (int s = 0; s < graph[qptr].size(); s++) {
			if (!visited[graph[qptr][s]]) { // Not visited yet
				q.push(graph[qptr][s]); // Input vertex in Queue
				visited[graph[qptr][s]] = true; // Change to visited
			}
		}
	}
}

int main(void) {
	
	// Input Function
	input();

	// DFS Function
	DFS(V);
	cout << "\n";

	// Initialize all visited to false
	memset(visited, false, sizeof(visited));
	
	// BFS Function
	BFS(V);
	cout << "\n";

	return 0;
}

/*

DFS와 BFS에 관한 핵심 정리
1. DFS(Depth First Search)
- 사용하는 자료구조 : Stack
- Stack 구현 방법 : Recursive Function
- 재귀 함수가 빠져나가는 원리 생각해보기 (Stack 비울 때)

2. BFS(Breadth First Search)
- 사용하는 자료구조 : Queue
- Queue 구현 방법 : STL Queue
- Queue를 이용해서 만든 것이 BFS이므로, 여기서는 재귀함수를 애초에 사용 X

*/