class Solution {
public:
    static bool cmp1(int a, int s)
    {
        return to_string(a) + to_string(s) > to_string(s) + to_string(a);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp1);
        if (nums[0] == 0)
            return "0";
        string q = "";
        for (auto i : nums)
        {
            q += to_string(i);
        }
        return q;
    }
};