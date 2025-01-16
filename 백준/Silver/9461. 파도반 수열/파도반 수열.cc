#include <iostream>
using namespace std;
typedef long long ll;

int t, n;
ll p[102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	p[1] = p[2] = p[3] = 1;
	p[4] = 2;
	for (int i = 5; i <= 100; i++) {
		p[i] = p[i - 5] + p[i - 1];
	}
	while (t--) {
		cin >> n;
		cout << p[n] << "\n";
	}
}