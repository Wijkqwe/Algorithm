#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdint>
#include <cstdlib> //C 标准函数库
#include <fstream> //C++ 文件流输入输出库
#include <functional>
#include <iomanip>
#include <list>
#include <math.h>
#include <map>
#include <numeric>
#include <queue> //C++ queue队列库
#include <unordered_map>
#include <string.h>
#include <string>
#include <stack>
#include <set>
//#include <tbb/tbb.h>
#include <utility>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;








class Solution {
public:
    static bool cmp1(int a, int s)
    {
        vector<int> aa, ss;
        while (a / 10 && s / 10)
        {
            aa.push_back(a % 10);
            ss.push_back(s % 10);
            a /= 10;
            s /= 10;
        }
        while (a / 10)
        {
            aa.push_back(a % 10);
            a /= 10;
        }
        aa.push_back(a);
        while (s / 10)
        {
            ss.push_back(s % 10);
            s /= 10;
        }
        ss.push_back(s);
        reverse(aa.begin(), aa.end());
        reverse(ss.begin(), ss.end());
        auto i = aa.begin(), j = ss.begin();
        for (; i != aa.end() && j != ss.end(); ++i, ++j)
        {
            if (*i == *j)
                continue;
            return *i > *j;
        }
        if (i != aa.end())
            return false;
        if (j != ss.end())
            return true;
        return true;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp1);
        string q = "";
        for (auto i : nums)
        {
            q += to_string(i);
        }
        return q;
    }
};





int main()
{
    Solution a;
    vector<int> nums(5);
    for (auto &i : nums)
    {
        cin >> i;
    }
    cout << a.largestNumber(nums);

    
    return 0;
}