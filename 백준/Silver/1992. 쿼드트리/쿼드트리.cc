#include <iostream>
using namespace std;

int N;
char video[65][65];

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (video[x][y] != video[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void solve(int x, int y, int z) {
	if (check(x, y, z)) {
		cout << video[x][y];
		return;
	}
	int half = z / 2;
	for (int i = 0; i < 2; i++) { // x
		for (int j = 0; j < 2; j++) { // y
			if (i == 0 && j == 0) cout << "(";
			solve(x + half * i, y + half * j, half);
			if (i == 1 && j == 1) cout << ")";
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> video[i][j];
		}
	}
	solve(0, 0, N);
}