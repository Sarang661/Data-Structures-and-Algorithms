class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int index1 = 0;
        int index2 = 0;
        int size1 = word1.size();
        int size2 = word2.size();
        int p1 = 0;
        int p2 = 0;
        while(index1<size1 && index2<size2){
          
            while(p1<word1[index1].size() && p2<word2[index2].size()){
                if(word1[index1][p1]!=word2[index2][p2]){
                    return false;
                }
                p1++;
                p2++;
            }
            if(p1==word1[index1].size()){
                index1++;
                p1=0;
            }
              if(p2==word2[index2].size()){
                index2++;
                  p2=0;
            }
        }
        
        //A -> ABC DE F
        // B -> ABC D
        if(index1<size1 || index2<size2){
            return false;
        }
        return true;
    }
};