class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pref = 1;
        int suff = 1;
        int ans = -1e9;
        int maxcount = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(pref==0) pref = 1; // for o cases
            if(suff==0) suff = 1; // for 0 cases
            pref = pref * nums[i];
            suff =  suff * nums[n-i-1];
            if(max(pref,suff)>ans){
                ans = max(pref,suff);
                count++;
                maxcount = max(count, maxcount);
            }
        }
        return ans; 
    }
};
