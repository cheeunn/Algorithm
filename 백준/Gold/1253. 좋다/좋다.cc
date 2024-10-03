#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int count = 0;
	cin >> n;
	vector<int> A(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	for (int k = 0; k < n; k++) {
		int i = 0, j = n - 1;
		long target = A[k];

		while (i < j) {
			if (A[i] + A[j] == target) {
				if (i != k && j != k) {
					count++;
					break;
				}
				else if (i == k) {
					i++;
				}
				else if (j == k){
					j--;
				}
			}
			else if (A[i] + A[j] > target) {
				j--;
			}
			else {
				i++;
			}
		}
	}
	cout << count << '\n';
}