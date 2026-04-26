#include <bits/stdc++.h>

using namespace std;
int n;
int answer;

void dfs(int idx, int sum, vector<int> numbers, int target) {
    if(idx == n) {
        if(sum == target) answer++;
        return;
    }
    dfs(idx+1, sum - numbers[idx], numbers, target);
    dfs(idx+1, sum + numbers[idx], numbers, target);
}

int solution(vector<int> numbers, int target) {
    n = numbers.size();
    dfs(0, 0, numbers, target);
    
    return answer;
}