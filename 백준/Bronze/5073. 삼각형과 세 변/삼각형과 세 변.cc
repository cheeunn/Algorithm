#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	
	while (true) {
		cin >> a >> b >> c;
		if (!(a || b || c)) break;
		if (a + b - c > 0 && b + c - a > 0 && c + a - b > 0) {
			if (a == b && b == c) {
				cout << "Equilateral" << endl;
			} else if (a == b || b == c | c == a) {
				cout << "Isosceles" << endl;
			} else {
				cout << "Scalene" << endl;
			}
		} else {
			cout << "Invalid" << endl;
		}
	}
}

