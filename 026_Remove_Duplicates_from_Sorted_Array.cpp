class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        return unique(nums.begin(), nums.end()) - nums.begin();
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)  return nums.size();
        
        int ret = 1;
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); )
        {
            if (nums[i] > tmp)  
            {
                ++ret;
                tmp = nums[i];
                ++i;
            }
            else
                nums.erase(static_cast<vector<int>::iterator>(&nums[i]));
        }
        return ret;
    }
};