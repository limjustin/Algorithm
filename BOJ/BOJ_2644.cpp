// BOJ_2644.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n; // Total Person
int A, B; //Calculate the degree of kinship between two person
int m; // Edges
int kinship;
vector<int> graph[101]; // Maximum people is 100
bool visited[101]; // visited array
int level[101];
queue<int> q; // Queue used in BFS

void input() {
	// Input
	cin >> n;
	cin >> A >> B;
	cin >> m;

	// Relationship
	for (int i = 0; i < m; i++) {
		int x, y; // x is parent, y is descendent
		cin >> x >> y;

		// Non-directed Graph
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	// Sorting each vertices
	for (int j = 1; j <= n; j++) {
		sort(graph[j].begin(), graph[j].end());
	}
}

int FindKinship(int v, int goal) {
	// Push into Queue and Check visited
	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		int parent = q.front(); // Queue front is parent
		q.pop(); // Pop

		// Graph Search
		for (int s = 0; s < graph[parent].size(); s++) {
			// not visit yet
			if (!visited[graph[parent][s]]) {
				// Push into Queue and Check visited
				q.push(graph[parent][s]);
				visited[graph[parent][s]] = true;

				// Calculate Vertex Level (Using parent's level)
				level[graph[parent][s]] = level[parent] + 1;

				// If find goal
				if (graph[parent][s] == goal)
					return level[graph[parent][s]]; // return level of it
			}
		}
	}
	return -1; // non-relative, return -1
}

int main(void) {
	// Input Function
	input();
	
	// FindKinship Function and Print Result
	cout << FindKinship(A, B) << "\n";

	return 0;
}

/*
문제 풀 수 있었던 핵심 아이디어
- BFS 알고리즘 활용
- 촌수를 계산하려면, vertex 간의 거리를 알아야하는데(level)
  부모의 level을 활용해서 자식의 level을 측정하는 알고리즘을 활용
- level을 재려면, 부모의 level을 활용하자!! (누적의 개념)
*/