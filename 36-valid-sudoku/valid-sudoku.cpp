#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        bool row[9][9] = {false}, col[9][9] = {false}, box[9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (b[i][j] == '.') continue;
                int num = b[i][j] - '1';
                int k = (i / 3) * 3 + j / 3;
                if (row[i][num] || col[j][num] || box[k][num]) return false;
                row[i][num] = col[j][num] = box[k][num] = true;
            }
        }
        return true;
    }
};
