#include <iostream>
using namespace std;

int N;
int arr[2200][2200];
int cnt[3];

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[x][y] != arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void solve(int x, int y, int n) {
	if (check(x, y, n)) {
		cnt[arr[x][y] + 1]++;
		return;
	}
	n = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(x + n * i, y + n * j, n);
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
			cin >> arr[i][j];
		}
	}
	solve(0, 0, N);
	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << "\n";
	}
}