#include <iostream>
using namespace std;

void func(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << "\n";
		return;
	}
	int c = 6 - a - b;
	func(a, c, n - 1);
	cout << a << ' ' << b << "\n";
	func(c, b, n - 1);
	
}
int pow(int n) {
	if (n == 0) return 1;
	return 2 * pow(n - 1);
}
int main() {
	int n;
	cin >> n;
	cout << pow(n) - 1 << "\n";
	func(1, 3, n);

}