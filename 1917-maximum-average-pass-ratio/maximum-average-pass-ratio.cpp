#include <bits/stdc++.h>
using namespace std;

struct Node {
    int p, t;
    double gain;
    Node(int _p,int _t):p(_p),t(_t){
        gain=(double)(p+1)/(t+1)-(double)p/t;
    }
    bool operator<(const Node& other) const {
        return gain < other.gain;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& cls, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        priority_queue<Node> pq;
        for (auto &c: cls) pq.emplace(c[0], c[1]);

        while (k--) {
            auto cur = pq.top(); pq.pop();
            pq.emplace(cur.p+1, cur.t+1);
        }

        double sum=0;
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            sum += (double)cur.p / cur.t;
        }
        return sum / cls.size();
    }
};
