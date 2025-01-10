#include <iostream>
using namespace std;

int k, n;
int S[302];
int d[302][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> S[i];
	}
	d[1][1] = S[1];
	d[1][2] = 0;
	d[2][1] = S[2];
	d[2][2] = S[1] + S[2];

	for (int i = 3; i <= k; i++) {
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + S[i];
		d[i][2] = d[i-1][1] + S[i];
	}
	cout << max(d[k][1], d[k][2]);
}