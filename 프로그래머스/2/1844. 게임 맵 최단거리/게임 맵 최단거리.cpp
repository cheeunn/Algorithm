#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited[102][102];
int n, m;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size(), m = maps[0].size();
    queue<pair<int, int>> Q;
    for(int i = 0; i < n; i++) {
        fill(visited[i], visited[i] + m, -1);
    }
    
    visited[0][0] = 1;
    Q.push({0, 0});
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(maps[nx][ny] == 0 || visited[nx][ny] != -1) continue;
            visited[nx][ny] = visited[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    answer = visited[n-1][m-1];
    return answer;
}