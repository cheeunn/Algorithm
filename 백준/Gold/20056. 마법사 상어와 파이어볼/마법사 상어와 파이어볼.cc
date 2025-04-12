#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct FIREBALL {
	int x, y, m, s, d;
};

vector<FIREBALL> fireballs;

int n, M, k;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1};

void move_all_fireballs() {
	vector<FIREBALL> board[52][52];
	// 파이어볼 이동
	for (auto fb : fireballs) {
		int nx = (fb.x + (fb.s % n) * dx[fb.d] + n) % n;
		int ny= (fb.y + (fb.s % n) * dy[fb.d] + n) % n;
		fb.x = nx;
		fb.y = ny;
		board[nx][ny].push_back(fb);
	}

	fireballs.clear();

	// 이제 파이어볼 합체
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j].size() == 0) continue;
			if (board[i][j].size() == 1) {
				fireballs.push_back(board[i][j][0]);
				continue;
			}
			int new_m = 0, new_s = 0;
			bool all_even = true, all_odd = true;
			for (auto fb : board[i][j]) {
				new_m += fb.m;
				new_s += fb.s;
				if (fb.d % 2 == 0) all_odd = false;
				else all_even = false;
			}
			new_m /= 5;
			if (new_m == 0) continue;
			new_s /= board[i][j].size();
			vector<int> new_dir = (all_even || all_odd) ? vector<int> {0, 2, 4, 6} : vector<int>{ 1, 3, 5, 7 };
			for (int d : new_dir) {
				fireballs.push_back({ i, j, new_m, new_s, d});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio();
	cin.tie(0);

	cin >> n >> M >> k;
	int ans = 0;
	for (int i = 0; i < M; i++) {
		int x, y, m, s, d;
		cin >> x >> y >> m >> s >> d;
		fireballs.push_back({ x - 1, y - 1, m, s, d });
	}
	
	while (k--) {
		move_all_fireballs();
	}

	for (auto fb : fireballs) {
		ans += fb.m;
	}
	cout << ans;
}