#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int n = brown / 2 + 2;
    for (int h = 1; h <= n / 2; h++) {
        if (h * (n - h) == brown + yellow) {
            return {n-h, h};
        }
    }
}