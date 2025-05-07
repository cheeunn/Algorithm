#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
bool isPrime(int num) {
    if(num < 2) return false;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    set<int> ans;
    
    do {
        for(int i = 1; i <= numbers.length(); i++) {
            string sub = numbers.substr(0, i);
            int temp = stoi(sub);
            if(isPrime(temp)) ans.insert(temp);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    answer = ans.size();
    return answer;
}