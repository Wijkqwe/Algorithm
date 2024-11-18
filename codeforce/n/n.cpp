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
    int n;
    cin >> n;
    while (n--)
    {
        int a, s;
        char c;
        cin >> a >> c >> s;
        if (a > s) 
            c = '>';
        if (a < s)
            c = '<';
        if (a == s)
            c = '=';
        cout << a << c << s << endl;
    }

    return 0;
}