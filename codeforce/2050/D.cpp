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

void solve()
{
    string q;
    cin >> q;
    for (int i = 0; i < q.size(); ++i)
    {
        for (int j = i; j > 0; --j)
        {
            if (q[j] - 1 > q[j - 1])
                swap(--q[j], q[j - 1]);
            else
                break;
        }
    }
    cout << q + endl;
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
