class Solution
{
public:
    //: 官方题解二
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i)
        {
            while (!q.empty() && nums[i] >= nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i)
        {
            while (!q.empty() && nums[i] >= nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k)
            {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
    //:
    /*
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> res;
        multiset<int, greater<int>> sets;
        for (int i = 0; i < nums.size() && i < k; ++i)
            sets.insert(nums[i]);
        res.push_back(*sets.begin());

        for (int i = k; i < nums.size(); ++i)
        {
            sets.erase(sets.find(nums[i - k]));
            sets.insert(nums[i]);
            res.push_back(*sets.begin());
        }

        return res;
    }  //*/
};
