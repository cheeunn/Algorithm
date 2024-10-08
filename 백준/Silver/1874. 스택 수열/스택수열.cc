#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> A(n, 0);
	vector<char> resultV;
	stack<int> myStack;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	int num = 1;
	bool result = true;

	for (int& a : A) {
		if (a >= num) {
			while (a >= num) {
				myStack.push(num++);
				resultV.push_back('+');
			}
			myStack.pop();
			resultV.push_back('-');
		}
		else {
			int n = myStack.top();
			if (a < n) {
				result = false;
				cout << "NO";
				break;
			}
			else { 
				myStack.pop();
				resultV.push_back('-');
			}
		}
	}
	if (result) {
		for (char& v : resultV) {
			cout << v << '\n';
		}
	}
}
