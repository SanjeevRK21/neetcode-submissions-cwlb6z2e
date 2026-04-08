class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;
        int curr;
        int take;
        int notake;
        for(int i = 1; i<n;i++){
            if(n>1){
                take = nums[i]+prev2;
            }
            else{ take = nums[i];}
            notake = prev1;
            curr = max(take,notake);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
