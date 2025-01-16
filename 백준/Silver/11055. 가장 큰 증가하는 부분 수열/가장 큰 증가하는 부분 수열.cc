#include <iostream>
using namespace std;

int n;
int a[1002];
int d[1002];
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = a[i];
		for (int j = 1; j < i; j++) {
			if(a[j] < a[i]) {
				d[i] = max(d[i], d[j] + a[i]);
			}
		}
		ans = max(ans, d[i]);
	}
	cout << ans;

}