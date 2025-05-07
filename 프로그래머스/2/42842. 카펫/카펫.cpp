#include <string>
#include <vector>

using namespace std;
vector<int> solution(int brown, int yellow) {
    int wh = brown / 2 + 2;
    int h = 3;
    int w = wh - h;
    while(w >= h){
        if(w * h == brown + yellow) break;
        w--; h++;
    }
    return vector<int>{w, h};
}