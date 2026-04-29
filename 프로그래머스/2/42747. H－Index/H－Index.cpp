#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h;
    sort(citations.begin(), citations.end(), greater<>());
    
    for(int i = 0; i < citations.size(); i++) {
        h = min(i + 1, citations[i]);
        answer = max(h, answer); 
    }
    return answer;
}