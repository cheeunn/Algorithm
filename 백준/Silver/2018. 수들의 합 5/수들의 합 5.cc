#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int start = 1, end = 1;
	int cnt = 1; // n itself 미리 count

	int sum = 1;
	while (end != n) {
		if (sum <= n) {
			if (sum == n) cnt++;
			end++;
			sum += end;
		}
		else {
			sum -= start;
			start++;
		}
	}

	cout << cnt;
	
}