class Solution {
private:
    string curr = "";
  void findUniqueStrings(vector<string>&arr,int &maxLen,int index){
      if(index == arr.size()){
          vector<int>charFreq(26,0);
          
          for(int i=0;i<curr.size();i++){
              charFreq[curr[i]-'a']++;
          }
          
          for(int i=0;i<26;i++){
              if(charFreq[i]>1){
                  return;
              }
          }
         
          maxLen = max(maxLen,(int)curr.size());
          return;
      }
        curr+=arr[index];
        findUniqueStrings(arr,maxLen,index+1);
        curr.erase(curr.size()-arr[index].size());
        findUniqueStrings(arr,maxLen,index+1);
    }
public:
    int maxLength(vector<string>& arr) {
        int totalStrings = 0;
        findUniqueStrings(arr,totalStrings,0);
        
        return totalStrings;
    }
};