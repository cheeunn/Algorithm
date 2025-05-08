#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int parents[102];

bool compare (vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int getParent(int node) {
    if(parents[node] == node) return node;
    return parents[node] = getParent(parents[node]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i = 0; i < n; i++) {
        parents[i] = i;
    }
    sort(costs.begin(), costs.end(), compare);
    
    for(int i = 0; i < costs.size(); i++) {
        int st = getParent(costs[i][0]);
        int en = getParent(costs[i][1]);
        int cost = costs[i][2];
        if(st != en) {
            parents[en]  = st;
            answer += cost;
        }
    }
    
    return answer;
}