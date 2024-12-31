#include <iostream>
using namespace std;

int main() {
    int n, max = 0, sum = 0;
    int score;
    float avg;
    
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> score;
        sum += score;
        if (score > max) max = score;
    }
    avg = float(sum) / max * 100 / n;
    cout << avg;
}