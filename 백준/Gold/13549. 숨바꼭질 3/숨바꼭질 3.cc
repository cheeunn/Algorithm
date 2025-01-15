#include<iostream>
#include<queue>
using namespace std;
#define MAX 200002
int n, k;
int dist[MAX];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	fill(dist, dist + MAX, -1);
	dist[n] = 0;
	deque<int> dq;
	dq.push_back(n);

	while (dq.size()) {
		int cur = dq.front(); dq.pop_front();
		if (cur == k) {
			cout << dist[k];
			return 0;
		}
		int warp = cur * 2; 
		if (warp < MAX && dist[warp] == -1) {
			dist[warp] = dist[cur];
			dq.push_front(warp);
		}
		int l = cur - 1, r = cur + 1;
		if (l >= 0  && dist[l] == -1) {
			dist[l] = dist[cur] + 1;
			dq.push_back(l);
		}
		if (r < MAX && dist[r] == -1) {
			dist[r] = dist[cur] + 1;
			dq.push_back(r);
		}
	}


}