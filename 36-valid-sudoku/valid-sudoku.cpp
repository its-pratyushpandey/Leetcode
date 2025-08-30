#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        vector<unordered_set<char>> r(9), c(9), x(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char v = b[i][j];
                if (v == '.') continue;
                if (r[i].count(v) || c[j].count(v) || x[(i/3)*3 + j/3].count(v))
                    return false;
                r[i].insert(v);
                c[j].insert(v);
                x[(i/3)*3 + j/3].insert(v);
            }
        }
        return true;
    }
};
