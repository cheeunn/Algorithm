#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define X first
#define Y second

int t, n, m, k;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int board[52][52];
bool visited[52][52];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		queue<pair<int, int>> Q;
		int ans = 0;

		while (k--) {
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}
		
		for (int i = 0; i < n; i++) { // y
			for (int j = 0; j < m; j++) { // x
				if (board[j][i] == 1 && !visited[j][i]) {
					visited[j][i] = 1;
					Q.push({ j, i });
					ans++;

					while (!Q.empty()) {
						auto cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
							if (board[nx][ny] == 0 || visited[nx][ny]) continue;
							visited[nx][ny] = 1;
							Q.push({ nx, ny });
						}
					}
				}
			}
		}
		cout << ans << "\n";
		for (int i = 0; i < m; i++) {
			fill(board[i], board[i] + n, 0);
			fill(visited[i], visited[i] + n, 0);
		}
	}

}