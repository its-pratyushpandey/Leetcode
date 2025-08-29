class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddN = (n + 1) / 2, evenN = n / 2;
        long long oddM = (m + 1) / 2, evenM = m / 2;
        return oddN * evenM + evenN * oddM;
    }
};
