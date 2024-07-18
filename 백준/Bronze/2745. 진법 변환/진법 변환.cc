#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string str;
    int b, num = 0, new_num;
    cin >> str >> b;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            new_num =  int(str[i] - '0');
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            new_num = int(str[i] - 'A') + 10;
        }
        num += new_num * pow(b, str.length() - 1 - i);
    }

    cout << num;


}