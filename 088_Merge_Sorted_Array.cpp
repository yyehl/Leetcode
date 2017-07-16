class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return ;
        else if (m == 0) 
        {
            copy(nums2.begin(), nums2.end(), nums1.begin());
            return ;
        }
        else ;
        
        vector<int> arr(m+n);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
                arr[k++] = nums1[i++];
            else 
                arr[k++] = nums2[j++];
        }
        while (i < m)
            arr[k++] = nums1[i++];
        while (j < n)
            arr[k++] = nums2[j++];
        for (int i = 0; i < m+n; i++)
            nums1[i] = arr[i];
    }
};