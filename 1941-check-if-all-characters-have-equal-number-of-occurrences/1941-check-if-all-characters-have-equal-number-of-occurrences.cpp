class Solution {
public:
    bool areOccurrencesEqual(string s){
        vector<int> cnt(26,0);
		//store freq of each char of s in cnt vector
        for(char c : s) cnt[c-'a']++;
		//num contains the freq of first char in s
        int num=cnt[s[0]-'a'];
		//traversing the cnt vector
		//freq in cnt must be either 0(char is not present in s) or num(if char present in s
		//than its freq should be same as that of other chars of string) else we will return false
        for(int i: cnt){
            if(i!=num and i!=0) return false;
        }
        return true;
    }
};