#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	stack<char> myStack;
	int length = 0;

	while (true) {
		bool isBalanced = true;
		getline(cin, str);
		if (str.compare(".") == 0) break;
		length = str.length();
		for (int i = 0; i < length; i++) {
			char c = str[i];
			if (c == '.') break;
			if (c == '(') {
				myStack.push(c);
			}
			else if (c == '[') {
				myStack.push(c);
			}
			else if (c == ')') {
				if (!myStack.empty() && myStack.top() == '(') {
					myStack.pop();
				}
				else {
					isBalanced = false;
					break;
				}
			}
			else if (c == ']') {
				if (!myStack.empty() && myStack.top() == '[') {
					myStack.pop();
				}
				else {
					isBalanced = false;
					break;
				}
			}
		}
		if (!myStack.empty()) {
			isBalanced = false;
		}
		while (!myStack.empty()) {
			myStack.pop();
		}
		if (isBalanced) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}
	
}