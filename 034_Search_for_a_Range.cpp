class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret = {-1, -1};
        if (nums.empty())    return ret;
        int left = lower_bound(nums, 0, nums.size()-1, target);
        int right = upper_bound(nums, 0, nums.size()-1, target);
        if (left < nums.size() && nums[left] == target)   ret[0] = left, ret[1] = right-1;
        return ret;
    }
    int lower_bound(const vector<int>& nums, int low, int high, int target)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (target <= nums[mid])    high = mid - 1;
            else    low = mid + 1;
        }
        return low;
    }
    int upper_bound(const vector<int>& nums, int low, int high, int target)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (target >= nums[mid])    low = mid + 1;
            else   high = mid - 1;
        }
        return low;
    }
};