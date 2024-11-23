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
    double n;
    cin >> n;
    map<int, int> qwe;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        qwe[a]++;
    }
    n -= 2;
    for (int i = 1; i <= n; ++i)
    {
        if (!n % i)
        {
            int j = n / i;
            if (i == j && qwe[i] >= 2)
            {
                cout << i << ' ' << j << endl;
                return;
            }
            else if (i != j && qwe[i] >= 1 && qwe[j] >= 1)
            {
                cout << i << ' ' << j << endl;
                return;
            }
        }
    }

}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}