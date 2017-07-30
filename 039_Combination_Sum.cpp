class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return vector<vector<int>>(0, vector<int>());
        sort(candidates.begin(), candidates.end());
        int left = 0, right = candidates.size()-1;
        vector<vector<int>> ret;
        if (candidates[left] > target)  return ret;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target < candidates[mid])    right = mid - 1;
            else    left = mid + 1;
        }
        vector<int> tmp;
        foo(candidates, ret, tmp, 0, left-1, target);     
        return ret;
    }
    void foo(const vector<int>& nums, vector<vector<int>>& ret, vector<int> tmp, int left, int right, int target)
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
                foo(nums, ret, tmp, i, right, target-nums[i]);
                tmp.pop_back();
            }
        }
    }
    
};