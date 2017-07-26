
// O(nlogn)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1)   return ;
        for (int i = nums.size()-2; i >= 0; i--)
        {
            int left = i + 1, right = nums.size()-1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (nums[i] >= nums[mid])    left = mid + 1;
                else if (nums[i] < nums[mid])  right = mid - 1;
            }
            if (left == nums.size())  
            {
                int tmp = nums[i];
                std::copy(&nums[i+1], &nums[left], &nums[i]);
                nums[left-1] = tmp;
            }
            else    
            {
                swap(nums[i], nums[left]);
                break;
            }
        }
        return ;
    }
};

// O(n)     n+ logn + n/2
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1)   return ;
        int index = nums.size()-1;
        while (index > 0 && nums[index] <= nums[index-1])   index--;
        if (index != 0)
        {
            int low = index, high = nums.size()-1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (nums[mid] <= nums[index-1])   high = mid - 1;
                else    low = mid + 1;
            }
            swap(nums[index-1], nums[high]);
        }
        for (int i = index; i < index + (nums.size()-index)/2; i++)     swap(nums[i], nums[nums.size()-1-i+index]);
    }
};



