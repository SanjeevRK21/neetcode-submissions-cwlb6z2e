from collections import defaultdict
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        row = defaultdict(set)
        col = defaultdict(set)
        boxes = defaultdict(set)

        for r in range(9):
            for c in range(9):
                num = board[r][c]

                if num == ".":
                    continue 

                box = (r//3,c//3)

                if num in row[r] or num in col[c] or num in boxes[box]:
                    return False

                row[r].add(num)
                col[c].add(num)
                boxes[box].add(num)

        return True