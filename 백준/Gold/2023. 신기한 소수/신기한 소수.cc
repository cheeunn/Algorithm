#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n);
void DFS(int num, int digit);
static int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

	
}

bool isPrime(int n) {
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void DFS(int num, int digit) {
	int odds[5] = { 1, 3, 5, 7, 9 };
	int new_num;

	if (digit == n) {
		if (isPrime(num)) {
			cout << num << '\n';
		}
		return;
	}
	for (int i : odds) {
		new_num = num * 10 + i;
		if (isPrime(new_num)) {
			DFS(new_num, digit + 1);
		}
	}


}