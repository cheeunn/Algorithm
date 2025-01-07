#include <iostream>
using namespace std;

int n, cnt;
bool isused1[15];
bool isused2[30];
bool isused3[30];

void func(int cur) {
	if (cur == n) {
		cnt++;
		return; 
	}
	for (int i = 0; i < n; i++) {
		if (!isused1[i] && !isused2[cur + i] && !isused3[i - cur + n - 1]) {
			isused1[i] = isused2[cur + i] = isused3[i - cur + n - 1] = 1;
			func(cur + 1);
			isused1[i] = isused2[cur + i] = isused3[i - cur + n - 1] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	func(0);
	cout << cnt;
}