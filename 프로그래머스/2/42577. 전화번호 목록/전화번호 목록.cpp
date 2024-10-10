#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> map;
    
    for(string& number : phone_book) {
        map[number] = 1;
    }
    
    for(string& number : phone_book) {
        for(int j = 1; j < number.size(); j++) {
            string substr = number.substr(0, j);
            if (map[substr]) {
                return false;
            }
        }
    }
    return answer; 
}