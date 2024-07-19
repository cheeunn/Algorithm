#include <iostream>

using namespace std;

int main() {
	int a, b, v;
	int tree = 0, day;
	cin >> a >> b >> v;

	v -= a;
	day = v / (a - b);

	if (v % (a - b)) {
		day += 2;
	}
	else {
		day += 1;
	}
	
	cout << day;
}