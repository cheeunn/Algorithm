#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define X first
#define Y second

string sboard[102];
int board[102][102];
bool visited[102][102];
int n;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int b = 0, g = 0, r = 0, gr = 0;
	cin >> n;
	queue<pair<int, int>> Q;

	for (int i = 0; i < n; i++) {
		cin >> sboard[i];
		fill(board[i], board[i] + n, -1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sboard[i][j] == 'R') {
				board[i][j] = 1;
			}
			else if (sboard[i][j] == 'G') {
				board[i][j] = 2;
			}
		}
	}

	for (int color : {-1, 1, 2}) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == color && !visited[i][j]) {
					visited[i][j] = 1;
					Q.push({ i, j });
					if (color == -1) b++;
					if (color == 1) r++;
					if (color == 2) g++;
				}
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] != color || visited[nx][ny]) continue;
						visited[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		fill(visited[i], visited[i] + n, 0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] > 0 && !visited[i][j]) {
				visited[i][j] = 1;
				Q.push({ i, j });
				gr++;
			}

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] < 0 || visited[nx][ny]) continue;
					visited[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
		}
	}

	cout << b + g + r << ' ' << b + gr;
	
}