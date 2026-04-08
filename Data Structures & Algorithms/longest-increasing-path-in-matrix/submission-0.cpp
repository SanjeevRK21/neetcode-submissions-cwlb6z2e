class Solution {
public:
    int rows, cols;
    // Using a vector for dynamic sizing and easy initialization
    vector<vector<int>> memo;

    int dfs(vector<vector<int>>& matrix, int r, int c) {
        if (memo[r][c] != 0) return memo[r][c];

        int res = 1;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] > matrix[r][c]) {
                res = max(res, 1 + dfs(matrix, nr, nc));
            }
        }
        return memo[r][c] = res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        rows = matrix.size();
        cols = matrix[0].size();
        
        // Initialize memo with 0s based on actual matrix size
        memo.assign(rows, vector<int>(cols, 0));

        int maxPath = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maxPath = max(maxPath, dfs(matrix, i, j));
            }
        }
        return maxPath;
    }
};