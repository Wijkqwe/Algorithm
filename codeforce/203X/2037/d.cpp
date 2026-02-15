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

bool cmp(pair<int, int> a, pair<int, int> s)
{
    if (a.first == s.first)
        return a.second > s.second;
    return a.first < s.first;
}

void solve()
{
    int n, m, l, ans = 0;
    cin >> n >> m >> l;
    vector<pair<pair<int, int>, int>> nl(n);
    vector<pair<int, int>> ml(m);
    for (auto i : nl)
    {
        cin >> i.first.first >> i.first.second;
        i.second = i.first.second - i.first.first;
    }
    auto maxnl = max_element(nl.begin(), nl.end());
    for (auto i : ml)
    {
        cin >> i.first >> i.second;
    }
    sort(ml.begin(), ml.end(), cmp);
    bool fl = 1;
    while (maxnl >= nl.begin() && fl)
    {
        int a = 0;
        for (auto i = ml.begin(); i->first < maxnl->first.first; ++i)
        {
            a += i->second;
            ans++;
            if (a > maxnl->second)
            {

            }
        }
    }
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}