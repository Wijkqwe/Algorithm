#include <bits/stdc++.h>
using namespace std;

// #define endl "\n"
#define fast                                                                                                           \
    ios::sync_with_stdio(false);                                                                                       \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define gc() getchar()
#define one void(cout << "-1\n")
#define pb(c) push_back(c)
#define pf(c) push_front(c)
#define pii pair<int, int>
#define pll pair<long long, long long>
#define rint register int
#define vi vector<int>
#define vll vector<long long>
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

namespace slove
{
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

struct qwe
{
        short val;
        struct qwe *l, *r;
};

inline void solve()
{
    vi num(1005 * 1005), dp(1005 * 1005);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cin >> num[i * 1005 + j];
        }
    }
    dp[0] = num[0];
    dp[1 * 1005 + 0] = num[0] + num[1 * 1005 + 0];
    dp[1 * 1005 + 1] = num[0] + num[1 * 1005 + 1];
    for (int i = 2; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0)
            {
                dp[i * 1005] = dp[(i - 1) * 1005] + num[i * 1005];
                continue;
            }
            else if (j == i)
            {
                dp[i * 1005 + j] = dp[(i - 1) * 1005 + j - 1] + num[i * 1005 + j];
                continue;
            }
            dp[i * 1005 + j] = num[i * 1005 + j] + max(dp[(i - 1) * 1005 + j - 1], dp[(i - 1) * 1005 + j]);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ans < dp[(n - 1) * 1005 + i])
            ans = dp[(n - 1) * 1005 + i];
    }
    cout << ans;
}
}  // namespace slove

signed main()
{
    fast;
    ll T = 1;
    // T = read();
    // cin >> T;
    while (T--)
        slove::solve();
    return 0;
}

/*7-12 数字三角形
分数 30
作者 李廷元
单位 中国民用航空飞行学院

观察下面的数字金字塔。写一个程序查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。每一步可以从当前点走到左下方的点也可以到达右下方的点。

snap0404.jpg

在上面的样例中,从13到8到26到15到24的路径产生了最大的和86。
输入格式:

第一个行包含R(1≤ R≤1000)，表示行的数目。

后面每行为这个数字金字塔特定行包含的整数。

所有的被供应的整数是非负的且不大于100。
输出格式:

单独的一行，包含那个可能得到的最大的和。
输入样例:

5
13
11 8
12 7  26
6  14 15 8
12 7  13 24 11

输出样例:

86*/