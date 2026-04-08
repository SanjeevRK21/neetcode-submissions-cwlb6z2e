class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> check;
        for(int x : nums){
            if(check.count(x)){
                return true;
            }
            check.insert(x);
        }
        return false;
    }
};