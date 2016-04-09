#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 150000 + 10;
const int INF = 0x3f3f3f3f;

int n, a[maxn], ans;
bool ok[maxn];
vector<int> bad;

bool check(int i) {
	if(i & 1) return a[i - 1] > a[i] && a[i] < a[i + 1];
	else return a[i - 1] < a[i] && a[i] > a[i + 1];
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	a[0] = INF;
	if(n & 1) a[n + 1] = INF; else a[n + 1] = 0;

	for(int i = 1; i <= n; i++) {
		if(!check(i)) bad.push_back(i);
		else ok[i] = true;
	}

	if(bad.size() > 6) { printf("0\n"); return 0; }

	for(int i : bad) {
		for(int j = 1; j <= n; j++) if(ok[j] || j < i) {
			swap(a[i], a[j]);
			bool flag = true;
			if(!check(i) || !check(j)) flag = false;
			for(int k : bad) if(!check(k)) { flag = false; break; }
			if(flag) ans++;
			swap(a[i], a[j]);
		}
	}

	printf("%d\n", ans);

return 0;
}
