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

vll res;

void qwe(ll n, ll m)
{
    if (m >= n - 1)
    {
        res.pb(n);
        if (n > 1)
            qwe(n - 1, m - n + 1);
    }
    else
    {
        for (ll i = 1; i < n; ++i)
        {
            if (i == n - m)
                res.pb(n);
            res.pb(i);
        }
        if (!m && n > 1)
            res.pb(n);
    }
}

long long getBubbleSortSwapCount(vi a, int n)
{
    long long count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                count++;

                int temp = a[j + 1];

                a[j + 1] = a[j];

                a[j] = temp;
            }
        }
    }

    return count;
}

inline void solve()
{
    ll n, m;
    cin >> n >> m;
    qwe(n, m);
    cout << res[0];
    for (ll i = 1; i < n; ++i)
        cout << " " << res[i];
    cout << endl;
    // cout << getBubbleSortSwapCount(res, n);
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

/*给定一个正整数 n (1≤n≤1×106)，请你构造出一个大小为 n 的排列数组 a , 使数组 a
在经典冒泡排序（将数组从小到大排序）函数（参考下方代码）下得到的交换次数 count 为
k(0≤k≤2n×(n−1)​). 排列数组定义：数组的大小为 n,  且数组只包含 [1,n]
范围内的元素，并且数组中任意两个元素互不相同，例如：数组 {3,5,1,4,2} 是一个大小为 5 排列数组, 数组 {3,1,4,3,2}
不是一个排列数组，因为数组中包含 2 个元素 3 ，不满足数组中任意两个元素互不相同.
如果有多种答案满足要求，输出任意一种即可。
输入：

输入两个正整数n (1≤n≤1×106) , k (0≤k≤2n×(n−1)​).
输出：

输出一行大小为 n 的排列 a1​,a2​,a3​,...,an​(1≤ai​≤n).*/