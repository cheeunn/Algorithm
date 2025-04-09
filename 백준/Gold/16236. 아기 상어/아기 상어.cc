#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#include <climits>
using namespace std;

#define X first
#define Y second

int n;
int sharkSize = 2;
int cnt, ans;
int board[21][21];
int dist[21][21];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

tuple<int, int, int> eatfish(int x, int y) {
	tuple<int, int, int> mn = { INT_MAX, INT_MAX, INT_MAX };
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + n, -1);
	}
	
	q.push({ x, y });
	board[x][y] = 0;
	dist[x][y] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (dist[cur.X][cur.Y] > get<0>(mn)) break;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (dist[nx][ny] != -1 || board[nx][ny] > sharkSize) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			if (board[nx][ny] != 0 && board[nx][ny] < sharkSize) {
				mn = min(mn, { dist[nx][ny], nx, ny });

			}
			q.push({ nx, ny });
		}
	}
	return mn;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int shark_x = 0, shark_y = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				shark_x = i, shark_y = j;
			}
		}
	}
			
	while (1) {
		tuple<int, int, int> mn = eatfish(shark_x, shark_y);
		int dist, x, y;
		tie(dist, x, y) = mn;
		if (dist == INT_MAX) break;
		cnt++;
		if (cnt == sharkSize) {
			sharkSize++;
			cnt = 0;
		}
		ans += dist;
		shark_x = x, shark_y = y;
	}
	cout << ans;
	

}