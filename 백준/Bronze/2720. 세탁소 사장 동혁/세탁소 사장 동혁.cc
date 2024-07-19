#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t, money;
	int coin[4] = { 25, 10, 5, 1 };
	cin >> t;
	while (t--) {
		cin >> money;
		for (int i = 0; i < 4; i++) {
			cout << money / coin[i] << " ";
			money %= coin[i];	
		}
	}
}