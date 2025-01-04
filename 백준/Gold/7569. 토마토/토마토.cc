#include <iostream>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;

 
int board[102][102][102]; // X-Y-Z
int dist[102][102][102];
int h, n, m;
int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0};
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	queue<tuple<int, int, int>> Q;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) { // Z
		for (int j = 0; j < n; j++) { // X
			for (int k = 0; k < m; k++) { // Y
				int tmp;
				cin >> tmp;
				board[j][k][i] = tmp;
				if (tmp == 1) {
					Q.push({ j, k, i });
				}
				if (tmp == 0) {
					dist[j][k][i] = -1;
				}
			}
		}
	}
	
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur;
		for (int dir = 0; dir < 6; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (dist[nx][ny][nz] >= 0) continue;
			dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
			Q.push({ nx, ny, nz });
		}
	}
	
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[j][k][i] == -1) {
					cout << -1 << "\n";
				    return 0;
				}
				ans = max(ans, dist[j][k][i]);
			}
			
		}
	}
	cout << ans;
	
}