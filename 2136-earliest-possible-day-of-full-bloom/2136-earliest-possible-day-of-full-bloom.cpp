
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>plantGrowth;
        
        int total_size = plantTime.size();
        
        for(int index = 0;index < total_size;index++){
            plantGrowth.push_back({growTime[index], plantTime[index]});
        }
        sort(plantGrowth.begin(), plantGrowth.end(),greater<pair<int,int>>());
        
        int totalTime = plantGrowth[0].first + plantGrowth[0].second ;
        int time = 0;
        int maxi = 0;
        for(int index = 0;index < total_size; index ++){
            // totalTime = max( totalTime, totalTime - plantGrowth[index-1].first +  plantGrowth[index].first+plantGrowth[index].second );
            time+=plantGrowth[index].second;
            maxi = max(maxi,time+plantGrowth[index].first);
             
        }
       
        
        // return totalTime;
        return maxi;
    }
};

// 1 5  2 3  