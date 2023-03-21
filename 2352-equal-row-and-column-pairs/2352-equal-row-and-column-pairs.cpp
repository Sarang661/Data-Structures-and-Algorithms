class Solution {
public:
  int equalPairs(vector<vector<int>>& g) {
    int res = 0, n = g.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int k = 0;
            while (k < n && g[i][k] == g[k][j])
                ++k;
            res += k == n;
        }
    return res;
}
};