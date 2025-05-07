#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> first{1, 2, 3, 4, 5};
    vector<int> second{2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int list[3] = {0, 0, 0};
    
    int l = answers.size();
    for(int i = 0; i < l; i++) {
        if(answers[i] == first[i % 5]) list[0]++;
        if(answers[i] == second[i % 8]) list[1]++;
        if(answers[i] == third[i % 10]) list[2]++;
    }
    int mx = 0;
    for(int a : list) {
        mx = max(mx, a);
    }
    for(int i = 0; i < 3; i++) {
        if (list[i] == mx) answer.push_back(i+1);
    }
    return answer;
}