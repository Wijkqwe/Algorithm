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

inline void solve()
{
    double q[4], ans = 0;
    cin >> q[1] >> q[2] >> q[3];
    int a, s;
    for (cin >> a >> s; a && s; cin >> a >> s)
    {
        ans += q[a] * s;
    }
    printf("%.2f", ans);
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

/*学校餐厅新开了一个炸鸡翅的窗口，鸡翅有椒盐、麻辣、香辣三种不同的口味，不同口味的价格是不一样的，请你根据一天的销售信息，计算出营业额。
输入格式:

第一行输入三个实数，表示不同口味鸡翅一份的单价，三种口味分别用1，2，3表示。

接着有多行，每行输入两个整数，表示一单销售的鸡翅的口味和份数。

输入0 0表示结束。
输出格式:

输出一天的营业额，保留两位小数。*/