class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0)   return vector<int>();
        else if (rowIndex == 0)     return vector<int>(1, 1);
        else ;
        
        vector<int> ret(rowIndex + 1);
        vector<int> tmp(rowIndex + 1);
        int new_sz;
        tmp.resize(1);
        tmp[0] = 1;
        for (int i = 1; i <= rowIndex; i++)
        {
            int new_sz = tmp.size() + 1;
            ret.resize(new_sz);
            ret[0] = ret[new_sz - 1] = 1;
            for (int j = 1; j <= new_sz-2; j++)
                ret[j] = tmp[j] + tmp[j-1];
            tmp.resize(new_sz);
            for (int k = 0; k < new_sz; k++)
                tmp[k] = ret[k];
        }
        return ret;
    }
};