class Solution {
public:
    int solve(int i, int cnt, vector<int>& net, vector<vector<int>>& reqs)
    {
        if(i >= reqs.size()) 
        {
            for(auto x : net) if(x != 0) return 0;
            return cnt;
        }

        //curr req
        int from = reqs[i][0];
        int to = reqs[i][1];

        //take 
        net[from]--;
        net[to]++;
        int take = solve(i+1, cnt+1, net, reqs);
        net[from]++;
        net[to]--;
        //not take
        int notTake = solve(i+1, cnt, net, reqs);

        return max(take, notTake);
    }
    int maximumRequests(int n, vector<vector<int>>& reqs) {
        vector<int> net(n, 0);
        return solve(0, 0, net, reqs);
    }
};