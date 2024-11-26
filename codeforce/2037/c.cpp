#include <bits/stdc++.h>

#define one void(cout << "-1\n")

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n <= 4) return one;
    for (int i = 1; i <= n; i += 2)
    {
        if (i == 5) continue;
        cout << i << " ";
    }
    cout << "5 4 ";
    for (int i = 2; i <= n; i += 2)
    {
        if (i == 4) continue;
        cout << i << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
