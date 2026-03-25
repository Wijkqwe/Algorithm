class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        if (!k)
            return;
        if (k > nums.size())
            k %= nums.size();
        rev(nums, nums.size() - k, nums.size() - 1);
        rev(nums, 0, nums.size() - k - 1);
        rev(nums, 0, nums.size() - 1);
    }
private:
    void rev(vector<int>& nums, int s, int e)
    {  //: 翻转元素
        while (s < e)
            swap(nums[s++], nums[e--]);
    }
};
