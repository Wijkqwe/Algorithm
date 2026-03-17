class Solution
{
public:
    //: 官方题解
    int lengthOfLongestSubstring(string s)
    {
        if (!s.size())
            return 0;
        int res = 1;
        int i = 0, j = -1;
        unordered_set<int> sets;
        for (; i < s.size(); ++i)
        {
            if (i)
                sets.erase(s[i - 1]);
            while (j + 1 < s.size() && !sets.count(s[j + 1]))
            {
                sets.insert(s[j + 1]);
                ++j;
            }
            res = max(res, j - i + 1);
        }

        return res;
    }
    /*
    int lengthOfLongestSubstring(string s)
    {
        if (!s.size())
            return 0;
        int res = 1;
        int i = 0, j = i + 1;           //: 左右指针
        unordered_map<char, int> maps;  //: 记录每个字符是否出现过
        maps[s[0]] = 0;
        for (; j < s.size(); ++j)
        {
            if (maps.find(s[j]) != maps.end())
            {
                res = max(res, j - i);
                while (i < maps[s[j]] + 1)
                {
                    maps.erase(s[i++]);
                }
            }
            maps[s[j]] = j;
        }
        res = max(res, j - i);
        return res;
    }//*/
};
