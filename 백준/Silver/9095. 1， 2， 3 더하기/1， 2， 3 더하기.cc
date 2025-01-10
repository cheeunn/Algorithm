#include <iostream>
using namespace std;

int k, n;
int d[1000001];
int arr[12];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i <= 10; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	cin >> k;
	while (k--) {
		cin >> n;
		cout << d[n] << "\n";
	}
}