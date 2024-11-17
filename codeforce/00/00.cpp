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
    int n, ans = 0;
    cin >> n;
    vector<int> a(30, 0);
    for (int i = 0; i < n; ++i)
    {
        int q;
        cin >> q;
        if (a[q])
        {
            a[q] = 0;
            ans++;
        }
        else
            a[q]++;
    }
    cout << ans << endl;
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