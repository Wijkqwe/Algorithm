class Solution
{
public:
    //:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        unsigned short n = nums.size();
        sort(nums.begin(), nums.end());  //: 排序

        for (unsigned short i = 0; i < n; ++i)
        {                                    //: i指向第一个数
            if (i > 0)                       //: 不过滤第一次
                if (nums[i] == nums[i - 1])  //: 过滤重复的数
                    continue;
            unsigned short k = n - 1;  //: k指向第三个数
            for (unsigned short j = i + 1; j < k; ++j)
            {                                    //: j指向第二个数
                if (j > i + 1)                   //: 不过滤第一次
                    if (nums[j] == nums[j - 1])  //: 过滤重复的数
                        continue;
                while (nums[j] + nums[k] + nums[i] > 0 && k > j)
                    --k;  //: 左移减小遍历范围
                if (nums[j] + nums[k] + nums[i] == 0 && j != k)
                    res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};
