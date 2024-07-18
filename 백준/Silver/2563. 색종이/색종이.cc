#include <iostream>

using namespace std;

int main() {
    int paper[101][101] = { 0, };
    int n, x, y;
    int area = 0;

    cin >> n;
    
    while (n--) {
        cin >> x >> y;
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                paper[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (paper[i][j]) area++;
        }
    }

    cout << area;

}