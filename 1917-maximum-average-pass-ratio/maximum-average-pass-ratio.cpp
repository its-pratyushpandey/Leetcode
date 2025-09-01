#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double g(int x,int y){return (double)(x+1)/(y+1)-(double)x/y;}
    double maxAverageRatio(vector<vector<int>>& a,int m){
        priority_queue<tuple<double,int,int>> h;
        for(auto &u:a) h.push({g(u[0],u[1]),u[0],u[1]});
        while(m--){
            auto [d,x,y]=h.top(); h.pop();
            h.push({g(x+1,y+1),x+1,y+1});
        }
        double res=0;
        while(!h.empty()){
            auto [d,x,y]=h.top(); h.pop();
            res+=(double)x/y;
        }
        return res/a.size();
    }
};
