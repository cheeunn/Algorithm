#include <iostream>
using namespace std;
int k;
int d[42][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	d[0][0] = 1;
	d[0][1] = 0;
	d[1][0] = 0;
	d[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		d[i][0] = d[i - 1][0] + d[i - 2][0];
		d[i][1] = d[i - 1][1] + d[i - 2][1];
	}
	while (k--) {
		int tmp;
		cin >> tmp;
		cout << d[tmp][0] << " " << d[tmp][1] << "\n";
	}

}