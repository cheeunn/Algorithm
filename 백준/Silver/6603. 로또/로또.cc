#include<iostream>
using namespace std;

int k;
int s[12];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) cin >> s[i];
		
		for (int a = 0; a < k; a++) for (int b = a + 1; b < k; b++)
			for (int c = b + 1; c < k; c++) for (int d = c + 1; d < k; d++)
				for (int e = d + 1; e < k; e++) for (int f = e + 1; f < k; f++) {
					cout << s[a] << " " << s[b] << " " 
						<< s[c] << " " << s[d] << " " 
						<< s[e] << " " << s[f] << "\n";

				}
		cout << "\n";
	}
}