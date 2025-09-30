
// https://leetcode.com/problems/minimum-path-sum
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (i == 0 && j == 0) 
                    continue;
                else if (i == 0)
                    grid[i][j] += grid[i][j - 1];
                else if (j == 0) 
                    grid[i][j] += grid[i - 1][j];
                else
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};

int main() 
{
    Solution sol;

    vector<vector<int>> grid1 = {{1,3,1},{1,5,1},{4,2,1}};
    cout << "Example1 -> Expected 7, Got: " << sol.minPathSum(grid1) << "\n";

    vector<vector<int>> grid2 = {{1,2,3},{4,5,6}};
    cout << "Example2 -> Expected 12, Got: " << sol.minPathSum(grid2) << "\n";

    return 0;
}