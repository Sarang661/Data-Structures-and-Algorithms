class Solution {
public:
  vector<vector<int>> pref2d(vector<vector<int>> &v, int m, int n) {
    vector<vector<int>> p(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            p[i + 1][j + 1] = v[i][j] + p[i + 1][j] + p[i][j + 1] - p[i][j];
    return p;
}
int sum2d(vector<vector<int>> &p, int c1, int r1, int c2, int r2) {
    return p[c2 + 1][r2 + 1] + p[c1][r1] - p[c1][r2 + 1] - p[c2 + 1][r1];
}
bool possibleToStamp(vector<vector<int>>& g, int h, int w) {
    int m = g.size(), n = g[0].size();
    vector<vector<int>> stamp(m, vector<int>(n));
    auto pref = pref2d(g, m, n);
    for (int i = h - 1; i < m; ++i)
        for (int j = w - 1; j < n; ++j)
            stamp[i][j] = sum2d(pref, i - h + 1, j - w + 1, i, j) == 0;
    auto pref2 = pref2d(stamp, m, n);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (g[i][j] == 0 && sum2d(pref2, i, j, min(m - 1, i + h - 1), min(n - 1, j + w - 1)) == 0)
                return false;
    return true;
}
};