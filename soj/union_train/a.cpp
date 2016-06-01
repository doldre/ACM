/************************************************
 *Author        :mathon
 *Email         :luoxinchen96@gmail.com
*************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 500 + 5;
vector<int> ori_G[maxn];
vector<int> unori_G[maxn];
int out[maxn], in[maxn], degree[maxn];
bool used[maxn];
int n, m;

bool solve1() {
    queue<int> que;
    int odd = 0;
    for (int i = 1; i <= n; i++) {
        if(degree[i] % 2 == 1) {
            odd++;
        }
    }
    que.push(1);
    int cnt = 0;
    memset(used, 0, sizeof(used));
    while(!que.empty()) {
        int u = que.front(); que.pop();
        if(used[u]) continue;
        used[u] = true;
        /* pr(u); */
        cnt++;
        for (int i = 0; i < (int)unori_G[u].size(); i++) {
            int v = unori_G[u][i];
            if(!used[v]) {
                que.push(v);
            }
        }
    }
    /* pr(cnt); prln(odd); */
    return cnt == n && (odd == 0 || odd == 2);
}

bool solve2() {
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if(out[i] > in[i]) {
            que.push(i);
            break;
        }
    }
    if(que.empty()) que.push(1);
    int cnt = 0;
   memset(used, 0, sizeof(used));
    while(!que.empty()) {
        int u = que.front(); que.pop();
        if(used[u]) continue;
        used[u] = true;
        cnt++;
        for (int i = 0; i < (int)ori_G[u].size(); i++) {
            int v = ori_G[u][i];
            if(!used[v]) {
                que.push(v);
            }
        }
    }
    int tie = 0, mone = 0, lone = 0;
    for (int i = 1; i <= n; i++) {
        if(out[i] == in[i]) tie++;
        if(out[i] == in[i] + 1) mone++;
        if(out[i] == in[i] - 1) lone++;
    }
    return cnt == n && (tie == n || (tie == n - 2 && mone == 1 && lone == 1));
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++) {
            ori_G[i].clear();
            unori_G[i].clear();
        }
        memset(degree, 0, sizeof(degree));
        memset(out, 0, sizeof(out));
        memset(in, 0, sizeof(in));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            out[u]++; in[v]++;
            degree[u]++;
            degree[v]++;
            ori_G[u].push_back(v);
            unori_G[u].push_back(v);
            unori_G[v].push_back(u);
        }
        if(solve1()) {
            printf("Yes ");
        } else printf("No ");
        if(solve2()) {
            printf("Yes\n");
        } else printf("No\n");
    }
    return 0;
}
