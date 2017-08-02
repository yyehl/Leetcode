class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return ;
        int l = 0;
        n--;
        while (l < n)
        {
            vector<int> tmp = matrix[l];
            for (int i = l+1; i < n; i++)
                matrix[l][n-i+l] = matrix[i][l];
            for (int i = l+1; i < n; i++)
                matrix[i][l] = matrix[n][i];
            for (int i = l+1; i < n; i++)
                matrix[n][i] = matrix[n-i+l][n];
            for (int i = l+1; i < n; i++)
                matrix[i][n] = tmp[i];
            matrix[l][l] = matrix[n][l];
            matrix[n][l] = matrix[n][n];
            matrix[n][n] = matrix[l][n];
            matrix[l][n] = tmp[l];
            l++;
            n--;
        }
    }
};