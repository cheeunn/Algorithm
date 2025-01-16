#include<iostream>
using namespace std;

int n;
int d[100002];
int arr[100002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	d[0] = arr[0];
	if (d[0] < 0) d[0] = 0;
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		d[i] = d[i - 1] + arr[i];
		if (d[i] > max) max = d[i];
		if (d[i] < 0) d[i] = 0;
	}
	cout << max;
}