#include <iostream>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;

#define X first
#define Y second

string maze[1002];
int dist[1002][1002];
int distJ[1002][1002];
int r, c;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	queue<pair<int, int>> QF, QJ;
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> maze[i];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			dist[i][j] = -1;
			distJ[i][j] = -1;

			if (maze[i][j] == 'J') {
				QJ.push({ i, j });
				distJ[i][j] = 0;
			}
			if (maze[i][j] == 'F') {
				QF.push({ i, j });
				dist[i][j] = 0;
			}
		}
	}
	while (!QF.empty()) {
		auto cur = QF.front(); QF.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (dist[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
			dist[nx][ny] = dist[cur.X][cur.Y]+ 1;
			QF.push({ nx, ny });
		}
	}
	
	
	while (!QJ.empty()) {
		auto cur = QJ.front(); QJ.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << distJ[cur.X][cur.Y] + 1;
				return 0; 
			}
			if (distJ[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
			if (dist[nx][ny] != -1 && dist[nx][ny] <= distJ[cur.X][cur.Y] + 1) continue;
			distJ[nx][ny] = distJ[cur.X][cur.Y] + 1;
			QJ.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE\n";
	
}