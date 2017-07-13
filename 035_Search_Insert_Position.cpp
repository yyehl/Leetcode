class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size()-1, target);
    }
    
    int binary_search(const vector<int>& arr, int left, int right, int val)
    {
        int low = left, high = right, mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] < val)
                low = mid + 1;
            else if (arr[mid] > val)
                high = mid - 1;
            else 
                return mid;
        }
        return low;
    }
};