class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())   return vector<int>();
        else if (matrix.size() == 1)    return matrix[0];
        else ;
        
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ret;
        int ii, jj;
        for (int i = 0, j = 0; i < m  && j < n; ++i, ++j, --m, --n)
        {
            ii = i, jj = j;
            while (ii < m)  { ret.push_back(matrix[jj][ii]);  ++ii; }
            --ii;
            ++jj;
            if (jj == n)    break;
            while (jj < n)  { ret.push_back(matrix[jj][ii]);  ++jj; }
            --jj;
            --ii;
            if (ii < i)     break;
            while (ii >= i) { ret.push_back(matrix[jj][ii]);  --ii; }
            ++ii;
            --jj;
            while (jj > j)  { ret.push_back(matrix[jj][ii]);  --jj; }
        }
        return ret;
    }
};