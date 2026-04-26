#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> signals) {
    int answer = 0;
    int n = signals.size();
    int lcd = 1;
    for(auto s: signals) {
        int T = s[0] + s[1] + s[2];
        lcd = lcd / gcd(lcd, T) * T;
    }
    
    for(int t = 1; t < lcd; t++) {
        bool all_yellow = true;
        for(int i = 0; i < n; i++) {
            int G = signals[i][0], Y = signals[i][1], R = signals[i][2];
            int T = G + Y + R;
            if(t % T <= G || t % T > G + Y) {
                all_yellow = false;
                break;
            }
        }
        if(all_yellow) return t;
    }
    return -1;
}