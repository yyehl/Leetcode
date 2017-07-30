class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> ret;
        sort(candidates.begin(), candidates.end());
        int left = 0, right = candidates.size()-1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target < candidates[mid])   right = mid - 1;
            else left = mid + 1;
        }
        foo(candidates, ret, tmp, 0, left-1, target);
        return ret;
    }
    void foo(const vector<int>& nums, vector<vector<int>>& ret, vector<int>& tmp, int left, int right, int target)
    {
        if (target == 0)
        {
            ret.push_back(tmp);
            return ;
        }
        for (int i = left; i <= right; i++)
        {
            if (target >= nums[i])
            {
                tmp.push_back(nums[i]);
                foo(nums, ret, tmp, i+1, right, target-nums[i]);
                tmp.pop_back();
            }
            while (i < right && nums[i] == nums[i+1])   i++;
        }
    }
};