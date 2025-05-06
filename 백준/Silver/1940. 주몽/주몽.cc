#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int s = 0, e = n - 1;
	int cnt = 0;
	while (s < e) {
		if (v[s] + v[e] == m) {
			cnt++;
			e--; s++;
		}
		else if (v[s] + v[e] < m) {
			s++;
		}
		else {
			e--;
		}
	}
	cout << cnt;

}