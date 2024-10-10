#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    
    for(auto item : clothes) {
        m[item[1]]++;
    }
    for(auto p: m) {
        answer *= p.second + 1;
    }
    answer--;
    
    return answer;
}