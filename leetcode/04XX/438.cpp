class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        unordered_map<int, int> sets, pset;
        for (int i = 0; i < p.size(); ++i)
            pset[p[i]]++;
        int i = 0, j = 0;
        for (; i < s.size(); ++i)
        {
            while (j < i + p.size() && j < s.size())
            {
                sets[s[j++]]++;
            }
            if (sets == pset)
                res.push_back(i);

            if (sets[s[i]] > 1)
                sets[s[i]]--;
            else
                sets.erase(s[i]);
        }

        return res;
    }
};
