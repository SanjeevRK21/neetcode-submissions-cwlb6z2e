class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if((n==0) || (n==1)) return n; 
        sort(nums.begin(),nums.end());
        int max = INT_MIN;
        int count = 1;
        for(int i=0; i<n-1; i++){
            if((nums[i] == (nums[i+1]-1)) || (nums[i]==(nums[i+1]))){
                if(nums[i]==nums[i+1]-1){
                    count++;
                }
                if(count>max) max = count;
                continue;
            }
            else{
                count = 1;
                if(count>max) max = count;
            }
        }
        return max;

    }
};