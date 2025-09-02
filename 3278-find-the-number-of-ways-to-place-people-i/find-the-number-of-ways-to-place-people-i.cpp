class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        int n=p.size(), ans=0;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            if(i==j) continue;
            int x1=p[i][0], y1=p[i][1], x2=p[j][0], y2=p[j][1];
            if(x1<=x2 && y1>=y2){
                bool ok=true;
                for(int k=0;k<n;k++){
                    if(k==i||k==j) continue;
                    int x=p[k][0], y=p[k][1];
                    if(x1<=x && x<=x2 && y2<=y && y<=y1){ ok=false; break; }
                }
                if(ok) ans++;
            }
        }
        return ans;
    }
};
