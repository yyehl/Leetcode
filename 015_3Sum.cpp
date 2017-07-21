class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)    return vector<vector<int>>(0, vector<int>());  
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int taget, left, right;
        for (int i = 0; i < nums.size()-2; i++)
        {
            taget = 0-nums[i];
            left = i + 1;
            right = nums.size()-1;
            while (left < right)
            {
                if (nums[left] + nums[right] < taget)
                    ++left;
                else if (nums[left] + nums[right] > taget)
                    --right;
                else
                {
                    vector<int> tmp(3, 0);
                    tmp[0] = nums[i];
                    tmp[1] = nums[left];
                    tmp[2] = nums[right];
                    ret.push_back(tmp);
                    while (left < right && nums[left] == tmp[1])   left++;
                    while ((left < right) && nums[right] == tmp[2]) right--;
                }
            }
            while (i+1 < nums.size() && nums[i+1] == nums[i])  ++i;
        }
        return ret;
    }
};