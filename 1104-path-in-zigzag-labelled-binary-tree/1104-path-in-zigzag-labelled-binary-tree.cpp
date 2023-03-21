class Solution {
public:
 vector<int> pathInZigZagTree(int label) {
    vector<int> res;
    for (; label > 0; label /= 2)
        res.push_back(label);
    for (int i = res.size() - 1; i >= 0; --i)
        if (i % 2 == 1)
            res[i] = (1 << (res.size() - i - 1)) * 3 - res[i] - 1;
    return vector<int>(rbegin(res), rend(res));
}
};