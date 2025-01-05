/*
 *  이렇게 하니까 시간초과됨.
 *  불의 시작점마다 bfs하니까 불필요한 과정 반복됨 ;(
 *  불의 시작점 모두 Qf에 push 하고 bfs는 한 번만 하면 됨
 *  그리고 상근이 위치도 그냥 따로 큐에 담아서 map에서 이중 for 한 번만 돌게 하자.
 *  그리고 Queue를 함수 param으로 쓸 때 param 은 queue<pair<int, int>> &Q,
 *  function call 하면서 arg로 넘길 땐 주손데 Q 주소는 &Q가 아니라 걍 Q!
 */
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

void bfsF(int i, int j) {
	queue<pair<int, int>> Q;
	distF[i][j] = 0;
	Q.push({ i, j });

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (map[nx][ny] == '#') continue;
			if (distF[nx][ny] != -1 && distF[nx][ny] <= distF[cur.X][cur.Y] + 1) continue;
			distF[nx][ny] = distF[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
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
					bfsF(i, j);
				}
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == '@') {
					bfsS(i, j);
				}
			}
		}
	}
}
