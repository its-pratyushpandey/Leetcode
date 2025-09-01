#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double f(int a, int b) {
        return (double)(a+1)/(b+1) - (double)a/b;
    }
    double maxAverageRatio(vector<vector<int>>& v, int k) {
        priority_queue<tuple<double,int,int>> q;
        for (auto &x : v) q.push({f(x[0],x[1]),x[0],x[1]});
        while (k--) {
            auto [g,a,b] = q.top(); q.pop();
            q.push({f(a+1,b+1),a+1,b+1});
        }
        double s=0;
        while (!q.empty()) {
            auto [g,a,b] = q.top(); q.pop();
            s += (double)a/b;
        }
        return s/v.size();
    }
};
