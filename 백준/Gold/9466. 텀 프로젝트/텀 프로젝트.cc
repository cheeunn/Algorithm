#include <iostream>
#include <queue>
using namespace std;
int t, n;
int arr[100002];
int state[100002];

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int s) { // s는 시작점
	int cur = s;
	while (true) {
		state[cur] = s;
		cur = arr[cur];
		if (state[cur] == s) {
			while (state[cur] != CYCLE_IN) {
				state[cur] = CYCLE_IN;
				cur = arr[cur];
			}
			return;
		}

		else if (state[cur] != 0) return;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		fill(state + 1, state + n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++) {
			if (state[i] == NOT_VISITED) run(i);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (state[i] != CYCLE_IN) cnt++;
		}

		cout << cnt << "\n";
	}
}