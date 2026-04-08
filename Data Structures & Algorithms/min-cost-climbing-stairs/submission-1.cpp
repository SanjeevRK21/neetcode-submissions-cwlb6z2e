class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev1 = cost[1];
        int prev2 = cost[0];
        int curr;
        for(int i = 2; i<n; i++){
            int os = cost[i]+prev1;
            int ss = cost[i]+prev2;
            curr = min(os,ss);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(curr,prev2);
    }
};
