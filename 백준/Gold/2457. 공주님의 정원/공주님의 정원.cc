#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define start first
#define end second

int n;
vector<pair<int, int>> flowers;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		flowers.push_back({ sm * 100 + sd, em * 100 + ed });
	}
	
	int cur = 301;
	int ans = 0;
	
	while (cur < 1201) {
		int next = cur;
		for (int i = 0; i < n; i++) {
			if (flowers[i].start <= cur && next <= flowers[i].end) {
				next = flowers[i].end;
			}
		}
		if (next == cur) {
			cout << 0;
			return 0;
		}
		cur = next;
		ans++;
	}
	cout << ans;
}