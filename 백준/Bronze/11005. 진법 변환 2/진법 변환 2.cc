#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, b, tmp, cnt = 0;
    cin >> n >> b;
    string str;

    while (n > 0) {
        int tmp = n % b;
        if (tmp > 9) {
            tmp = tmp - 10 + 'A';
        }
        else {
            tmp += '0';
        }
        str += tmp;
        n /= b;

    }
    reverse(str.begin(), str.end());    
 
    cout << str;


}