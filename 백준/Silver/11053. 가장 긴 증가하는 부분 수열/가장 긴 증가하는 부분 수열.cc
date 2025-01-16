#include <iostream>
using namespace std;

int n;
int arr[1002];
int d[1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				d[i] = max(d[i], d[j]);
			}
		}
		d[i]++;
		ans = max(ans, d[i]);
	}
	cout << ans;
}