#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    
    int max_day = 0;
    int cnt = 1;
    
    for(int i = 0; i < n; i++) {
        int day = (99 - progresses[i] + speeds[i]) / speeds[i];
        
        if(day > max_day) {
            answer.push_back(1);
            max_day = day;
        } else {
            // day <= max_day
            answer.back()++;
        }
    }

    return answer;
}