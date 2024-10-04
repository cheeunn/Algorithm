#include <iostream>
#include <vector>
using namespace std;
static vector<vector <int>> A;
static vector<bool> visited;
void DFS(int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	A.resize(n + 1);
	visited = vector<bool>(n + 1, false);
	
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	int count = 0;

	for (int i = 1; i < n + 1; i++) {
		if (!visited[i]) {
			count++;
			DFS(i);
		}
	}

	cout << count << '\n';
}

void DFS(int v) {
	if (visited[v]) {
		return;
	}
	visited[v] = true;
	for (int i : A[v]) {
		if (visited[i] == false) {
			DFS(i);
		}
	}
}