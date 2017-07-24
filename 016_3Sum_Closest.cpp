class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.empty())   return 0;
        else if (nums.size() == 1)  return nums[0];
        else if (nums.size() == 2)  return nums[0] + nums[1];
        else if (nums.size() == 3)  return nums[0] + nums[1] + nums[2];
        else ;
        
        std::sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        int left, right, new_target;
        for (int i = 0; i < nums.size()-2; i++)
        {
            left = i + 1;
            right = nums.size() - 1;
            new_target = target - nums[i];
            while (left < right)
            {
                ret = abs(nums[left] + nums[right] - new_target) < abs(ret-target) ? nums[left] + nums[right] + nums[i] : ret;
                if (nums[left] + nums[right] < new_target)
                    ++left;
                else if (nums[left] + nums[right] > new_target)
                    --right;
                else 
                    return ret;
            }
        }
        return ret;
    }
};