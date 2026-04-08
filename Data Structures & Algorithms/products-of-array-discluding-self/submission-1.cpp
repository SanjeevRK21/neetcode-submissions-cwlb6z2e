class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> forw(n,1);
        vector<int> back(n,1);
        vector<int> final(n,1);
        for(int i=0; i< n; i++){
            if(i>0){
            forw[i] = nums[i-1] * forw[i-1];
            back[n-i-1] = back[n-i] * nums[n-i];
            }
        }
        for(int i=0; i<n; i++){
            final[i]= forw[i]*back[i];
        }
        return final;
    }
};
