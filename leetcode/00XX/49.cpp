class Solution
{
public:
    //: 官方题解二，需C++14+
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        auto arrayHash = [fn = hash<int>{}](const array<int, 26>& arr) -> size_t
        {//: lambda自定义哈希函数，为`array<int, 26>`提供哈希特化，使之可作为`unordered_map`的键
            return accumulate(arr.begin(), arr.end(), 0u,//: 遍历，0u: 无符号整数
                              [&](size_t acc, int num)
                              {//: 将计数数组映射到一个唯一的哈希值
                                  return (acc << 1) ^ fn(num);
                              });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str : strs)
        {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i)
            {
                counts[str[i] - 'a']++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
    //: 排序
    /*
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> res;
        map<string, vector<string>> maps;
        for (int i = 0; i < strs.size(); ++i)
        {
            string q = strs[i];
            sort(q.begin(), q.end());
            maps[q].push_back(strs[i]);
        }
        for (auto i : maps)
            res.push_back(i.second);
        return res;
    }//*/
};
