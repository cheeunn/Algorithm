#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    for(int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    while(true) {
        int priority = q.front().first;
        int idx = q.front().second;
        q.pop();
        if(priority == pq.top()) { // 실행
            answer++;
            pq.pop();
            if(idx == location) return answer;
        } else { // 실행 못했으니까 맨 뒤로
            q.push({priority, idx});
        }
    }
    return answer;
}