#include <iostream>
using namespace std;

int n;
int board1[22][22];
int board2[22][22];
int ANS = -1;


void rotate() {
	int tmp[22][22];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = board2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board2[i][j] = tmp[n - 1 - j][i];
		}
	}

}
void swipe(int dir) {
	while (dir--) rotate();

	
	for (int i = 0; i < n; i++) {
		int target = 0;
		int tmp[21] = { 0, };
		for (int j = 0; j < n; j++) {
			if (board2[i][j] == 0) continue;
			if (tmp[target] != board2[i][j]) {
				if (tmp[target] != 0) target++;
				tmp[target] = board2[i][j];
			}
			else {
				tmp[target] *= 2;
				target++;
			}
		}
		for (int j = 0; j < n; j++) board2[i][j] = tmp[j];
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board1[i][j];
		}
	}

	int mx = 0;

	for (int tmp = 0; tmp < (1 << 2 * 5); tmp++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board2[i][j] = board1[i][j];
			}
		}
		int brute = tmp;
		int dir = 0;
		for (int i = 0; i < 5; i++) {
			dir = brute % 4;
			brute /= 4;
			swipe(dir);
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mx = max(mx, board2[i][j]);
			}
		}
	}

	cout << mx;
	
}