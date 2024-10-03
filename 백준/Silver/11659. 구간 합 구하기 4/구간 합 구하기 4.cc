#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int i;
	int sum_arr[100001];
	cin >> n >> m;

	for(i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		sum_arr[i] = sum_arr[i - 1] + temp;
	}

	for (i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		cout << sum_arr[end] - sum_arr[--start] << '\n';
	}
}