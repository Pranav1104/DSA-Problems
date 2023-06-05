/*  Approach : Mark the zeros with the help of 2 arrays.

    Time Complexity : O((N*M)*(N+M)), 
    Where N is the number of row and 
    M is number of column of matrix. 
    Here nested loops creates the time complexity. 
    O(N*M) for traversing through each element and 
    (N+M)for traversing to row and column of elements having value 0.

    ******Space Complexity : O(1), Constant space.******

    Solved using Matrix.   */

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    for (int k = 0; k < m; k++)
                    {
                        if (matrix[i][k] != 0)
                        {
                            matrix[i][k] = -9999;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (matrix[k][j] != 0)
                        {
                            matrix[k][j] = -9999;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == -9999)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};