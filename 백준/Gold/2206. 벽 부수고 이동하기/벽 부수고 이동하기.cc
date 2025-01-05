#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, m;
char board[1002][1002];
int dist[1002][1002][2]; // [0]은 벽 안 깼을 때 [1]은 벽 깼을 때
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool OOB(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= m);
}
int bfs() {
	queue<tuple<int, int, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j][0] = dist[i][j][1] = -1;
		}
	}
	dist[0][0][0] = dist[0][0][1] = 1;
	Q.push({ 0, 0, 0 });

	while (!Q.empty()) {
		int curX, curY, broken;
		tie(curX, curY, broken) = Q.front(); Q.pop();
		if (curX == n - 1 && curY == m - 1) {
			return dist[curX][curY][broken];
		}
		int nextdist = dist[curX][curY][broken] + 1;
		for (int k = 0; k < 4; k++) {
			int nx = curX + dx[k];
			int ny = curY + dy[k];
			if (OOB(nx, ny)) continue;
			if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
				dist[nx][ny][broken] = nextdist;
				Q.push({ nx, ny, broken });
			}
			if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
				dist[nx][ny][1] = nextdist;
				Q.push({ nx, ny, 1 });
			}
		}
	}
	return -1;
}
 int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	queue<pair<int, int>> Q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	cout << bfs();
}