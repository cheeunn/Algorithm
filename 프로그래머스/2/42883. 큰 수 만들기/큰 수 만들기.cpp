#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int cnt = 0;
    int max_idx = -1; 
    
    for(int i = 0; i < number.size() - k; i++) {
        char max = '0';
        for(int j = max_idx + 1; j <= i + k; j++) {
            if(number[j] > max) {
                max = number[j];
                max_idx = j;
            }
        }
        answer += max;
    } 
    
    
    return answer;
}