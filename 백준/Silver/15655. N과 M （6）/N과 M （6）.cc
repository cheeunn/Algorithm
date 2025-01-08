#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int inArr[10];
int outArr[10];

void func(int k, int idx) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << outArr[i] << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i < n; i++) {
		outArr[k] = inArr[i];
		func(k + 1, i + 1);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> inArr[i];
	}
	sort(inArr, inArr + n);
	func(0, 0);

}