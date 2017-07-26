class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())   return -1;
        else if (nums.size() == 1)  return nums[0] == target ? 0 : -1;
        int low = 0, high = nums.size()-1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[high])  high = mid;
            else if (nums[mid] > nums[high])   low = mid + 1;
            else    break;
        }
        int left, right;
        if (low > 0 && target >= nums[0])
            left = 0, right = low - 1;
        else
            left = low, right = nums.size()-1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target < nums[mid])  right = mid - 1;
            else if (target > nums[mid])   left = mid + 1;
            else   return mid;
        }
        return -1;
    }
};