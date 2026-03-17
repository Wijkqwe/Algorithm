class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int res = nums.size();
        for (int i = 0, j = res - 1; i <= j;)
        {
            if (nums[j] == val)
            {
                --res;
                --j;
                continue;
            }
            if (nums[i] == val)
            {
                swap(nums[i], nums[j--]);
                --res;
            }
            ++i;
        }

        return res;
    }
};
