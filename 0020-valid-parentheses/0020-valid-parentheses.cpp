class Solution {
public:
    bool isValid(string s) {
        
        stack<char>st;
        
        for(int index = 0; index < s.size(); index++){
            
            if(s[index] == '{' || s[index]=='(' || s[index] == '['){
                st.push(s[index]);
            }
            else{
                if(st.size() == 0){
                    return false;
                }
                else if(s[index] == ')' && st.top()=='('){
                    st.pop();
                }
                else if(s[index] == '}' && st.top()=='{'){
                    st.pop();
                }
                else if(s[index] == ']' && st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
   
        }
        
        return st.size()== 0;
    }
};