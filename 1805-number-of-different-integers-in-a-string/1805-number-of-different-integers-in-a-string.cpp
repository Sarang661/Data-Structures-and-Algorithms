class Solution {
public:
  int numDifferentIntegers(string w) {
    unordered_set<string> s{""};    
    for (int i = 0, j = 0; j <= w.size(); ++j) {
        if (j < w.size() && isdigit(w[j]))
            i += i < j && w[i] == '0';
        else {
            s.insert(w.substr(i, j - i));
            i = j + 1;
        }
    }
    return s.size() - 1;
}
};