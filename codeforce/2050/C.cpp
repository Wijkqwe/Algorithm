#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fast                                                                                                           \
    ios::sync_with_stdio(false);                                                                                       \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define int long long
#define gc() getchar()
#define MOD 100000000
#define one void(cout << "-1\n")
#define pb(c) push_back(c)
#define rint register int
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()

void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
/*
一个数乘以某个数的余数，再乘以该数的逆元（模9意义下），结果仍然是原数（模9意义下）。
九余数定理:一个数对9取余等于这个数各位数相加的和对9取余
*/
void solve()
{
    string q;
    cin >> q;
    int s = 0, c2 = 0, c3 = 0;
    for (char i : q)
    {
        int a = i - '0';
        s += a;
        if (a == 2)
            ++c2;
        if (a == 3)
            ++c3;
    }
    int kk = (9 - (s % 9)) % 9;
    for (int i = 0; i <= c3; ++i)
    {
        int tmp = (kk - 6 * i) % 9;
        if (tmp < 0)
            tmp += 9;
        int a = tmp * 5 % 9;
        if (a <= c2)
            return yes();
    }
    no();
}

signed main()
{
    fast int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
