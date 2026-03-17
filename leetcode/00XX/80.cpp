class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int res = 0, count = 0;
        for (int j = res + 1; j < nums.size(); ++j)
        {
            if (nums[res] == nums[j])
            {
                if (!count)
                {
                    nums[++res] = nums[j];
                    ++count;
                }
            }
            else
            {
                nums[++res] = nums[j];
                count = 0;
            }
        }

        return res + 1;
    }
};