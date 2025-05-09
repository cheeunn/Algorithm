#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int tries = 100;
int visited[52];
bool convertable(string from, string to) {
    int cnt = 0;
    for(int i = 0; i < from.size(); i++) {
        if(from[i] != to[i]) cnt++;
    }
    if(cnt == 1) return true;
    return false;
}
void dfs(string cur, string target, vector<string> words, int count) {
    if(cur == target) {
        tries = min(tries, count);
        return;
    }
    for(int i = 0; i < words.size(); i++) {
        if(visited[i] != 0 || convertable(cur, words[i]) == false) continue;
        visited[i] = 1;
        dfs(words[i], target, words, count + 1);
        visited[i] = 0;
    }
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    fill(visited, visited + words.size(), 0);
    dfs(begin, target, words, 0);
    answer = tries;
    if(answer == 100) answer = 0;
    return answer;
}