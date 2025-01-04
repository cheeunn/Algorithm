#include <iostream>
#include <queue>
using namespace std;

int n, k;
int line[100002];
int dist[100002];
int dx[2] = { 1, -1 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 100002; i++) {
		dist[i] = -1;
	}
	cin >> n >> k;
	queue <int> Q;
	dist[n] = 0;
	Q.push(n);

	while (dist[k] == -1) {
		int cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 3; dir++) {
			int nx;
			if (dir == 2) nx = 2 * cur;
			else nx = cur + dx[dir];
			if (nx < 0 || nx > 1000000) continue;
			if (dist[nx] != -1) continue;
			dist[nx] = dist[cur] + 1;
			Q.push(nx);
		}
	}
	cout << dist[k];
}