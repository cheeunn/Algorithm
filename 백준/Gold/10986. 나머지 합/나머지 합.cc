#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	long answer = 0;
	vector<long> S(n);
	vector<long> C(m);
	cin >> S[0];


	for (int i = 1; i < n; i++) {
		int temp;
		cin >> temp;
		S[i] = S[i - 1] + temp;
	}

	for (int i = 0; i < n; i++) {
		int remainder;
		remainder = S[i] % m;
		if (remainder == 0) {
			answer++;
		}
		C[remainder]++;
	}

	for (int i = 0; i < m; i++) {
		if (C[i] > 1) {
			answer += C[i] * (C[i] - 1) / 2;
		}
	}

	cout << answer << "\n";


	

}