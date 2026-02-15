#include <bits/stdc++.h>

#define int long long
#define one void(cout << "-1\n")

using namespace std;

bool cmp(int a, int s) { return a > s; }

void solve()
{
    int n;
    cin >> n;
    if (n == 1 || n == 3)
        return one;
    if (n == 2)
        return void(cout << "66\n");
    string q;
    for (int i = 0; i < n - 4; ++i)
    {
        q += "3";
    }

    if (n % 2)
        q += "6366";
    else
        q += "3366";
    cout << q + "\n";
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
