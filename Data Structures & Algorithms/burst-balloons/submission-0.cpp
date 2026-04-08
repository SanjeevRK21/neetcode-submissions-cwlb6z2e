class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // Add 1 at beginning and end
        vector<int> arr(n + 2, 1);
        for(int i = 0; i < n; i++)
            arr[i + 1] = nums[i];
        
        int N = n + 2;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        
        // length is distance between left and right
        for(int len = 2; len < N; len++) {
            for(int left = 0; left + len < N; left++) {
                int right = left + len;
                
                for(int k = left + 1; k < right; k++) {
                    dp[left][right] = max(
                        dp[left][right],
                        arr[left] * arr[k] * arr[right]
                        + dp[left][k]
                        + dp[k][right]
                    );
                }
            }
        }
        
        return dp[0][N - 1];
    }
};
