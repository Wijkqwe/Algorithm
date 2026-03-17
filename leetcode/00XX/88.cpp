
class Solution
{
public:
    //: 官方题解法三
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while (i >= 0)
            nums1[k--] = nums1[i--];
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
    //: 官方题解法二
    /*
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> nums = nums1;
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums[i] < nums2[j])
            {
                nums1[k++] = nums[i++];
            }
            else
            {
                nums1[k++] = nums2[j++];
            }
        }
        if (i != m)
        {
            while (i < m)
            {
                nums1[k++] = nums[i++];
            }
        }
        if (j != n)
        {
            while (j < n)
            {
                nums1[k++] = nums2[j++];
            }
        }
    }//*/
};
