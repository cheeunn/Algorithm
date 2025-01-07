#include <iostream>
using namespace std;
#define MAX 81 * 81
int N;
char star[MAX][MAX];
void blank(int x, int y, int z) {
	for (int i = x; i < x + z; i++) {
		for (int j = y; j < y + z; j++) {
			star[i][j] = ' ';
		}
	}
}
void solve(int x, int y, int z) {
	if (z == 3) {
		for (int i = x; i < x + 3; i++) {
			for (int j = y; j < y + 3; j++) {
				if (i == x + 1 && j == y + 1) star[i][j] = ' ';
				else star[i][j] = '*';
			}
		}
		return;
	}
	int n = z / 3;
	for (int i = x; i < x + 3 * n; i += n) {
		for (int j = y; j < y + 3 * n; j += n) {
			if (i == x + n && j == y + n) {
				blank(i, j, n);
			}
			else solve(i, j, n);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	solve(0, 0, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << star[i][j];
		}
		cout << "\n";
	}
}