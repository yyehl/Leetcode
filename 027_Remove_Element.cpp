class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())  return 0;
        int i = 0;
        while (i < nums.size())
        {
            if (val == nums[i])
                nums.erase(static_cast<vector<int>::iterator>(&nums[i]));
            else 
                ++i;
        }
        return nums.size();
    }
};