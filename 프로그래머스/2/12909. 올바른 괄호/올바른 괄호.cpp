#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    for(auto c: s) {
        if (c == '(') st.push(c);
        else {
            if(st.empty()) return false;
            st.pop();
        }
    }
    if (st.empty()) return true;
    else return false;
}  