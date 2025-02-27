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
    int n, k;
    cin >> n >> k;
    vector<int> nu(n), qwe(n);
    for (int& i : nu)
    {
        cin >> i;
    }

    for (int i = 0; i < n; ++i)
    {
        if (qwe[i])
            continue;
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;
            if (!((nu[j] - nu[i]) % k))
            {
                ++qwe[i];
                ++qwe[j];
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (qwe[i] == 0)
        {
            yes();
            cout << i + 1 << endl;
            return;
        }
    }
    return no();
}

signed main()
{
    fast int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
