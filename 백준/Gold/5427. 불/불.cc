#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define X first
#define Y second
#define FIRE 0
#define SG 1

int t, w, h;
string map[1002];
int distF[1002][1002];
int distS[1002][1002];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfsF(queue<pair<int, int>> &Qf) {
	while (!Qf.empty()) {
		auto cur = Qf.front(); Qf.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (map[nx][ny] == '#' || distF[nx][ny] != -1) continue;
			distF[nx][ny] = distF[cur.X][cur.Y] + 1;
			Qf.push({ nx, ny });
		}
	}
}

void bfsS(int i, int j) {
	queue<pair<int, int>> Q;
	distS[i][j] = 0;
	Q.push({ i, j });

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
				cout << distS[cur.X][cur.Y] + 1 << "\n";
				return;
			}
			if (map[nx][ny] == '#' || distS[nx][ny] != -1) continue;
			if (distF[nx][ny] != -1 && distF[nx][ny] <= distS[cur.X][cur.Y] + 1) continue;
			distS[nx][ny] = distS[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;

	while (t--) {
		cin >> w >> h;
		queue<pair<int, int>> Qf;
		int SGx, SGy;

		for (int i = 0; i < h; i++) {
			fill(distF[i], distF[i] + w, -1);
			fill(distS[i], distS[i] + w, -1);
		}

		for (int i = 0; i < h; i++) {
			cin >> map[i];
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == '*') {
					distF[i][j] = 0;
					Qf.push({ i, j });
				}
				if (map[i][j] == '@') {
					SGx = i;
					SGy = j;
				}
			}
		}

		bfsF(Qf);
		bfsS(SGx, SGy);
	}
}