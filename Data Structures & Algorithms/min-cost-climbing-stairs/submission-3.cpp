class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev1 = cost[0];
        int prev2 = 0;
        int curr;
        int os, ss;
        for(int i = 1; i<n; i++){
            os = cost[i]+prev1;
            if(i>1){
             ss = cost[i]+prev2;
            }
            else{ss = cost[i];}
            curr = min(os,ss);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(curr,prev2); // this is done so that the person in the last step or the 2nd last step can jump to the top and here prev2 has taken the value of prev 1, thats why its the min(curr, prev2). 
    }
};
