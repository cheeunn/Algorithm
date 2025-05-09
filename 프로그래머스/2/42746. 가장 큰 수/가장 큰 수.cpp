#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int num : numbers) v.push_back(to_string(num));
    sort(v.begin(), v.end(), [](string s1, string s2) {
        return s1 + s2 > s2 + s1;
    });
    for(string s : v) answer += s;
    if(answer == string(answer.length(), '0')) answer = '0';
    return answer;
}