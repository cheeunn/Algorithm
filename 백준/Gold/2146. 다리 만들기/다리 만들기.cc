#include<iostream>
#include <utility>
#include <queue>
using namespace std;

#define X first
#define Y second

int n;
int cnt;
int board[102][102];
bool vis[102][102];
int dist[102][102];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


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

	// 섬에 번호 붙이기
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue;
			num++;
			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			board[i][j] = num;
			Q.push({ i, j });
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (OOB(nx, ny)) continue;
					if (board[nx][ny] == 0 || vis[nx][ny]) continue;
					vis[nx][ny] = 1;
					board[nx][ny] = num;
					Q.push({ nx, ny });
					}
	
			}
		}
	}

	// 이중 for 돌면서 섬에서 bfs 시작.
	// 다른 섬 찾으면 다리 길이 min이랑 비교해서 업데이트
	int ans = 500;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if (board[i][j] != 0) { // 섬 찾으면
				for (int k = 0; k < n; k++) fill(dist[k], dist[k] + n, -1);
				dist[i][j] = 0; // 방문 표시
				queue<pair<int, int>> Q;
				Q.push({ i, j });
				bool escape = false;

				while (!Q.empty() && !escape) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (OOB(nx, ny)) continue;
						if (dist[nx][ny] >= 0 || board[nx][ny] == board[i][j]) continue;
						if (board[nx][ny] != board[i][j] && board[nx][ny] != 0) {
							// new 섬
							ans = min(ans, dist[cur.X][cur.Y]);
							escape = true;
							while (!Q.empty()) Q.pop();
							break;
						}
						// board[nx][ny] == 0
						dist[nx][ny] = dist[cur.X][cur.Y] + 1;
						Q.push({ nx, ny });
					}
				}
			}
		}
	}

	cout << ans;


}