#include <iostream>
using namespace std;
#define MAX 81 * 81
int N;
char star[MAX][MAX];


void solve(int x, int y, int z) {
	if (z == 1) {
		star[x][y] = '*';
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			int n = z / 3;
			solve(x + i * n, y + j * n, n);
		}
	}
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		fill(star[i], star[i] + N, ' ');
	}
	solve(0, 0, N);

	for (int i = 0; i < N; i++) {
		cout << star[i] << "\n";
	}
}
