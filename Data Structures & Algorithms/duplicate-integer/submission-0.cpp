class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        bool f = false;
        sort(nums.begin(),nums.end());
        for(int i = 0; i< n/2; i++){
            if(nums[i]==nums[i+1] || nums[n-i-1] == nums[n-i-2]){
                f = true;
                break;
            }
        }
        return f;
    }
};