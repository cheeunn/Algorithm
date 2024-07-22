#include <iostream>

using namespace std;

int main() {
	int n, rooms = 1;
	int prev = 1, next;
	cin >> n;

	while (true) {
		if (n == 1) break;
		next = prev + 6 * rooms;
		if (n > prev && n <= next) {
			rooms++;
			break;
		}
		rooms++;
		prev = next;
	}
	cout << rooms;
}

