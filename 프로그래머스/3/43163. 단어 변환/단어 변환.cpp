#include <string>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int visited[52];

bool possible(string from, string to) {
    int cnt = 0;
    for(int i = 0; i < from.size(); i++) {
        if(from[i] != to[i]) cnt++;
    }
    
    if(cnt == 1) return true;
    else return false;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> Q;
    string temp;
    int num;
    Q.push({begin, 0});
    while(!Q.empty()) {
        temp = Q.front().first;
        num = Q.front().second;
        Q.pop();
        if(temp == target) {
            answer = num;
            break;
        }
        for(int i = 0; i < words.size(); i++) {
            if(visited[i]) continue;
            if(possible(temp, words[i])) {
                visited[i] = 1;
                Q.push({words[i], num + 1});
            }
        }
    }
    return answer;
}