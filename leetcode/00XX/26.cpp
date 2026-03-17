class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int res = 1;
        for (int i = 0, j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] != nums[j])
            {
                nums[++i] = nums[j];
                ++res;
            }
        }

        return res;
    }
};
