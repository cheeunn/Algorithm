#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> score(3, 0);
    vector<int> answer;
    vector<vector<int>> v;
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> v3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    
    for(int i = 0; i < answers.size(); i++) {
        for (int j = 0; j < 3; j++){
            if (answers[i] == v[j][i % v[j].size()]) score[j]++;
        }
    }
    
    auto mx = max_element(score.begin(), score.end());
    for(int i = 0; i < 3; i++) {
        if (score[i] == *mx) answer.push_back(i + 1);
    }
    
    return answer;
}