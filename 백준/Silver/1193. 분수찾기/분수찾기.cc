#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int x, i = 0, sum = 0;
	int denominator = 1, numerator = 1;
	cin >> x;

	while (true) {
		sum += ++i;
		if (sum >= x) {
			sum -= i++;
			break;
		}
	}
	if (i % 2) { // odd -> ascending
		denominator = x - sum;
		numerator = i - denominator;
	} else { // even -> descending
		denominator = i - (x - sum);
		numerator = i - denominator;
	}

	cout << denominator << "/" << numerator;

	
}