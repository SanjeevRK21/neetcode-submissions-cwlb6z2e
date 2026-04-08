class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> leavf, leavl;
        int n = nums.size();
        if(n ==1) return nums[0];
        for(int i = 0; i < n; i++){
            if(i!=0) leavf.push_back(nums[i]);
            if(i!=n-1) leavl.push_back(nums[i]);
        }
        return max(house(leavf), house(leavl));
    }

    int house(vector<int>&a){
        int m = a.size();
        int prev1 = a[0];
        int prev2 = 0;
        int curr;
        int take;
        int notake;
        for(int i = 1; i < m; i++){
            if(i>1) take = a[i] + prev2;
            else take = a[i];
            notake = prev1;
            curr = max(take,notake);
            prev2 = prev1;
            prev1 = curr;
        }
        return max(prev1, prev2);
    }
};