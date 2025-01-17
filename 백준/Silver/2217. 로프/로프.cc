#include <iostream>
#include <algorithm>
using namespace std;


int n;
int rope[100002];

bool compare(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> rope[i];
	}
	sort(rope + 1, rope + 1 + n, compare);

	for (int i = 1; i <= n; i++) {
		ans = max(ans, rope[i] * i);
	}
	cout << ans;
}
