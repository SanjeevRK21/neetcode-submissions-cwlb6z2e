class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        row = len(grid)
        col = len(grid[0])
        isl = 0

        def dfs(a,b):
            if a < 0 or b < 0 or a >= row or b >= col or grid[a][b] == "0":
                return 
            
            grid[a][b] = "0"

            dfs(a+1,b)
            dfs(a,b+1)
            dfs(a-1,b)
            dfs(a,b-1)

        for a in range(row):
            for b in range(col):
                if grid[a][b] =="1":
                    isl +=1
                    dfs(a,b)

        return isl
    
        