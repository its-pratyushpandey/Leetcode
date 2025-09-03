class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            int xi = points[i][0];
            int yi = points[i][1];
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                int xj = points[j][0];
                int yj = points[j][1];
                if (xj >= xi && yj <= yi && yj > maxY) {
                    ++count;
                    maxY = yj;
                }
            }
        }
        return (int)count;
    }
};