class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int hi = 0, lo = INT_MAX, ans = 0;
        for (auto& n : nums)
            hi = max(hi, n), lo = min(lo, n);
        int bsize = max(int((hi - lo) / (nums.size() - 1)), 1);
        vector<vector<int>> buckets((hi - lo) / bsize + 1, vector<int>());
        for (auto& n : nums)
            buckets[(n - lo) / bsize].push_back(n);
        int currhi = 0;
        for (auto& b : buckets) {
            if (b.empty()) continue;
            int prevhi = currhi ? currhi : b[0], currlo = b[0];
            for (auto& n : b)
                currhi = max(currhi, n), currlo = min(currlo, n);
            ans = max(ans, currlo - prevhi);
        }
        return ans;
    }
};