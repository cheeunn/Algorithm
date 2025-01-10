#include <iostream>
using namespace std;

int n;
int d[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) { // 2로 나누어 떨어질 때
			if (i % 3 == 0) {
				d[i] = min(d[i / 2] + 1, d[i / 3] + 1);
				d[i] = min(d[i], d[i - 1] + 1);
			}
			else {
				d[i] = min(d[i / 2] + 1, d[i - 1] + 1);
			}
		}
		else {
			if (i % 3 == 0) {
				d[i] = min(d[i / 3] + 1, d[i - 1] + 1);
			}
			else {
				d[i] = d[i - 1] + 1;
			}
		}
	}

	cout << d[n];
}