#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    int alphabet[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int min_path = n-1;
    
    for(int x = 0; x < n; x++) {
        answer += alphabet[name[x] - 'A'];
        int y = x + 1;
        
        while(name[y] == 'A' && y < n) y++; // x 오른쪽 A 아닌 y 찾기

        // int rl = 2 * y - x + n - y;
        //int lr = 2 * (n - y) + x;
        min_path = min(min_path, x + n - y + min(x, n- y));
    }
    answer += min_path;
    
    
    return answer;
}