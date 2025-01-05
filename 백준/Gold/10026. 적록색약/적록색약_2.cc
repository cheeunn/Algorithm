#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define X first
#define Y second


char board[102][102];
bool visited[102][102];
int n;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int i, int j) {
	int ans = 0;
	queue<pair<int, int>> Q;
	Q.push({ i, j });
	visited[i][j] = 1;

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visited[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;
			visited[nx][ny] = 1;
			Q.push({ nx, ny });
		}
	}

}

int area() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				cnt++;
				bfs(i, j);
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	int not_s = area();
	
	for (int i = 0; i < n; i++) {
		fill(visited[i], visited[i] + n, 0);
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G') {
				board[i][j] = 'R';
			}
		}
	}
	int yes_s = area();
	cout << not_s << " " << yes_s;
	
}
