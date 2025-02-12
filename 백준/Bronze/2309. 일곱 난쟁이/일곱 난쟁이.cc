#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int heights[10];
    int sum = 0;
    int two;
    
    for(int i = 0; i < 9; i++) {
        cin >> heights[i];
        sum += heights[i];
    }
    sort(heights, heights + 9);
    int x = sum - 100;
    int spy[2];
    for(int i = 0; i < 9; i++) {
        for(int j = i + 1; j < 9; j++) {
            if(heights[i] + heights[j] == x) {
                spy[0] = heights[i];
                spy[1] = heights[j];
            }
        }
    }
    for(int i = 0; i < 9; i++) {
        if(heights[i] == spy[0] || heights[i] == spy[1]) continue;
        cout << heights[i] << "\n";
    }
}