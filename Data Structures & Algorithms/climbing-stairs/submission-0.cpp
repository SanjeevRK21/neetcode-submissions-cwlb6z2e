class Solution {
public:
    int climbStairs(int n) {
        if(n == 0||n == 1) return n; // see here if number of ways to climb o stairs if 0 then this is correct 
        int prev = 1;
        int prev2 = 1; 
        int curr;
        for(int i = 2; i<= n; i++){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};
