#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(31, 0);
    
    for(int& lost_idx : lost) {
        students[lost_idx] = -1;
    }
    for(int& reserve_idx : reserve) {
        students[reserve_idx]++;
    }
    
    for(int i = 1; i <= n; i++) {
        if(students[i] == -1) {
            if(students[i - 1] == 1) {
                students[i - 1] = 0;
                students[i] = 0;
            } else {
                if(i < n && students[i + 1] == 1 ){
                    students[i + 1] = 0;
                    students[i] = 0;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if (students[i] != -1) {
            answer++;
        }
    }
    
    return answer;
}