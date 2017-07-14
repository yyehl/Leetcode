#include <vector>
#include <iostream>
#include <stdlib.h>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)   return nums[0];
        
        int ret = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum = sum + nums[i];
            ret = max(ret, sum);
            if (sum <= 0)   sum = 0;
        }
        return ret;
    }
};

class Solution1 {
public:
    vector<int> max_subarray_ret_arr(const vector<int>& nums)
    {
        if (nums.size() == 0 || nums.size() == 1)   return nums;

        int sum = 0, max = INT_MIN;
        int m = 0, n = 0, start = 0;
        vector<int> ret;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (max < sum)
            {
                max = sum;
                n = i;
                m = start;
            }
            if (sum <= 0)
            {
                sum = 0;
                start = i + 1;
            }
        }
        for (int i = m; i <= n; ++i)    ret.push_back(nums[i]);
        return ret;
    }
};


int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    Solution1 s1;
    vector<int> max_subarray = s1.max_subarray_ret_arr(nums);
    cout << s.maxSubArray(nums) << endl;
    for (int i = 0; i < max_subarray.size(); ++i)   cout << max_subarray[i] << " ";
    cout << endl;
    return 0;
}


