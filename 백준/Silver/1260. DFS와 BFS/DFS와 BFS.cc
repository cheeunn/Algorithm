#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector <vector<int>> graph;
static vector<bool> visited;
void DFS(int v);
void BFS(int v);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v;
	cin >> n >> m >> v;
	graph.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	visited = vector<bool>(n + 1, false);
	DFS(v);
	visited = vector<bool>(n + 1, false);
	cout << '\n';
	BFS(v);
}

void DFS(int node) {
	visited[node] = true;
	cout << node << " ";

	for (int i : graph[node]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}

void BFS(int node) {
	queue<int> myqueue;
	myqueue.push(node);

	visited[node] = true;
	while (!myqueue.empty()) {
		int now_node = myqueue.front();
		myqueue.pop();
		cout << now_node << " ";
		for (int i : graph[now_node]) {
			if (!visited[i]) {
				visited[i] = true;
				myqueue.push(i);
			}
		}
	}
}