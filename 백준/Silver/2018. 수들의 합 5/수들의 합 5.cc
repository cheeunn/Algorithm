#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int start_index = 1;
	int end_index = 1;
	int sum = 1, count = 1;
	 
	while (end_index != n) {
		if (sum < n) {
			end_index++;
			sum += end_index;
		}
		else if (sum > n) {
			sum -= start_index;
			start_index++;
		}
		else {
			// sum == n
			count++;
			end_index++;
			sum += end_index;
		}
	}
	cout << count;
}