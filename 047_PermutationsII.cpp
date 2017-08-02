class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        foo(ret, nums, tmp);
        return ret;
    }
    void foo(vector<vector<int>>& ret, vector<int>& nums, vector<int>& tmp)
    {
        if (nums.empty())   
        {
            ret.push_back(tmp);
            return ;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            nums.erase(nums.begin()+i);
            tmp.push_back(x);
            foo(ret, nums, tmp);
            tmp.pop_back();
            nums.insert(nums.begin()+i, x);
            while (i < nums.size() && nums[i+1] == x) ++i;
        }
    }
};