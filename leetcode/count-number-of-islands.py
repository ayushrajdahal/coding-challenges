# Count Number of Islands
# Given a 2D grid grid where '1' represents land and '0' represents water, count and return the number of islands.

# An island is formed by connecting adjacent lands horizontally or vertically and is surrounded by water. You may assume water is surrounding the grid (i.e., all the edges are water).

# Example 1:

# Input: grid = [
#     ["0","1","1","1","0"],
#     ["0","1","0","1","0"],
#     ["1","1","0","0","0"],
#     ["0","0","0","0","0"]
#   ]
# Output: 1
# Example 2:

# Input: grid = [
#     ["1","1","0","0","1"],
#     ["1","1","0","0","1"],
#     ["0","0","1","0","0"],
#     ["0","0","0","1","1"]
#   ]
# Output: 4
# Constraints:

# 1 <= grid.length, grid[i].length <= 100
# grid[i][j] is '0' or '1'.

def numIslands(grid):
    rows = len(grid)
    cols = len(grid[0])

    def lookback(row, col):
        left = [elem[col-1] for elem in grid]
        up = grid[row-1]

        return 1 in left+up

    no_islands = 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == "1": # MODIFIED: used int earlier
                if not lookback(row, col):
                    no_islands += 1
    
    return no_islands

print(numIslands([["1","1","0","0","1"],["1","1","0","0","1"],["0","0","1","0","0"],["0","0","0","1","1"]]))
