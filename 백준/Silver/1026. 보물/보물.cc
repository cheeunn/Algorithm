#include <iostream>
#include <algorithm>
using namespace std;


int n;
int A[52];
int B[52];

bool compare(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	sort(A, A + n);
	sort(B, B + n, compare);
	for (int i = 0; i < n; i++) {
		ans += A[i] * B[i];
	}
	cout << ans;
}
