class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> check(nums.begin(),nums.end()); 
        // since set does not save any duplicates
        if(check.size()<nums.size()) return true;
        else return false; 
    }
};