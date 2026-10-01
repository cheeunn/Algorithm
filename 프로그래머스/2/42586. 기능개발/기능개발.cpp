#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    for(int i = 0; i < n; i++) {
        progresses[i] = (99 - progresses[i] + speeds[i]) / speeds[i];
    }
    
    int max_day = progresses[0];
    int cnt = 1;
    
    for(int i = 1; i < n; i++) {
        if(progresses[i] <= max_day) cnt++;
        else {
            max_day = progresses[i];
            answer.push_back(cnt);
            cnt = 1;
        }
    }
    
    answer.push_back(cnt);
    return answer;
}