#include <string>
#include <vector>

using namespace std;
void dfs(int h, int w, vector<int>& answer, int br, int yw) {
    if(h * w > br + yw) return;
    if(h * w == br + yw) {
        answer.push_back(w);
        answer.push_back(h);
        return;
    }
    dfs(h, w + 2, answer, br, yw);
    dfs(h + 2, w, answer, br, yw);
}
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int yh = 1; yh * yh <= yellow; yh++) {
        if(yellow % yh) continue;
        int yw = yellow / yh;
        dfs(yh + 2, yw + 2, answer, brown, yellow);
        if(!answer.empty()) break;
    }
    return answer;
}