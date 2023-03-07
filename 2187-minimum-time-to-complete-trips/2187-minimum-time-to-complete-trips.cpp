class Solution {
private:
    
    bool poss(long long mid, vector<int>&time, long num){
        
        long total = 0;
        
        for(int index = 0; index < time.size(); index++){
            
            total+=(mid/time[index]);
        }
        
        return total >= num;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        sort(time.begin(), time.end());
        
        long long low = 1;
        long long high = (long)time[time.size()-1]*(long)totalTrips;
        
        while(low<high){
            
            long long mid = low + (high - low)/2;
            
            if(poss(mid, time, totalTrips)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        
        return low;
    }
};