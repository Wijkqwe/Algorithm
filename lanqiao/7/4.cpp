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

#define int long long

namespace slove
{
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

inline void solve()
{
    int n;
    string q;
    cin >> n >> q;
    vi num(10, 0);
    for (char i : q)
    {
        ++num[i - 'A'];
    }
    cout << num[0];
    for (int i = 1; i < 10; ++i)
        cout << " " << num[i];
    cout << endl;
}
}  // namespace slove

signed main()
{
    fast;
    ll T = 1;
    // T = read();
    cin >> T;
    while (T--)
        slove::solve();
    return 0;
}

/*这场比赛共有十个问题，对应序号分别为 A∼J。现在给你一个字符串 s，由大写字母 A∼J
组成，代表预期的提交序列。该提交序列的每一次提交都一定通过，也一定会发出一个相应的气球。请你帮帮志愿者们，根据预期的提交序列，计算出每道题目需要准备多少气球吧！
输入

第一行输入一个正整数 t(1≤t≤2×105) ，代表测试用例的数量。

每个测试用例给出两行，第一行输入一个正整数 n(1≤n≤2×105) ，代表预期提交序列的长度。

第二场输入一个字符串 s，代表预期提交序列，其中 si​∈{′A′∼′J′}。

所有测试用例的n总和不超过 2×105。
输出

输出一行10个整数，分别代表 A∼J 每道题目需要准备多少气球。*/