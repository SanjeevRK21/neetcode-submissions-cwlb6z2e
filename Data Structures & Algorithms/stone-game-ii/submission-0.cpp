#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> suffix;

    int solve(int i, int M) {
        if (i >= n) return 0;
        
        // If we can take all remaining piles
        if (i + 2 * M >= n) 
            return suffix[i];

        if (dp[i][M] != -1) 
            return dp[i][M];

        int result = 0;

        for (int X = 1; X <= 2 * M; X++) {
            result = max(result, 
                         suffix[i] - solve(i + X, max(M, X)));
        }

        return dp[i][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.assign(n, vector<int>(n + 1, -1));
        suffix.assign(n, 0);

        // Build suffix sum
        suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        return solve(0, 1);
    }
};