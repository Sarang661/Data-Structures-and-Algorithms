class Solution {
public:
   int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> m;
    for (auto n : nums)
        ++m[n];
    return accumulate(begin(m), end(m), 0, [](int sum, const auto &p) {
        return sum + (p.second == 1 ? p.first : 0);
    });
}
};