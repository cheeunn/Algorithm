#include <iostream>

using namespace std;

int main() {
	int n;
	int num, cnt = 0;
	bool isprime;
	cin >> n;

	while (n--) {
		cin >> num;
		isprime = true;
		if (num == 1) continue;
		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				isprime = false;
				break;
			}
		}
		if (isprime) {
			cnt++;
		}
	}
	cout << cnt;
}