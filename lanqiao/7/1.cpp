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

#define int ll

namespace slove
{
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

bool is_prime(int a)
{
    if (a <= 1)
        return false;
    for (int i = 2; i * i <= a; ++i)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

inline void solve()
{
    int n;
    int res;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        if (is_prime(a))
            ++res;
    }
    if (res <= 2)
        return void(cout << "0\n");
    res = (res >= 3) ? (res * (res - 1) * (res - 2) / 6) : 0;
    cout << res << endl;
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

/*
给定一个长度为 n 的序列 a，我们定义友谊组为满足条件 (ai​,aj​,ak​)，其中
1≤i<j<k≤n，且 ai​，aj​，ak​
均为质数的组合。现在需要计算序列中存在多少个不同的友谊组。

友谊组的唯一性取决于它们的下标各不相同。质数是指大于1的自然数中，除了1和该数自身外，无法被其他自然数整除的数。
输入格式:

第一行一个整数 n (1≤n≤1e5)，表示序列 a 长度为 n。

第二行 n 个整数，表示序列 ai​ (1≤ai​≤5e5)。
输出格式:

输出一个整数表示有多少友谊组。*/