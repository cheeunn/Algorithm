#include <iostream>

using namespace std;

int main() {
    int n;
    int x, y;
    int east = -10000, west = 10000;
    int south = 10000, north = -10000;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x < west) {
            west = x;
        }
        if (x > east) {
            east = x;
        }
        if(y < south) {
            south = y;
        }
        if (y > north) {
            north = y;
        }
    }
    int area = (north - south) * (east - west);
    cout << area;
}