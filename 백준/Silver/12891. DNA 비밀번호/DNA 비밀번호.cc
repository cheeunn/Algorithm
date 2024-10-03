#include <iostream>
using namespace std;

int checkArr[4];
int myArr[4];
int checkPW = 0;
void add(char c);
void remove(char c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s, p;
	cin >> s >> p;
	int count = 0;
	string A;
	cin >> A;

	for (int i = 0; i < 4; i++) {
		cin >> checkArr[i];
		if (checkArr[i] == 0) {
			checkPW++;
		}
	}

	for (int i = 0; i < p; i++) {
		add(A[i]);
	}
	if (checkPW == 4) {
		count++;
	}

	for (int i = p; i < s; i++) {
		int j = i - p;
		add(A[i]);
		remove(A[j]);
		if (checkPW == 4) {
			count++;
		}
	}

	cout << count << '\n';
}
void add(char c) {
	switch (c) {
	case 'A':
		myArr[0]++;
		if (myArr[0] == checkArr[0]) {
			checkPW++;
		}
		break;
	
	case 'C':
		myArr[1]++;
		if (myArr[1] == checkArr[1]) {
			checkPW++;
		}
		break;
	case 'G':
		myArr[2]++;
		if (myArr[2] == checkArr[2]) {
			checkPW++;
		}
		break;
	case 'T':
		myArr[3]++;
		if (myArr[3] == checkArr[3]) {
			checkPW++;
		}
		break;
	}
}

void remove(char c) {
	switch (c) {
	case 'A':
		if (myArr[0] == checkArr[0]) {
			checkPW--;
		}
		myArr[0]--;
		break;

	case 'C':
		if (myArr[1] == checkArr[1]) {
			checkPW--;
		}
		myArr[1]--;
		break;
	case 'G':
		if (myArr[2] == checkArr[2]) {
			checkPW--;
		}
		myArr[2]--;
		break;
	case 'T':
		if (myArr[3] == checkArr[3]) {
			checkPW--;
		}
		myArr[3]--;
		break;
	}
}
