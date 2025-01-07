#include <iostream>
using namespace std;

int n, s;
int cnt;
int arr[30];

void func(int cur, int tot) {
	if (cur == n) {
		if (tot == s) cnt++;
		return;
	}
	func(cur + 1, tot); // cur 수 포함 X
	func(cur + 1, tot + arr[cur]); // cur 수 포함 O
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	func(0, 0);
	if (s == 0) cnt--; // s 0일 땐 공집합도 포함됨
	cout << cnt;
}