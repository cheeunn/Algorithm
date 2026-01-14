#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a1, a0, c, n;
	bool ans;
	
	cin >> a1 >> a0 >> c >> n;
	if (a1 > c) {
		ans = 0;
	}
	else if (a1 == c) {
		if (a0 > 0) ans = 0;
		else ans = 1;
	}
	else {
		ans = a1 * n + a0 <= c * n ? 1 : 0;
	}
	
	cout << ans;
}