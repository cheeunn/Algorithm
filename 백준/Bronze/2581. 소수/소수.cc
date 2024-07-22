#include <iostream>

using namespace std;

bool isPrime(int n);
int main() {
	int m, n;
	int sum = 0, min = -1;

	cin >> m >> n;

	for (int i = n; i >= m; i--) {
		if (isPrime(i)) {
			sum += i;
			min = i;
		}
	}
	if (min == -1) {
		cout << min << endl;
	}
	else {
		cout << sum << endl << min << endl;
	}
	return 0;
}

bool isPrime(int n) {
	if (n == 1) return false;
	for (int div = 2; div < n; div++) {
		if (n % div == 0) {
			return false;
		}
	}
	return true;
}