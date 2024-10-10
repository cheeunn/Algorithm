#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    int alphabet[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int min_path = n-1;
    
    for(int curr = 0; curr < n; curr++) {
        answer += alphabet[name[curr] - 'A'];
        int next = curr + 1;
        while(next < n && name[next] == 'A') next++;
        
        int rl = 2 * curr + n - next;
        int lr = 2 * (n - next) + curr;
        min_path = min(min_path, min(rl, lr));
    }
    answer += min_path;
    
    
    return answer;
}