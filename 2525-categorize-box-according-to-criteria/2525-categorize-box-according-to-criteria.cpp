#define ll long long int
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool b = false;
        bool h = false;
        
        ll v = (ll)length*(ll)width*(ll)height;
        if(((height>=1e4) || (width>=1e4) || (length>=1e4)) || v>=1e9){
            b=true;
        }
        if(mass>=100){
            h=true;
        }
        if(b && h){
            return "Both";
        }
        
          if(b==false  && h==false){
            return "Neither";
        }
        if(b){
            return "Bulky";
        }
        if(h){
return "Heavy";}
        
        return "t";
    }
};