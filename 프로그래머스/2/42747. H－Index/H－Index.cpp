#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.rbegin(), citations.rend());
    int tmp;
    
    for(int i = 0; i < citations.size(); i++) {
        tmp = min(i + 1, citations[i]);
        answer = max(answer, tmp);
    }
    
    return answer;
}