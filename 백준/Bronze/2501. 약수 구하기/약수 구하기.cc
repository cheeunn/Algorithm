#include <iostream>

using namespace std;

int main() {
	int n, k;
	int arr[10001];
	int cnt = 0;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			arr[cnt + 1] = i;
			cnt++;
		}
	}
	if (cnt < k) {
		cout << 0;
	}
	else {
		cout << arr[k];
	}

}