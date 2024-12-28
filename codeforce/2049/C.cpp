#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fast                                                                                                           \
    ios::sync_with_stdio(false);                                                                                       \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define gc() getchar()
#define MOD 100000000
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

void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

inline void solve()
{
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    --x, --y;

    auto next = [&](int i) -> int
    {
        int j = i + 1;
        if (j == n)
            j = 0;
        return j;
    };

    vector<int> a(n);
    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i++)
            a[i] = i % 2;
        if (a[x] == a[y])
            a[x] = 2;
    }
    else
    {
        int i = x;
        a[i] = 2;
        for (int c = 0; c < n - 1; c++)
        {
            i = next(i);
            a[i] = c % 2;
        }
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

signed main()
{
    fast ll T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
