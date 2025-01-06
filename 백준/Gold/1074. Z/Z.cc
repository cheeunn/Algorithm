#include <iostream>
using namespace std;

int func(int n, int r, int c) {
	if (n == 0) return 0;
	int half = 1 << (n - 1);
	int zone;
	if (r < half && c < half) return func(n - 1, r, c);
	if (r < half && c >= half) return half* half + func(n - 1, r, c - half);
	if (r >= half && c < half) return half * half * 2 + func(n - 1, r - half, c);
	if (r >= half && c >= half) return half * half * 3 + func(n - 1, r - half, c - half);
}

int main() {
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
}