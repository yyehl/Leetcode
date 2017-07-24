class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)   return vector<vector<int>>(0, vector<int>());
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int target_3, target_2, j, left, right;
        for (int i = 0; i < nums.size()-3; i++)
        {
            j = i + 1;
            target_3 = target - nums[i];
            while (j < nums.size()-2)
            {
                left = j + 1;
                right = nums.size()-1;
                target_2 = target_3 - nums[j];
                while (left < right)
                {
                    if (nums[left] + nums[right] < target_2)   ++left;
                    else if (nums[left] + nums[right] > target_2)   --right;
                    else
                    {
                        vector<int> tmp(4);
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[left];
                        tmp[3] = nums[right];
                        ret.push_back(tmp);
                        ++left;
                        --right;
                        while (left < right && nums[left] == nums[left-1]) ++left;
                        while (left < right && nums[right] == nums[right+1])  --right;
                    }
                }
                j++;
                while (j < nums.size()-2 && nums[j] == nums[j-1])   ++j;
            }
            while (i < nums.size()-3 && nums[i] == nums[i+1])  ++i;
        }
        return ret;
    }
};