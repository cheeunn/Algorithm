#include <iostream>

using namespace std;

int main() {
	int n, sum, cnt;
	int arr[100000];

	while (true) {
		cin >> n;
		sum = 0;
		cnt = 0;

		if (n == -1) {
			break;
		}

		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				sum += i;
				arr[cnt + 1] = i;
				cnt++;
			}
		}
		if (sum == n) {
			cout << n << " = 1";
			for (int i = 2; i <= cnt; i++) {
				cout << " + " << arr[i];
			}
			cout << endl;
		}
		else {
			cout << n << " is NOT perfect." << endl;
		}
	}

}