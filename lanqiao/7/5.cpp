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

#define int ll

namespace slove
{
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

inline void solve()
{
    int mid, maxi = 0, mini = 0;
    cin >> maxi;
    mid = (maxi + mini) >> 1;
    cout << mid << endl;
    string q;
    for (int i = 0; i < 25; ++i)
    {
        cin >> q;
        if (q[0] == '>')
        {
            mini = mid;
            mid = (maxi + mini) >> 1;
            if (mid == mini)
                return void(cout << "! " << mid << endl);
            else
                cout << mid << endl;
        }
        else
        {
            maxi = mid;
            mid = (maxi + mini) >> 1;
            if (mid == maxi)
                return void(cout << "! " << mid << endl);
            else
                cout << mid << endl;
        }
    }
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

/*猜数字-交互版
你需要编写一个“猜数字”的程序。跟你做过的大部分题目不一样，你需要通过不断地询问另外一个程序（以下称之为“交互程序”）来猜到最终的数字。

在你的程序刚运行时，交互程序会通过标准输入给你提供一个数字 N，表示你需要猜的数字在 1 到 N 范围里。

接下来你可以开始发起你的询问。你可以直接通过输出到标准输出来询问；每次询问为一个数字，表示你猜测的结果。每次询问后，你需要刷新输出流，否则可能会有输出内容停留在缓冲区不被输出。例如
C++ 你可以使用

    fflush(stdout)

，Java 你可以使用

    System.out.flush()

，Pascal 你可以使用

    flush(output)

，Python 则可以使用

    stdout.flush()

。

交互程序会根据你的询问返回你的猜测与正确答案的比较情况。具体而言：

    如果正确答案小于你的猜测，则会返回 <；
    如果正确答案大于等于你的猜测，则会返回 >=

一旦你确定你找到了正确的答案，则输出

    ! x

（x 是你猜测的数字，注意与感叹号用空格隔开），并立刻结束你的程序（否则判题系统可能不能返回正确的判题结果）。

最后，总的询问次数不能大于等于 25 次。

请你尝试猜对正确的数字吧！
输入样例:

    20
    >=
    <
    >=
    <
    >=
    <

输出样例:

    5
    18
    10
    13
    12
    11
    ! 12

样例程序

以下程序用于你理解如何与交互程序进行交互，并不是正确的程序。

    #include <cstdio>
    int main() {
        int n;
        scanf("%d", &n);
        printf("%d\n", n / 2);
        fflush(stdout);
        char ans[10];
        scanf("%s", ans);
        if(ans[0] == '>') {
            printf("! %d\n", n / 2 + 1);
            fflush(stdout);
        } else {
            printf("! %d\n", n / 2 - 1);
            fflush(stdout);
        }
    }*/