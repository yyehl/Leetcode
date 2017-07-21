class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0, low = 0, high = height.size()-1;
        while (low < high)
        {
            ret = max(ret, min(height[low], height[high]) * (high-low));
            if (height[low] < height[high]) ++low;
            else --high;
        }
        return ret;
    }
};