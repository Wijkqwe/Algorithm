#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> qwe;
    qwe.push_back(1);

    if (k == 1)
    {
        cout << n << '\n';
        return;
    }
    while (n)
    {
        ans += n % k;
        n /= k;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}