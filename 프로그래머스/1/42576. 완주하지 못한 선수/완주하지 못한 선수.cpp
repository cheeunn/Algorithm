#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int i;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i]) {
            break;
        }
    }
    if (i == participant.size()) answer = participant[i - 1];
    else answer = participant[i];
    return answer;
}