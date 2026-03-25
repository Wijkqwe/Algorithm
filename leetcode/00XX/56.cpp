class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int left = intervals[0][0], right = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] <= intervals[i - 1][1] || intervals[i][0] <= right)
            {
                right = max(right, intervals[i][1]);
            }
            else
            {
                vector<int> a = {left, right};
                res.push_back(move(a));
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        vector<int> a = {left, right};
        res.push_back(move(a));

        return res;
    }
};
