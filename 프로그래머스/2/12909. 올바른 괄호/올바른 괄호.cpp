#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> mystack;

    for(char c : s) {
        if(c == '(') mystack.push(c);
        else {
            if(mystack.empty()) return false;
            else {
                mystack.pop();
            }
        }
    }
    if(mystack.empty()) answer = true;
    else answer = false;
    return answer;
}