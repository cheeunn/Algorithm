#include <iostream>

using namespace std;

 int main() {
	int arr[3];
	int max = 0, sum = 0;

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
		sum += arr[i];
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	sum -= max;
	if (max >= sum) {
		max = sum - 1;
	}
	cout << sum + max;
}

