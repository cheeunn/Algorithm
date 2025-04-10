#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int num;
	vector<pair<int, int>> chicken;
	vector<pair<int, int>> house;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num;
			if (num == 1) house.push_back({ i, j });
			if (num == 2) chicken.push_back({ i, j });
		}
	}

	int mn = 0x7F7F7F7F;
	vector<int> brute(chicken.size(), 1);
	fill(brute.begin(), brute.end() - m, 0);
	do {
		int dist = 0;
		for (auto h : house) {
			int temp = 0x7f7f7f7f;
			for (int i = 0; i < chicken.size(); i++) {
				if (brute[i] == 1) {
					temp = min(temp, abs(h.X - chicken[i].X) + abs(h.Y - chicken[i].Y));
				}
			}
			dist += temp;
		}
		mn = min(mn, dist);
	} while (next_permutation(brute.begin(), brute.end()));

	cout << mn;


}