#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second 

int n;

int cnt;
char board[27][27];
bool vis[27][27];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<int> v;

bool OOB(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= n);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '0' || vis[i][j]) continue;
			cnt++;
			vis[i][j] = 1;
			int area = 1;
			queue<pair<int, int>> Q;
			Q.push({ i, j });
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (OOB(nx, ny)) continue;
					if (board[nx][ny] == '0' || vis[nx][ny]) continue;
					vis[nx][ny] = 1;
					area++;
					Q.push({ nx, ny });
				}
			}
			v.push_back(area);
		}
	}
	sort(v.begin(), v.end());
	cout << cnt << "\n";
	for (int& area : v) cout << area << "\n";
	
}