class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>k(n);
        for(int i = 0; i< n; i++){
            k[i] =  prefix(nums, i)*postfix(nums, i);
        }
        return k;
    }
    
    int prefix(vector<int>& nums, int i){
        int prod = 1;
        if(i == 0) return 1;
        for(int j =0; j<i; j++){
            prod = prod * nums[j];
        }
        return prod;
    }

    int postfix(vector<int>& nums, int i){
        int n = nums.size();
        int prod = 1;
        if(i == n-1) return 1;
        for(int j = i+1; j<n; j++){
            prod = prod* nums[j];
        }
        return prod;

    }
};
