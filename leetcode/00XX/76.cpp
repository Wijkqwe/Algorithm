class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> smap, tmap;
        int distance = 0, min = s.size() + 1;
        int start = -1, ans = -1;
        for (auto i : t)
        {
            if (tmap.find(i) == tmap.end())
            {
                ++distance;
            }
            ++tmap[i];
        }
        for (int i = 0, j = 0; j < s.size(); ++j)
        {
            if (++smap[s[j]] > 0 && smap[s[j]] == tmap[s[j]])
                --distance;
            while (!distance)
            {
                if (j - i + 1 < min)
                {
                    min = j - i + 1;
                    start = i;
                }
                if (smap[s[j]] > 0 && smap[s[i]] == tmap[s[i]])
                    ++distance;
                --smap[s[i++]];
            }
        }
        if (start == -1)
            return "";
        return string(s.begin() + start, s.begin() + start + min);
    }
};

//: 官方题解
/*
class Solution
{
public:
    bool check()
    {
        for (const auto& p : tmap)
            if (smap[p.first] < p.second)
                return false;
        return true;
    }

    string minWindow(string s, string t)
    {
        for (auto i : t)
            ++tmap[i];
        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;

        while (r < int(s.size()))
        {
            if (tmap.find(s[++r]) != tmap.end())
            {
                ++smap[s[r]];
            }
            while (check() && l <= r)
            {
                if (r - l + 1 < len)
                {
                    len = r - l + 1;
                    ansL = l;
                }
                if (tmap.find(s[l]) != tmap.end())
                {
                    --smap[s[l]];
                }
                ++l;
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
private:
    unordered_map<char, int> smap, tmap;
};//*/

//: 作者：若叶舞风
//: 链接：https://leetcode.cn/problems/minimum-window-substring/solutions/3923357/hua-dong-chuang-kou-hai-ming-ju-by-angry-b7ur/
/*
char* minWindow(char* s, char* t)
{
    int *Hash1 = (int*)calloc(128, sizeof(int)), *Hash2 = (int*)calloc(128, sizeof(int));
    int len1 = strlen(s), len2 = strlen(t), i, j, distance = 0, left = 0, right = 0, min = len1 + 1;
    char *start = NULL, *ans = NULL;
    for (i = 0; i < len2; i++)
    {
        if (Hash2[t[i]]++ == 0)
            distance++;
    }
    i = 0;
    for (j = 0; j < len1; j++)
    {
        Hash1[s[j]]++;
        if (Hash1[s[j]] > 0 && Hash1[s[j]] == Hash2[s[j]])
            distance--;
        while (distance == 0)
        {
            if (j - i + 1 < min)
            {
                min = j - i + 1;
                start = s + i;
            }
            if (Hash1[s[j]] > 0 && Hash1[s[i]] == Hash2[s[i]])
                distance++;
            Hash1[s[i]]--;
            i++;
        }
    }
    ans = (char*)calloc(min + 1, sizeof(char));
    if (start == NULL)
        return ans;
    strncpy(ans, start, min);
    return ans;
}//*/
