#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h;
    sort(citations.begin(), citations.end(), greater<>());
    
    for(int i = 0; i < citations.size(); i++) {
        if(citations[i] < i + 1) {
            return i;
        }
    }
    return citations.size();
}