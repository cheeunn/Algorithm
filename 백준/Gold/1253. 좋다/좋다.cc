#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int s = 0, e = n - 1;
		while (s < e) {
			if (v[s] + v[e] == v[i]) {
				if (s == i) s++;
				else if (e == i) e--;
				else {
					cnt++;
					break;
				}
			}
			else if (v[s] + v[e] > v[i]) {
				e--;
			}
			else {
				s++;
			}
		}
	}
	cout << cnt;

}