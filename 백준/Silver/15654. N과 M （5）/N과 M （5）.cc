#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int inArr[10];
int outArr[10];
bool isused[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << outArr[i] << ' ';
		}
		cout << "\n";
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			outArr[k] = inArr[i];
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
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
	func(0);

}