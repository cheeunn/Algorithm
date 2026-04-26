#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> signals) {
    int answer = 0;
    int len = signals.size();
    int cycle;
    int lcd = signals[0][0] + signals[0][1] + signals[0][2];
    
    for(int i = 1; i < len; i++) {
        lcd = lcd * (signals[i][0] + signals[i][1] + signals[i][2]) / gcd(lcd, (signals[i][0] 
              + signals[i][1] + signals[i][2]));
    }
    
    for (int cur = 1; cur <= lcd; cur++) {
        bool isYellow = true;
        for(int i = 0; i < len; i++) {
            cycle = signals[i][0] + signals[i][1] + signals[i][2];
            if (cur % cycle > signals[i][0] && cur % cycle <= signals[i][0] + signals[i][1]) continue;
            isYellow = false;
            break;
        }
        if(isYellow) return cur;
    }
    return -1;
}