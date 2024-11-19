/*cf_4D
typedef long long LL;
const int MAXN = 5000 + 10;
int n, f[MAXN], las[MAXN], wz, hz, cnt;
struct node
{
	int w, h, id;
}a[MAXN];

int read()
{
	int sum = 0, fh = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') fh = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { sum = (sum << 3) + (sum << 1) + (ch ^ 48); ch = getchar(); }
	return sum * fh;
}

bool cmp(const node& fir, const node& sec)
{
	if (fir.w ^ sec.w) return fir.w < sec.w;
	return fir.h < sec.h;
}

void print(int k)
{
	if (k == -1) return;
	print(las[k]); printf("%d ", a[k].id);
}

int main()
{
	n = read(), wz = read(), hz = read();
	for (int i = 1; i <= n; ++i)
	{
		int w = read(), h = read(); las[i] = -1;
		if (w <= wz || h <= hz) continue;
		a[++cnt].w = w; a[cnt].h = h; a[cnt].id = i;
	}
	if (cnt == 0) { printf("0\n"); return 0; }
	sort(a + 1, a + cnt + 1, cmp);
	for (int i = 1; i <= cnt; ++i)
	{
		f[i] = 1;
		for (int j = 1; j < i; ++j)
		{
			if (a[j].w < a[i].w && a[j].h < a[i].h && f[j] + 1 > f[i])
			{
				f[i] = f[j] + 1;
				las[i] = j;
			}
		}
	}
	int ans = 0, flag = 0;
	for (int i = 1; i <= cnt; ++i)
	{
		if (f[i] > ans)
		{
			ans = f[i];
			flag = i;
		}
	}
	printf("%d\n", ans); print(flag);
	return 0;
}

//*/