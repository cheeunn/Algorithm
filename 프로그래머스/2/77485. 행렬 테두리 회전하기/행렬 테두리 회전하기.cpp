#include <string>
#include <vector>
#include<algorithm>

using namespace std;
int rotate(vector<int> query);
int matrix[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= columns; j++) {
            matrix[i][j] = (i - 1) * columns + j;
        }
    }
    
    for(vector<int>& query : queries) {
        answer.push_back(rotate(query));
    }
    return answer;
}

int rotate(vector<int> query) {
    int x1 = query[0], y1 = query[1];
    int x2 = query[2], y2 = query[3];
    int p = matrix[x1][y1];
    int minimum = p;
    
    
    // left
    for(int i = 0; i < x2 - x1; i++) {
        matrix[x1 + i][y1] = matrix[x1 + i + 1][y1];
        minimum = min(minimum, matrix[x1 + i][y1]);
    }
    // lower
    for(int i = 0; i < y2 - y1; i++) {
        matrix[x2][y1 + i] = matrix[x2][y1 + i +1];
        minimum = min(minimum, matrix[x2][y1 + i]);
    }
    // right
    for(int i = 0; i < x2 - x1; i++) {
        matrix[x2 - i][y2] = matrix[x2 - i -1][y2];
        minimum = min(minimum, matrix[x2 - i][y2]);
    }
    // upper
    for(int i = 0; i < y2 - y1; i++) {
        matrix[x1][y2 - i] = matrix[x1][y2 - i - 1];
        minimum = min(minimum, matrix[x1][y2 - i]);
    }
    matrix[x1][y1+1] = p;
    
    
    return minimum;
}