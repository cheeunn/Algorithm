#include <iostream>
#include <algorithm>
using namespace std;


int n;
int t[1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	sort(t, t + n);

	for (int i = 0; i < n; i++) {
		ans += t[i] * (n - i);
	}
	cout << ans;
	
}
