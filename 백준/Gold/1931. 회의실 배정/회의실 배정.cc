#include <iostream>
#include<utility>
#include <algorithm>
using namespace std;


int n;
pair<int, int> a[100002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
	}
	sort(a, a + n);
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (t <= a[i].second) {
			ans++;
			t = a[i].first;
		}
	}
	cout << ans;
	
}
