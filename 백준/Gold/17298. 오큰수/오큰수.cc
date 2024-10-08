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
	vector<int> A(n);
	vector<int> NGE(n, -1);
	stack<int> myStack;
	

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	myStack.push(0);

	for (int i = 1; i < n; i++) {
		while (!myStack.empty() && A[myStack.top()] < A[i]) {
			// A[i]는 오큰수
			NGE[myStack.top()] = A[i];
			myStack.pop();
		}
		myStack.push(i);
	}
	
	while (!myStack.empty()) {
		int top = myStack.top();
		NGE[top] = -1;
		myStack.pop();
	}

	for (int& nge : NGE) {
		cout << nge << " ";
	}
}