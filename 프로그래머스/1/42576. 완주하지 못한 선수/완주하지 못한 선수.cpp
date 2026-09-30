#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> um;
    for(auto name : participant) {
        if(um.find(name) == um.end()) um.insert({name, 1});
        else um[name]++;
    }
    
    for (auto name : completion) {
        um[name]--;
        if (um[name] == 0) um.erase(name);
    }
    
    for(auto it : um) return it.first;
    
}