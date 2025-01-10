#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second 

int n, m, k;

int cnt;
int board[102][102];
bool visited[102][102];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<int> areas;

bool OOB(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= m);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x1, y1, x2, y2;
	cin >> n >> m >> k;
	queue<pair<int, int>> Q;
	while (k--) {
		cin >> y1 >> x1 >> y2 >> x2;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				board[i][j] = 1;

			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 && !visited[i][j]) {
				visited[i][j] = 1;
				int area = 1;
				cnt++;
				Q.push({ i, j });
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (OOB(nx, ny)) continue;
						if (board[nx][ny] || visited[nx][ny]) continue;
						visited[nx][ny] = 1;
						Q.push({ nx, ny });
						area++;
					}
				}
				areas.push_back(area);
			}
		}
	}
	cout << cnt << "\n";
	sort(areas.begin(), areas.end());
	for (int& area : areas) cout << area << " ";
}