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

signed main()
{
    int n, p = 0;
    cin >> n;
    while (n--)
    {
        int a;
        char c;
        cin >> c >> a;
        if (c == 'P')
        {
            p += a;
        }
        if (c == 'B')
        {
            if (a <= p)
            {
                p -= a;
                cout << "NO\n";
            }
            else
            {
               p = 0;
               cout << "YES\n"; 
            }
        }
    }

    return 0;
}