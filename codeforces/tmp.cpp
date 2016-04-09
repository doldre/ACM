#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define X first
#define Y second

const int maxn = 1005;
const int maxs = 1e6 + 5;
const int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m;
long long K;

int a[maxn][maxn], b[maxn][maxn], fa[maxs], size[maxs];
std::pair<int, std::pair<int,int> > t[maxs];
int tot, lim;

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int a,int b)
{
	a = find(a), b = find(b);

	if(a != b)
	{
		size[a] += size[b];
		size[b] = 0, fa[b] = a;
	}
}
void dfs(int x,int y)
{
	if(!(x >= 0 && x < n && y >= 0 && y < m)) return;
	if(a[x][y] < lim || b[x][y] || !tot) return;

	b[x][y] = lim, tot--;

	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y - 1);
	dfs(x, y + 1);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	scanf("%d%d", &n, &m);
	std::cin >> K;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			t[i * m + j] = std::make_pair(a[i][j], std::make_pair(i, j));
		}

	std::sort(t, t + n * m);
	std::reverse(t, t + n * m);

	for(int i = 0; i < n * m; i++) fa[i] = i, size[i] = 1;

	int ans = -1;

	for(int i = 0, j = 0; i < n * m; i = j)
	{
		while(j < n * m && t[j].X == t[i].X)
		{
			for(int k = 0; k < 4; k++)
			{
				int ox = t[j].Y.X;
				int oy = t[j].Y.Y;
				int x = move[k][0] + ox;
				int y = move[k][1] + oy;

				if(x >= 0 && x < n && y >= 0 && y < m)
					if(a[x][y] >= t[i].X) merge(x * m + y, ox * m + oy);
			}

			j++;
		}

		if(t[i].X && K % t[i].X == 0)
		{
			for(int k = i; k < j; k++)
			{
				int x = t[k].Y.X, y = t[k].Y.Y;

				if(size[find(x * m + y)] >= K / t[i].X)
				{ ans = x * m + y; break; }
			}

			if(ans != -1) break;
		}
	}

	if(ans == -1) puts("NO");
	else
	{
		lim = a[ans / m][ans % m];
		tot = K / lim;

		dfs(ans / m, ans % m);

		puts("YES");
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
				printf("%d ", b[i][j]);
			puts("");
		}
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
