#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m;
char board[12][12];

struct INFO {
	int rx, ry, bx, by, count;
};

INFO start;
int visited[10][10][10][10];

int bfs() {
	int ret = -1;
	queue<INFO> Q;
	Q.push(start);
	visited[start.rx][start.ry][start.bx][start.by] = 1;

	while (!Q.empty()) {
		INFO cur = Q.front(); Q.pop();
		if (cur.count > 10) break;
		if (board[cur.rx][cur.ry] == 'O' && board[cur.bx][cur.by] != 'O') {
			ret = cur.count;
			break;
		}

		for (int dir = 0; dir < 4; dir++) {
			int next_rx = cur.rx;
			int next_ry = cur.ry;
			int next_bx = cur.bx;
			int next_by = cur.by;

			while (1) {
				if (board[next_rx][next_ry] != '#' && board[next_rx][next_ry] != 'O') {
					next_rx += dx[dir]; next_ry += dy[dir];
				}
				else {
					if (board[next_rx][next_ry] == '#') {
						next_rx -= dx[dir]; next_ry -= dy[dir];
					}
					break;
				}
			}

			while (1) {
				if (board[next_bx][next_by] != '#' && board[next_bx][next_by] != 'O') {
					next_bx += dx[dir]; next_by += dy[dir];
				}
				else {
					if (board[next_bx][next_by] == '#') {
						next_bx -= dx[dir]; next_by -= dy[dir];
					}
					break;
				}
			}

			if (next_rx == next_bx && next_ry == next_by) {
				if (board[next_rx][next_ry] != 'O') {
					int dist_r = abs(cur.rx - next_rx) + abs(cur.ry - next_ry);
					int dist_b = abs(cur.bx - next_bx) + abs(cur.by - next_by);

					if (dist_r < dist_b) {
						next_bx -= dx[dir]; next_by -= dy[dir];
					}
					else {
						next_rx -= dx[dir]; next_ry -= dy[dir];
					}
				}
			}
			
			if (visited[next_rx][next_ry][next_bx][next_by] == 1) continue;
			visited[next_rx][next_ry][next_bx][next_by] = 1;
			INFO next;
			next.rx = next_rx;
			next.ry = next_ry;
			next.bx = next_bx;
			next.by = next_by;
			next.count = cur.count + 1;
			Q.push(next);
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R') {
				start.rx = i, start.ry = j;
			}
			if (board[i][j] == 'B') {
				start.bx = i, start.by = j;
			}
		}
	}

	start.count = 0;

	int ret = bfs();

	cout << ret;

}