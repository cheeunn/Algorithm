#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> comm;
    
    for (auto comm : commands) {
        vector<int> arr;
        int i = comm[0];
        int j = comm[1];
        int k = comm[2];
        int ans;
        
        for(int n = 0; n < j - i + 1; n++) {
            arr.push_back(array[i - 1 + n]); 
        }
        
        sort(arr.begin(), arr.end());
        ans = arr[k -1];
        answer.push_back(ans);        
    }
    return answer;
}