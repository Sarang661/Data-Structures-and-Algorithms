class Solution {
public:
  vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
  auto f = [](string& s) {
    return count(begin(s), end(s), *min_element(begin(s), end(s)));
  };
  vector<int> cnt(11, 0), res;
  for (auto& w : words)
    for (int i = f(w) - 1; i >= 0; --i) ++cnt[i];
  for (auto& q : queries) res.push_back(cnt[f(q)]);
  return res;
}
};