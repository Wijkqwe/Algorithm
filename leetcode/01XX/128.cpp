class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (!nums.size())
            return 0;
        sort(nums.begin(), nums.end());
        int res = 1, sum = 1;
        for (int i = 0, j = i + 1; j < nums.size(); ++j)
        {
            if (nums[j] == nums[i] + 1)
            {
                i = j;
                ++sum;
            }
            else if (nums[i] == nums[j])
                continue;
            else
            {
                res = max(res, sum);
                sum = 1;
                i = j;
            }
        }
        res = max(res, sum);
        return res;
    }
};
