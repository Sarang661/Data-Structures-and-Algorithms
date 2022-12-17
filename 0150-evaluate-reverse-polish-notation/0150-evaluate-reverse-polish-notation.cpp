#define ll long long int
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        
        ll ans = 0;
        
        stack<string>st;
        
        ll len = tokens.size();
        
        for(ll i=0;  i < len; i++){
            
            
            if(tokens[i] == "+"){
                
                ll curr1 = stoll(st.top());
                st.pop();
                ll curr2 = stoll(st.top());
                 st.pop();
                
                ll val = curr1 + curr2;
                st.push(to_string(val));
            }
            
            else if(tokens[i] == "-"){
                 ll curr1 = stoi(st.top());
                st.pop();
              ll curr2 = stoi(st.top());
                 st.pop();
                
                ll val = curr2 - curr1 ;
                st.push(to_string(val));
            }
            else if(tokens[i] == "*"){
                 ll curr1 = stoll(st.top());
                st.pop();
                ll curr2 = stoll(st.top());
                 st.pop();
                
                ll val = curr2 * curr1 ;
                st.push(to_string(val));
                
            }
            else if(tokens[i] == "/"){
                  ll curr1 = stoll(st.top());
                st.pop();
            ll curr2 = stoll(st.top());
                 st.pop();
                
                ll val = curr2 / curr1 ;
                st.push(to_string(val));
                
            }
            else{
                st.push(tokens[i]);
            }
        }
        
        return stoll(st.top());
    }
};