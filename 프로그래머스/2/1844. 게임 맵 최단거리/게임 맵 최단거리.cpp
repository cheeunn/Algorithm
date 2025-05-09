#include<vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int visited[102][102];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    for(int i = 0; i < n; i++) {
        fill(visited[i], visited[i] + m, -1);
    }
    visited[0][0] = 1;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(visited[nx][ny] != -1 || maps[nx][ny] == 0) continue;
            visited[nx][ny] = visited[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    answer = visited[n-1][m-1];
    return answer;
}