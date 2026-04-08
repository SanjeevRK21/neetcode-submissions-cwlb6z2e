class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1) return 1;
        int max = INT_MIN;
        int count = 1;
        sort(nums.begin(),nums.end());
        //multiset<int>num(nums.begin(),nums.end());
        for(int i=0; i<n-1; i++){
            if(nums[i]==nums[i+1]) {
                if(count>max) max = count;
                continue;
            }
            else if(nums[i]==nums[i+1]-1){
                count++;
                if(count>max){
                    max=count;
                }
            }
            else{
                count= 1;
            }
        }
        return max;
    }
};
