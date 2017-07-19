class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)   return vector<vector<int>>(0, vector<int>(0));
        vector<vector<int>> ret;
        ret.push_back(vector<int>(1, 1));
        int new_sz;
        vector<int> tmp(numRows);
        for (int i = 2; i <= numRows; ++i)
        {
            tmp.clear();
            new_sz = ret.rbegin()->size() + 1;
            tmp.resize(new_sz);
            tmp[0] = 1, tmp[new_sz - 1] = 1;
            for (int j = 1; j <= new_sz - 2; j++)
            {
                tmp[j] = ret[i-2][j] + ret[i-2][j-1];
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};