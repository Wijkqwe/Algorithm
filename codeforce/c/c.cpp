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



void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> qwe;
    vector<int> po;
    while (n--)
    {
        int a;
        cin >> a;
        if (qwe.find(a) == qwe.end())
        {
            qwe[a]++;
        }
        else
        {
            qwe.erase(a);
            po.push_back(a);
        }
    }
    if (po.size() < 4)
    {
        cout << "NO\n";
        return;
    }
    sort(po.begin(), po.end());
    int a = *--po.end(), s = *----po.end(), d = *po.begin(), f = *++po.begin();
    cout << "YES\n" << d << " " << f << " " << d << " " << a << " " << s << " " << f << " " << s << " " << a << endl;
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