#include <iostream>
using namespace std;

int n, m;
int board[1025][1025];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tmp;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			board[i][j] = board[i][j - 1] + board[i - 1][j] - board[i - 1][j - 1] + tmp;
 		}
	}

	while (m--) {
		int ans;
		int x1, x2, y1, y2;

		cin >> x1 >> y1 >> x2 >> y2;
		ans = board[x2][y2] - board[x2][y1 - 1] - board[x1 - 1][y2] + board[x1 - 1][y1 - 1];
		cout << ans << "\n";
	}



}