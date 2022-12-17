#define ll long long int
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        
        ll ans = 0;
        
        stack<string>st;
        
        ll len = tokens.size();
         ll curr1 = 0;
        ll curr2 = 0;
        ll val = 0;
        
        
        for(ll i=0;  i < len; i++){
            
            
            if(tokens[i] == "+"){
                
                 curr1 = stoll(st.top());
                st.pop();
                 curr2 = stoll(st.top());
                 st.pop();
                
                 val = curr1 + curr2;
                st.push(to_string(val));
            }
            
            else if(tokens[i] == "-"){
                  curr1 = stoi(st.top());
                st.pop();
              curr2 = stoi(st.top());
                 st.pop();
                
                val = curr2 - curr1 ;
                st.push(to_string(val));
            }
            else if(tokens[i] == "*"){
                  curr1 = stoll(st.top());
                st.pop();
                curr2 = stoll(st.top());
                 st.pop();
                
                 val = curr2 * curr1 ;
                st.push(to_string(val));
                
            }
            else if(tokens[i] == "/"){
                   curr1 = stoll(st.top());
                st.pop();
             curr2 = stoll(st.top());
                 st.pop();
                
                val = curr2 / curr1 ;
                st.push(to_string(val));
                
            }
            else{
                st.push(tokens[i]);
            }
        }
        
        return stoll(st.top());
    }
};