#include<iostream>
#include <utility>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, m;
int cnt;
int board[305][305];
int visited[305][305];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool no_ice;

bool OOB(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= m);
}
int state() {
	int x, y;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j]) {
				x = i;
				y = j;
				cnt1++;
			}
		}
	}
	if (cnt1 == 0) return 0;
	queue<pair<int, int>> Q;
	visited[x][y] = 1;
	Q.push({ x, y });
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		cnt2++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || visited[nx][ny] || board[nx][ny] == 0) continue;
			visited[nx][ny] = 1;
			Q.push({ nx, ny });
		}
	}
	if (cnt1 == cnt2) return 1;
	else return 2;

}

void ice_melt() {
	int zeros[305][305] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) continue;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (board[nx][ny] == 0) zeros[i][j]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = max(0, board[i][j] - zeros[i][j]);
		}
	}
}

void init_vis() {
	for (int i = 0; i < n; i++) {
		fill(visited[i], visited[i] + m, 0);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int year = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	while (true) {
		year++;
		ice_melt();
		init_vis();
		int check = state();
		if (check == 0) {
			cout << 0;
			return 0;
		} else if (check == 1) {
			continue;
		}
		else {
			break;
		}
	}
	cout << year;
}