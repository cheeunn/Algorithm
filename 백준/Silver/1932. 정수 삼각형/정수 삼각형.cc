#include <iostream>
#include <algorithm>
using namespace std;
int n;
int d[502][502];
int arr[502][502];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	d[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		d[i][0] = d[i - 1][0] + arr[i][0];
		d[i][i] = d[i - 1][i - 1] + arr[i][i];
		for (int j = 1; j < i; j++) {
			d[i][j] = max(d[i-1][j - 1], d[i-1][j]) + arr[i][j];
		}
	}
	sort(d[n - 1], d[n - 1] + n);
	cout << d[n - 1][n - 1];
}