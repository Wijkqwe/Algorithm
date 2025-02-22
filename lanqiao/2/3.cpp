#include <bits/stdc++.h>
using namespace std;

// #define endl "\n"
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

namespace Fread
{
const int SIZE = 1 << 16;
char buf[SIZE], *S, *T;
inline char getchar()
{
    if (S == T)
    {
        T = (S = buf) + fread(buf, 1, SIZE, stdin);
        if (S == T)
            return '\n';
    }
    return *S++;
}
}  // namespace Fread
using namespace Fread;
namespace Fwrite
{
const int SIZE = 1 << 16;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush()
{
    fwrite(buf, 1, S - buf, stdout);
    S = buf;
}
inline void putchar(char c)
{
    *S++ = c;
    if (S == T)
        flush();
}
struct NTR
{
        ~NTR() { flush(); }
} ztr;
}  // namespace Fwrite
using namespace Fwrite;
#define getchar Fread::getchar
#define putchar Fwrite::putchar
namespace Fastio
{
struct Reader
{
        template <typename T>
        Reader& operator>>(T& x)
        {
            x = 0;
            short f = 1;
            char c = getchar();
            while (c < '0' || c > '9')
            {
                if (c == '-')
                    f *= -1;
                c = getchar();
            }
            while (c >= '0' && c <= '9')
                x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
            x *= f;
            return *this;
        }
        Reader& operator>>(double& x)
        {
            x = 0;
            double t = 0;
            short f = 1, s = 0;
            char c = getchar();
            while ((c < '0' || c > '9') && c != '.')
            {
                if (c == '-')
                    f *= -1;
                c = getchar();
            }
            while (c >= '0' && c <= '9' && c != '.')
                x = x * 10 + (c ^ 48), c = getchar();
            if (c == '.')
                c = getchar();
            else
            {
                x *= f;
                return *this;
            }
            while (c >= '0' && c <= '9')
                t = t * 10 + (c ^ 48), s++, c = getchar();
            while (s--)
                t /= 10.0;
            x = (x + t) * f;
            return *this;
        }
        Reader& operator>>(long double& x)
        {
            x = 0;
            long double t = 0;
            short f = 1, s = 0;
            char c = getchar();
            while ((c < '0' || c > '9') && c != '.')
            {
                if (c == '-')
                    f *= -1;
                c = getchar();
            }
            while (c >= '0' && c <= '9' && c != '.')
                x = x * 10 + (c ^ 48), c = getchar();
            if (c == '.')
                c = getchar();
            else
            {
                x *= f;
                return *this;
            }
            while (c >= '0' && c <= '9')
                t = t * 10 + (c ^ 48), s++, c = getchar();
            while (s--)
                t /= 10.0;
            x = (x + t) * f;
            return *this;
        }
        Reader& operator>>(__float128& x)
        {
            x = 0;
            __float128 t = 0;
            short f = 1, s = 0;
            char c = getchar();
            while ((c < '0' || c > '9') && c != '.')
            {
                if (c == '-')
                    f *= -1;
                c = getchar();
            }
            while (c >= '0' && c <= '9' && c != '.')
                x = x * 10 + (c ^ 48), c = getchar();
            if (c == '.')
                c = getchar();
            else
            {
                x *= f;
                return *this;
            }
            while (c >= '0' && c <= '9')
                t = t * 10 + (c ^ 48), s++, c = getchar();
            while (s--)
                t /= 10.0;
            x = (x + t) * f;
            return *this;
        }
        Reader& operator>>(char& c)
        {
            c = getchar();
            while (c == ' ' || c == '\n' || c == '\r')
                c = getchar();
            return *this;
        }
        Reader& operator>>(char* str)
        {
            int len = 0;
            char c = getchar();
            while (c == ' ' || c == '\n' || c == '\r')
                c = getchar();
            while (c != ' ' && c != '\n' && c != '\r')
                str[len++] = c, c = getchar();
            str[len] = '\0';
            return *this;
        }
        Reader& operator>>(string& str)
        {
            str.clear();
            char c = getchar();
            while (c == ' ' || c == '\n' || c == '\r')
                c = getchar();
            while (c != ' ' && c != '\n' && c != '\r')
                str.push_back(c), c = getchar();
            return *this;
        }
        Reader() {}
} cin;
const char endl = '\n';
struct Writer
{
        const int Setprecision = 6;
        typedef int mxdouble;
        template <typename T>
        Writer& operator<<(T x)
        {
            if (x == 0)
            {
                putchar('0');
                return *this;
            }
            if (x < 0)
                putchar('-'), x = -x;
            static short sta[40];
            short top = 0;
            while (x > 0)
                sta[++top] = x % 10, x /= 10;
            while (top > 0)
                putchar(sta[top] + '0'), top--;
            return *this;
        }
        Writer& operator<<(double x)
        {
            if (x < 0)
                putchar('-'), x = -x;
            mxdouble _ = x;
            x -= (double)_;
            static short sta[40];
            short top = 0;
            while (_ > 0)
                sta[++top] = _ % 10, _ /= 10;
            if (top == 0)
                putchar('0');
            while (top > 0)
                putchar(sta[top] + '0'), top--;
            putchar('.');
            for (int i = 0; i < Setprecision; i++)
                x *= 10;
            _ = x;
            while (_ > 0)
                sta[++top] = _ % 10, _ /= 10;
            for (int i = 0; i < Setprecision - top; i++)
                putchar('0');
            while (top > 0)
                putchar(sta[top] + '0'), top--;
            return *this;
        }
        Writer& operator<<(long double x)
        {
            if (x < 0)
                putchar('-'), x = -x;
            mxdouble _ = x;
            x -= (long double)_;
            static short sta[40];
            short top = 0;
            while (_ > 0)
                sta[++top] = _ % 10, _ /= 10;
            if (top == 0)
                putchar('0');
            while (top > 0)
                putchar(sta[top] + '0'), top--;
            putchar('.');
            for (int i = 0; i < Setprecision; i++)
                x *= 10;
            _ = x;
            while (_ > 0)
                sta[++top] = _ % 10, _ /= 10;
            for (int i = 0; i < Setprecision - top; i++)
                putchar('0');
            while (top > 0)
                putchar(sta[top] + '0'), top--;
            return *this;
        }
        Writer& operator<<(__float128 x)
        {
            if (x < 0)
                putchar('-'), x = -x;
            mxdouble _ = x;
            x -= (__float128)_;
            static short sta[40];
            short top = 0;
            while (_ > 0)
                sta[++top] = _ % 10, _ /= 10;
            if (top == 0)
                putchar('0');
            while (top > 0)
                putchar(sta[top] + '0'), top--;
            putchar('.');
            for (int i = 0; i < Setprecision; i++)
                x *= 10;
            _ = x;
            while (_ > 0)
                sta[++top] = _ % 10, _ /= 10;
            for (int i = 0; i < Setprecision - top; i++)
                putchar('0');
            while (top > 0)
                putchar(sta[top] + '0'), top--;
            return *this;
        }
        Writer& operator<<(char c)
        {
            putchar(c);
            return *this;
        }
        Writer& operator<<(char* str)
        {
            int cur = 0;
            while (str[cur])
                putchar(str[cur++]);
            return *this;
        }
        Writer& operator<<(const char* str)
        {
            int cur = 0;
            while (str[cur])
                putchar(str[cur++]);
            return *this;
        }
        Writer& operator<<(string str)
        {
            int st = 0, ed = str.size();
            while (st < ed)
                putchar(str[st++]);
            return *this;
        }
        Writer() {}
} cout;
}  // namespace Fastio
using namespace Fastio;
#define cin Fastio::cin
#define cout Fastio::cout
#define endl Fastio::endl

void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

ll mod = 998244353;

inline void solve()
{
    ll a, s, fla = 0, fls = 0, fld = 0;
    pll d, f;
    cin >> a >> s >> d.first >> f.first;
    d.second = 1;
    f.second = 2;

    if (d.first > f.first)
    {
        swap(d, f);
        fld = 1;
    }

    if (d.first >= a)
        fla++;
    if (d.first >= s)
        fla++;
    if (f.first >= a)
        fls++;
    if (f.first >= s)
        fls++;

    if (fla)
    {
        if (fld)
            cout << f.first << "-Y " << d.first << "-Y\n";
        else
            cout << d.first << "-Y " << f.first << "-Y\n";
        cout << "huan ying ru guan\n";
    }
    else
    {
        if (fls == 2)
        {
            if (fld)
                cout << f.first << "-Y " << d.first << "-Y\n";
            else
                cout << d.first << "-Y " << f.first << "-Y\n";
            cout << "qing " << f.second << " zhao gu hao " << d.second << endl;
        }
        else if (fls)
        {
            if (fld)
                cout << f.first << "-Y " << d.first << "-N\n";
            else
                cout << d.first << "-N " << f.first << "-Y\n";
            cout << f.second << ": huan ying ru guan\n";
        }
        else
        {
            if (fld)
                cout << f.first << "-N " << d.first << "-N\n";
            else
                cout << d.first << "-N " << f.first << "-N\n";
            cout << "zhang da zai lai ba\n";
        }
    }
}

signed main()
{
    // fast
    ll T = 1;
    // T = read();
    // cin >> T;
    while (T--)
        solve();
    return 0;
}

/*输入在一行中给出 4 个整数：

禁入年龄线 陪同年龄线 询问者1的年龄 询问者2的年龄

这里的禁入年龄线是指严格小于该年龄的儿童禁止入馆；陪同年龄线是指大于等于该年龄的人士可以陪同儿童入馆。默认两个询问者的编号依次分别为
1 和 2；年龄和年龄线都是 [1, 200] 区间内的整数，并且保证 陪同年龄线 严格大于 禁入年龄线。 输出格式：

在一行中输出对两位询问者的回答，如果可以进就输出 年龄-Y，否则输出 年龄-N，中间空 1 格，行首尾不得有多余空格。

在第二行根据两个询问者的情况输出一句话：

    如果两个人必须一起进，则输出 qing X zhao gu hao Y，其中 X 是陪同人的编号， Y 是小孩子的编号；
    如果两个人都可以进但不是必须一起的，则输出 huan ying ru guan；
    如果两个人都进不去，则输出 zhang da zai lai ba；
    如果一个人能进一个不能，则输出 X: huan ying ru guan，其中 X 是可以入馆的那个人的编号。
*/