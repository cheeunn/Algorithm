#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, m;
int board1[10][10];
int board2[10][10];
int vis[10][10];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> blank;

void bfs() {
	for (int i = 0; i < n; i++) {
		fill(vis[i], vis[i] + m, 0);
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board2[i][j] == 2 && vis[i][j] == 0) {
				vis[i][j] = 1;
				q.push({ i, j });

				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board2[nx][ny] != 0 || vis[nx][ny]) continue;
						vis[nx][ny] = 1;
						board2[nx][ny] = 2;
						q.push({ nx, ny });
					}
				}
			}
		}
	}
}

int count_safe() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board2[i][j]) continue;
			ret++;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio();
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board1[i][j];
			if (board1[i][j] == 0) {
				blank.push_back({ i, j });
			}
		}
	}

	int mx = 0;
	vector <int> brute(blank.size(), 0);
	fill(brute.end() - 3, brute.end(), 1);
	do {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board2[i][j] = board1[i][j];
			}
		}
		for (int i = 0; i < blank.size(); i++) {
			if (brute[i] == 0) continue;
			pair wall = blank[i];
			board2[wall.X][wall.Y] = 1;
		}
		bfs();
		mx = max(mx, count_safe());
	} while (next_permutation(brute.begin(), brute.end()));

	cout << mx;
}