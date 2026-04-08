class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int> (amount+1, -1)); //this will intialize the matrix from dp[0...n-1][0...amount]
        int ans = mini(n-1,amount,coins,dp);
        if(ans >= 1e9){
            return -1;
        }
        else return ans;
    }
    int mini(int n, int amount, vector<int>&coins, vector<vector<int>>&dp){
        int take = 1e9;
        int notake;
        if(dp[n][amount]!=-1) return dp[n][amount];
        if(n==0){
            if(amount%coins[n]==0) return dp[n][amount]=(amount/coins[n]);
            else return dp[n][amount]=1e9;
        }
        if(coins[n] <= amount){
            take = 1 + mini(n,amount-coins[n],coins,dp);
        }
        notake = mini(n-1,amount,coins,dp);
        dp[n][amount] = min(take,notake);
        return dp[n][amount];
    }
};
