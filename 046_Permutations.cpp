class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        foo(ret, nums, tmp);
        return ret;
    }
    void foo(vector<vector<int>>& ret, vector<int>& vi, vector<int>& tmp)
    {
        if (vi.empty())  { ret.push_back(tmp);  return ; } 
        for (int i = 0; i < vi.size(); i++)
        {
            int x = vi[i];
            vi.erase(vi.begin()+i);
            tmp.push_back(x);
            foo(ret, vi, tmp);
            tmp.pop_back();
            vi.insert(vi.begin()+i, x);
        }
    }
};