#include <bits/stdc++.h>

#define int long long
#define one void(cout << "-1\n")

using namespace std;

bool cmp(int a, int s) { return a > s; }

void solve()
{
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> qq(k + 5, 0);
    for (int i = 0; i < k; ++i)
    {
        int a, s;
        cin >> a >> s;
        qq[a] += s;
    }
    sort(qq.begin(), qq.end(), cmp);
    for (int i = 0; i < n && i < qq.size(); ++i)
    {
        ans += qq[i];
    }
    cout << ans << "\n";
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
