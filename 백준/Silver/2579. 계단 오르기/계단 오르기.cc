#include <iostream>
using namespace std;

int k, n;
int S[302];
int d[302];
int sum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> S[i];
		sum += S[i];
	}
	d[1] = S[1];
	d[2] = S[2];
	d[3] = S[3];
	for (int i = 4; i <= k; i++) {
		d[i] = min(d[i - 2], d[i - 3]) + S[i];
	}
	cout << sum - min(d[k-2], d[k-1]);
}