#include <iostream>

using namespace std;

int main() {
    int x[3] = {0, };
    int y[3] = {0, };
    int rx, ry;
    
    for(int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }
    rx = x[0] == x[1] ? x[2] : x[0] == x[2] ? x[1] : x[0];
    ry = y[0] == y[1] ? y[2] : y[0] == y[2] ? y[1] : y[0];
    
    cout << rx << " " << ry;
    
        
}