#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> visited;
void dfs(int j, int n, vector<vector<int>>& computers) {
    visited[j] = 1;
    for(int i = 0; i < n; i++) {
        if(i == j || visited[i] || computers[j][i] == 0) continue;
        visited[i] = 1;
        dfs(i, n, computers);
    }
}
    
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.resize(n, 0);

    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        visited[i] = 1;
        for(int j = 0; j < n; j++) {
            if(i == j || computers[i][j] == 0) continue;
            dfs(j, n, computers);
        }
        answer++;
    }

    return answer;
}