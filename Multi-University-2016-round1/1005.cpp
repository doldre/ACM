---
title: 暑期集训-7-11-a
date: 2016-09-11 14:55:36
tags:
- ACM
- 2016 暑期集训
- HDU
- 搜索
categories:
- 2016暑期集训
---
## 题意
HDU 4770
n*m的房间，有些房间可以被破坏，给出一些L形的灯，有一个特殊的灯可以旋转，让用最少的灯覆盖所有的可破坏的区域，且不能覆盖不可破坏的区域。

## 做法
暴力枚举可以旋转灯的位置和方向，暴力枚举其他灯的位置。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int inf = 0x3f3f3f3f;
const int maxn = 200 + 5;
char mp[maxn][maxn];
pii ps[maxn];
int cntps;
int used[maxn][maxn];
int timestamp;
int N, M;

pii dir1[] = {pii(0, 1), pii(1, 0), pii(-1, 0)};
pii dir2[] = {pii(1, 0), pii(0, -1), pii(0, -1)};

bool legal(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int work(int mask) {
    timestamp++;
    int cntcover = 0;
    for (int i = 0; i < cntps; i++) {
        if((mask>>i)&1) {
            int x = ps[i].xx, y = ps[i].yy;
            if(x - 1 >= 0 && mp[x-1][y] == '#') return inf;
            if(x - 1 >= 0 && used[x-1][y] != timestamp) {
                used[x-1][y] = timestamp;
                cntcover++;
            }
            if(used[x][y] != timestamp) {
                used[x][y] = timestamp;
                cntcover++;
            }
            if(y + 1 < M && mp[x][y+1] == '#') return inf;
            if(y + 1 < M && used[x][y+1] != timestamp) {
                used[x][y+1] = timestamp;
                cntcover++;
            }
        }
    }
    if(cntcover == cntps) return __builtin_popcount(mask);
    for (int i = 0; i < cntps; i++) {
        if(((mask >> i) & 1) == 0) {
            int x = ps[i].xx, y = ps[i].yy;
            for (int i = 0; i < 3; i++) {
                int t = 0;
                int nx, ny;
                nx = x + dir1[i].xx, ny = y + dir1[i].yy;
                if(legal(nx, ny)  && mp[nx][ny] == '#') continue;
                if(legal(nx, ny) && used[nx][ny] != timestamp) t++;
                if(used[x][y] != timestamp) t++;
                nx = x + dir2[i].xx, ny = y + dir2[i].yy;
                if(legal(nx, ny) && mp[nx][ny] == '#') continue;
                if(legal(nx, ny) && used[nx][ny] != timestamp) t++;
                if(t + cntcover == cntps) return __builtin_popcount(mask) + 1;
            }
        }
    }
    return inf;
}


int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &N, &M) == 2 && N && M) {
        memset(used, 0, sizeof(used));
        timestamp = 0;
        cntps = 0;
        for (int i = 0; i < N; i++) {
            scanf("%s", mp[i]);
            for (int j = 0; j < M; j++) {
                if(mp[i][j] == '.') {
                    ps[cntps++] = pii(i, j);
                }
            }
        }
        int ans = inf;
        for (int i = 0; i < (1<<cntps); i++) {
            ans = min(ans, work(i));
        }
        if(ans == inf) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}

```


---
title: 暑期集训-7-11-b
date: 2016-09-11 15:01:11
tags:
- ACM
- 2016 暑期集训
- HDU
- BFS
- 暴力
categories:
- 2016暑期集训
---
## 题意
HDU 4771
有若干个宝藏，问从起点遍历过所有K个宝藏的最短时间

## 做法
因为只有4个宝藏，所以预处理起点和4个宝藏之间两两之间的最短距离，枚举4个宝藏的遍历顺序求出答案。

<!--more-->
## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 100 + 5;
const int inf = 0x3f3f3f3f;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
char mp[maxn][maxn];
int d[maxn*maxn];
int dist[maxn*maxn][maxn*maxn];
int N, M;
int id(pii p) {
    return p.xx * M + p.yy;
}

int bfs(pii s, pii t) {
    memset(d, inf, sizeof(d));
    d[id(s)] = 0;
    queue<pii> que;
    que.push(s);
    while(!que.empty()) {
        pii cur = que.front(); que.pop();
        int x = cur.xx, y = cur.yy;
        if(cur == t) return d[id(cur)];
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(d[id(pii(nx, ny))] >= inf && mp[nx][ny] == '.') {
                pii nxt = pii(nx, ny);
                d[id(nxt)] = d[id(cur)] + 1;
                que.push(nxt);
            }
        }
    }
    return d[id(t)];
}

const int maxk = 4;
pii T[maxk + 1];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &N, &M) == 2 && N && M) {
        for (int i = 0; i < N; i++) {
            scanf("%s", mp[i]);
            for (int j = 0; j < M; j++) {
                if(mp[i][j] == '@') {
                    T[0] = pii(i, j);
                }
            }
        }
        
        int K; scanf("%d", &K);
        for (int i = 1; i <= K; i++) {
            scanf("%d%d", &T[i].xx, &T[i].yy);
            T[i].xx--; T[i].yy--;
        }
        
        for (int i = 0; i <= K; i++) {
            for (int j = 0; j <= K; j++) {
                if(i == j) continue;
                int t = bfs(T[i], T[j]);
                dist[id(T[i])][id(T[j])] = t;
            }
        }
        int A[] = {0, 1, 2, 3, 4};
        int ans = inf;
        do {
            int tmp = 0;
            for (int i = 0; i < K; i++) {
                tmp  += dist[id(T[A[i]])][id(T[A[i+1]])];
            }
            ans = min(ans, tmp);
        } while(next_permutation(A + 1, A + K + 1));
        
        if(ans == inf) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}

```

---
title: 暑期集训-7-11-c
date: 2016-09-11 15:05:27
tags:
- ACM
- 2016 暑期集训
- HDU
- 简单题
categories:
- 2016暑期集训
---
## 题意
HDU 4772
给两个n*n的矩阵，矩阵可以旋转，问两个矩阵最多可以有多少个数匹配

## 做法
水题
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 30 + 5;
int A[maxn][maxn], B[maxn][maxn];
int n;
int cal() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(A[i][j] == B[i][j]) {
                res++;
            }
        }
    }
    return res;
}

void turn() {
    int buf[maxn][maxn];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            buf[j][n - 1 - i] = A[i][j];
        }
    }
    memcpy(A, buf, sizeof(buf));
}


int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1 && n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &A[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &B[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            ans = max(ans, cal());
            turn();
        }
        cout << ans << endl;
    }
    return 0;
}

```

---
title: 暑期集训-7-11-g
date: 2016-09-11 15:08:51
tags:
- ACM
- 2016 暑期集训
- HDU
- Trie
categories:
- 2016暑期集训
---
## 题意
HDU 4776
给一颗树，定义两点之间的距离为两点路径中边权的xor值，求第k大的值。

## 做法
非常棒的一道题。首先我们转化为有根树，求出每个节点u到根节点的xor值d[u]，然后任意两点之间的xor值为这两个节点到根节点xor值得xor。对所有d[u]维护一颗trie树，通过这个trie树，我们可以做到给定x，查询x xor d[u]的第k大值。首先对于所有节点u,把d[u]与其他节点v，d[u] xor d[v]的最大值丢进优先队列，然后如果d[u]的最大值弹出队列，则把d[u]的次大值丢进去，以此类推。这样就能预处理出前K个最大值。
<!--more-->

## 代码
```cpp
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
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef unsigned long long ull;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e5 + 5;

struct Trie {
    struct Node {
        int nxt[2], num;
        void clear() {
            memset(nxt, -1, sizeof(nxt));
            num = 0;
        }
    }nds[maxn*64];
    int cnt;
    void init() {
        nds[0].clear();
        cnt = 0;
    }
    
    int newnode() {
        ++cnt;
        nds[cnt].clear();
        return cnt;
    }
    
    void insert(ll x) {
        int p = 0;
        for (int i = 63; i >= 0; i--) {
            int t = (x >> i) & 1;
            if(nds[p].nxt[t] == -1) {
                nds[p].nxt[t] = newnode();
            }
            p = nds[p].nxt[t];
            nds[p].num++;
        }
    }
    
    ll querry(ll x, int k) {
        int p = 0;
        ll res = 0;
        for (int i = 63; i >= 0; i--) {
            int t = (x >> i) & 1;
            int num = 0;
            if(nds[p].nxt[t^1] != -1) {
                num = nds[nds[p].nxt[t^1]].num;
            }
            if(num >= k) {
                res |= 1ll << i;
                p = nds[p].nxt[t^1];
            } else {
                k -= num;
                p = nds[p].nxt[t];
            }
        }
        return res;
    }
    
}trie;


vector<pil> G[maxn];
ll A[maxn];
int n, m;

void cal(int u, int fa, ll dist) {
    A[u] = dist;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i].xx;
        if(v == fa) continue;
        cal(v, u, dist ^ G[u][i].yy);
    }
}
const int maxk = 2e5 + 5;
ll ans[maxk];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1 && n) {
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 1; i <= n - 1; i++) {
            int u, v;
            ll w;
            scanf("%d%d%lld", &u, &v, &w);
            G[u].push_back(pil(v, w));
            G[v].push_back(pil(u, w));
        }
        memset(A, 0, sizeof(A));
        cal(1, -1, 0);
        trie.init();
        for (int i = 1; i <= n; i++) {
            trie.insert(A[i]);
        }
        priority_queue<pair<ll, pli> > que;
        for (int i = 1; i <= n; i++) {
            ll t = trie.querry(A[i], 1);
            que.push(make_pair(t, pli(A[i], 1)));
        }
        memset(ans, -1, sizeof(ans));
        int i = 1;
        ll tot = ll(n) * (n - 1);
        while(!que.empty() && i <= tot && i < maxk) {
            pair<ll, pli> cur = que.top(); que.pop();
            ans[i++] = cur.xx;
            if(cur.yy.yy == n - 1) continue;
            ll t = trie.querry(cur.yy.xx, cur.yy.yy + 1);
            que.push(make_pair(t, pli(cur.yy.xx, cur.yy.yy + 1)));
        }
        
        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            int x; scanf("%d", &x);
            cout << ans[x] << endl;
        }
    }
    return 0;
}
```


---
title: 暑期集训-7-11-h
date: 2016-09-11 15:21:05
tags:
- ACM
- 2016 暑期集训
- HDU
- BIT
categories:
- 2016暑期集训
---
## 题意
给定一个序列，询问对于[l,r]之间，有多少个数字与区间内其他所有数字互质

## 做法
用筛法预处理出每个数向左和向右最近与其不互质的数的位置L[i],R[i]。这样对于每个位置i，都对应一个区间[L[i],R[i]],对于一个询问，等价于[l,r]内，有多少个位置i,[L[i],R[i]]区间包含[l,r]。这样就转化为区间覆盖问题，对询问的R进行排序，然后从左往右扫，碰到i则i位置+1，L[i]位置-1，碰到R,贼i位置-1，L[i]位置+1，然后查询[l,r]区间和就是答案。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 2e5 + 5;
struct BIT {
    int bit[maxn + 1];
    int n;
    void init(int n) {
        this->n = n;
        memset(bit, 0, sizeof(bit));
    }
    
    void update(int i, int add) {
        for (; i <= n; i += lowbit(i)) {
            bit[i] += add;
        }
    }
    
    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= lowbit(i)) {
            res += bit[i];
        }
        return res;
    }
    
    int querry(int l, int r) {
        return sum(r) - sum(l - 1);
    }
}bit;

struct Inter {
    int l, r, num;
    Inter(int l, int r):l(l), r(r) {}
    Inter() {}
    Inter(int l, int r, int num):l(l), r(r), num(num) {}
};

bool cmp(const Inter &a, const Inter &b) {
    return a.r < b.r;
}

vector<Inter> Querry, inters[3];
int n, m;
int cnt[3][maxn], tot[maxn];
int A[maxn];
bool isprime[maxn];
int fact_pos[maxn];
int L[maxn], R[maxn];
vector<int> primes;

void get_prime() {
    memset(isprime, true, sizeof(isprime));
    for (int i = 2; i < maxn; i++) {
        if(isprime[i]) {
            primes.push_back(i);
            for (int j = i + i; j < maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
}


void cal(int ind) {
    sort(inters[ind].begin(), inters[ind].end(), cmp);
    bit.init(maxn-1);
    for (int i = 0, j = 0; i < (int)Querry.size(); i++) {
        for (; j < (int)inters[ind].size() && inters[ind][j].r <= Querry[i].r; j++) {
            // prln("ok");
            bit.update(inters[ind][j].l + 1, 1);
        }
        cnt[ind][Querry[i].num] = bit.querry(Querry[i].l + 1, Querry[i].r + 1);
    }
}

void solve() {
    memset(fact_pos, 0, sizeof(fact_pos));
    for (int i = 1; i <= n; i++) L[i] = 0;
    for (int i = 1; i <= n; i++) {
        int x = A[i];
        // prln(x);
        for (int j = 0; primes[j] * primes[j] <= x; j++) {
            if(x % primes[j] == 0) {
                L[i] = max(L[i], fact_pos[primes[j]]);
                fact_pos[primes[j]] = i;
            }
            while(x % primes[j] == 0) {
                x /= primes[j];
            }
        }
        if(x > 1) {
            L[i] = max(L[i], fact_pos[x]);
            fact_pos[x] = i;
        }
    }
    
    for (int i = 0; i < maxn; i++) fact_pos[i] = n + 1;
    for (int i = 1; i <= n; i++) R[i] = n + 1;
    for (int i = n; i >= 1; i--) {
        int x = A[i];
        for (int j = 0; primes[j] * primes[j] <= x; j++) {
            if(x % primes[j] == 0) {
                R[i] = min(R[i], fact_pos[primes[j]]);
                fact_pos[primes[j]] = i;
            }
            
            while(x % primes[j] == 0) {
                x /= primes[j];
            }
        }
        if(x > 1) {
            R[i] = min(R[i], fact_pos[x]);
            fact_pos[x] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        // pr(L[i]); pr(i); prln(R[i]);
        inters[0].push_back(Inter(L[i], i));
        inters[1].push_back(Inter(i, R[i]));
        inters[2].push_back(Inter(L[i], R[i]));
    }
    for (int i = 0; i < 3; i++) {
        cal(i);
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    get_prime();
    while(scanf("%d%d", &n, &m) == 2 && n && m) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        Querry.clear();
        for (int i = 0; i < 3; i++) {
            inters[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            Querry.push_back(Inter(l, r, i));
            tot[i] = r - l + 1;
        }
        sort(Querry.begin(), Querry.end(), cmp);
        solve();
        for (int i = 1; i <= m; i++) {
            // pr(tot[i]); pr(cnt[0][i]); pr(cnt[1][i]); prln(cnt[2][i]);
            printf("%d\n", tot[i] - cnt[0][i] - cnt[1][i] + cnt[2][i]);
        }
    }
    return 0;
}
```



---
title: 暑期集训-7-11-i
date: 2016-09-11 15:37:37
tags:
- ACM
- 2016 暑期集训
- HDU
- dp
- 博弈
categories:
- 2016暑期集训
---

## 题意
HDU 4778
有G种颜色，B个背包，每个背包有n个宝石，颜色分别为ci.两人轮流取背包放到公共容器里面，当容器有s个相同颜色宝石时，这s个宝石就会融合成一个魔法师。当选手这一步操作产生魔法师时，选手可以再选一个背包，直到不产生魔法石，每个背包只能用一次。每个选手都会尽量使自己得到的魔法师最多，求先手得到的魔法师-后手得到的模仿是

## 做法
因为数据比较小，考虑状态压缩，当我们知道还剩下哪些背包，我们可以算出已经合成了多少个魔法石，容器里各个颜色还有多少个，所以我们dp[mask]表示还剩下的背包状态，当前先手最多可以获得多少个魔法石，对手能获得的魔法石=已经产生的魔法石-dp[mask],然后dp一下即可。还是很有趣的一个题目
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxb = 21;
const int maxg = 8;
const int maxn = 10;
int G, B, S;
int dp[1<<maxb];
int bags[maxb][maxn];
int colors[maxg];
int tot;
int dfs(int mask) {
    // pr(mask); prln(turn);
    //turn:
    if(dp[mask] != -1) return dp[mask];
    int already_have = 0;
    int t_colors[maxg];
    memset(t_colors, 0, sizeof(t_colors));
    for (int i = 0; i < B; i++) {
        if((mask>>i) & 1) {
            for (int j = 0; j < G; j++) {
                t_colors[j] += bags[i][j];
            }
        }
    }
    
    for (int i = 0; i < G; i++) {
        already_have += t_colors[i] / S;
        t_colors[i] %= S;
    }
    
    // prln(already_have);
    int buf[maxg];
    int res = 0;
    for (int i = 0; i < B; i++) {
        if(!((mask >> i) & 1)) {
            memcpy(buf, t_colors, sizeof(buf));
            for (int j = 0; j < G; j++) {
                buf[j] += bags[i][j];
            }
            int cnt_new_gems = 0;
            for (int j = 0; j < G; j++) {
                cnt_new_gems += buf[j] / S;
            }
            if(cnt_new_gems > 0) {
                res = max(res,  cnt_new_gems + dfs((mask|(1<<i))));
            } else {
                res = max(res, tot - already_have - dfs((mask|(1<<i))));
            }
        }
    }
    return dp[mask] = res;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d%d", &G, &B, &S) == 3 && G && B && S) {
        memset(bags, 0, sizeof(bags));
        memset(colors, 0, sizeof(colors));
        for (int i = 0; i < B; i++) {
            int n; scanf("%d", &n);
            for (int j = 0; j < n; j++) {
                int x; scanf("%d", &x);
                x--;
                bags[i][x]++;
                colors[x]++;
            }
        }
        tot = 0;
        for (int i = 0; i < G; i++) {
            tot += colors[i] / S;
        }
        memset(dp, -1, sizeof(dp));
        int a = dfs(0);
        int b = tot - a;
        // prln(tot);
        // pr(a); prln(b);
        printf("%d\n", a - b);
    }
    return 0;
}

```

---
title: 暑期集训-7-13-a
date: 2016-09-11 15:56:46
tags:
- ACM
- 2016 暑期集训
- POJ
- Tarjan
categories:
-	2016暑期集训
---

## 题意
POJ 1523
给定无向图，求割点，和割点的联通块

## 做法
Tarjan莽一波，这题输入特别无聊！！！！
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1000 + 5;
vector<int> G[maxn];
int low[maxn], dfn[maxn], dfsNum;
int cnt[maxn];

void dfs(int u) {
    dfn[u]= low[u] = ++dfsNum;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(dfn[v] == -1) {
            dfs(v);
            if(u == 1) cnt[u]++;
            if(u != 1 && low[v] >= dfn[u]) cnt[u]++;
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}


int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int u, v;
    int Case = 0;
    while(scanf("%d", &u) == 1 && u) {
        for (int i = 0; i < maxn; i++) G[i].clear();
        scanf("%d", &v);
        G[u].push_back(v);
        G[v].push_back(u);
        while(scanf("%d", &u) && u) {
            scanf("%d", &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(dfn, -1, sizeof(dfn));
        dfsNum = 0;
        memset(cnt, 0, sizeof(cnt));
        dfs(1);
        cnt[1]--;
        bool flag = false;
        if(Case > 0) puts("");
        printf("Network #%d\n", ++Case);
        for (int i = 1; i < maxn; i++) {
            if(cnt[i] > 0) {
                printf("  SPF node %d leaves %d subnets\n", i, cnt[i] + 1);
                flag = true;
            }
        }
        if(!flag) {
            printf("  No SPF nodes\n");
        }
    }
    return 0;
}
```

---
title: 暑期集训-7-13-b
date: 2016-09-11 15:59:21
tags:
- ACM
- 2016 暑期集训
- HDU
- 割点
- Tarjan
categories:
- 2016暑期集训
---

## 题意
HDU 3671
给定一个无向图，去掉两点后剩下的图不在联通，求一共有多少种情况。

## 做法
枚举去掉一个点，然后分类讨论，对于还联通的情况跑次tarjan计算割点数量，这里需要注意讨论一些特殊情况，否则很容易wa。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1000 + 5;
vector<int> G[maxn];
int cnt[maxn];
int root;
int low[maxn], dfn[maxn], dfsNum;
int used[maxn];
int n, m;
const int maxm = 1e4 + 5;
int U[maxm], V[maxm];
void dfs(int u, int pass) {
    low[u] = dfn[u] = ++dfsNum;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == pass) continue;
        if(dfn[v] == -1) {
            dfs(v, pass);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]) {
                cnt[u]++;
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void init() {
    for (int i = 0; i <= n; i++) G[i].clear();
    for (int i = 0; i < m; i++) {
        int u = U[i], v = V[i];
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

int count_cut(int u) {
    memset(cnt, 0, sizeof(cnt));
    memset(dfn, -1, sizeof(dfn));
    dfsNum = 0;
    int pass;
    if(u != 1) {
        root = 1;
        pass = u;
    } else {
        root = 2;
        pass = u;
    }
    dfs(root, pass);
    cnt[root]--;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if(cnt[i] > 0) {
            res++;
        }
    }
    return res;
}

int dfs2(int u, int pass) {
    used[u] = 1;
    int res = 1;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(used[v] || v == pass) continue;
        res += dfs2(v, pass);
    }
    return res;
}
vector<int> count_part(int pass) {
    memset(used, 0, sizeof(used));
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if(i == pass) {
            continue;
        }
        if(!used[i]) {
            int t = dfs2(i, pass);
            res.push_back(t);
        }
    }
    return res;
}


int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Case = 0;
    while(scanf("%d%d", &n, &m) == 2) {
        if(n == 0 && m == 0) return 0;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &U[i], &V[i]);
        }
        // prln("ok");
        int res = 0;
        init();
        for (int i = 1; i <= n; i++) {
            int add = 0;
            vector<int> t = count_part(i);
            sort(t.begin(), t.end());
            if(t.size() > 2) {
                add = n - 1;
            }else if(t.size() == 2) {
                if(t[1] > 1 && t[0] == 1) {
                    add = t[1];
                } else if(t[1] > 1 && t[0] > 1) {
                    add = n - 1;
                }
            } else if(t.size() == 1) {
                add = count_cut(i);
            }
            res += add;
        }
        // pr(i); prln(add);
        printf("Case %d: %d\n", ++Case, res / 2);
    }
    return 0;
}
```


---
title: 暑期集训-7-13-e
date: 2016-09-11 16:05:18
tags:
- ACM
- 2016 暑期集训
- POJ
- 二分
categories:
- 2016暑期集训
---

## 题意
POJ 3122
N块，高度为1，半径为Ri的圆柱形奶酪，需要将这N块奶酪均分给F+1个人，每个人得到的体积相等，求每个人能够得到的最大奶酪体积

## 做法
读懂题意后，二分即可。难点在题意
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const double pi = acos(-1.0);
const int maxn = 1e4 + 5;
double R[maxn];
int N, F;
bool judge(double v) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += floor(R[i] * R[i] * pi / v);
    }
    return cnt >= (F+1);
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Case = 1; Case <= T; Case++) {
        scanf("%d%d", &N, &F);
        for (int i = 0; i < N; i++) {
            scanf("%lf", &R[i]);
        }
        
        double l = 0, r = 1e15;
        for (int i = 0; i < 250; i++) {
            double m = (l + r) / 2;
            if(judge(m)) {
                l = m;
            } else {
                r = m;
            }
        }
        printf("%.4lf\n", l);
    }
    return 0;
}

```


---
title: 暑期集训-7-13-f
date: 2016-09-11 16:11:41
tags:
- ACM
- 2016 暑期集训
- POJ
- 二分
categories:
- 2016暑期集训
---
## 题意
最大化平均值

## 做法
把等式变形，把求最值问题转化为判定性问题，然后二分，很经典的套路.
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const double eps = 1e-9;
const int maxn = 1e5 + 5;
struct Node {
    int v, w, num;
    double x;
    Node() {}
}A[maxn];

bool cmp(const Node &a, const Node &b) {
    return a.x > b.x;
}

int n, k;
bool judge(double x) {
    for (int i = 0; i < n; i++) {
        A[i].x = A[i].v - x * A[i].w;
    }
    sort(A, A + n, cmp);
    double res = 0;
    for (int i = 0; i < k; i++) {
        res += A[i].x;
    }
    return res >= 0;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &n, &k) == 2) {
        double l = 0, r = 1e9;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &A[i].v, &A[i].w);
            A[i].num = i;
        }
        while(r - l > eps) {
            double m = (l + r) / 2;
            if(judge(m)) {
                l = m + eps;
            } else {
                r = m - eps;
            }
        }
        judge(l);
        for (int i = 0; i < k; i++) {
            printf("%d%c", A[i].num + 1, i == k - 1 ? '\n' : ' ');
        }
    }
    return 0;
}

```


---
title: 暑期集训-7-13-g
date: 2016-09-11 16:14:33
tags:
- ACM
- 2016 暑期集训
- POJ
- 二分
categories:
- 2016暑期集训
---

## 题意
POJ 3579
给定一个长度为n的序列，求两两之间差值绝对值的中位数

## 做法
转化为判定性问题，二分。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e5 + 5;
int X[maxn];
ll tot;
int n;

bool judge(int x) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        int t = X[i] + x;
        int p = upper_bound(X + i + 1, X + n, t) - X;
        cnt += p - i - 1;
    }
    return cnt < tot;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1) {
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &X[i]);
            r = max(r, X[i]);
        }
        r += 1;
        sort(X, X + n);
        tot = ll(n) * (n - 1) / 2;
        tot = (tot + 1) / 2;
        while(l < r - 1) {
            int m = (l + r) >> 1;
            if(judge(m)) {
                l = m;
            } else {
                r = m;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}

```


---
title: 暑期集训-7-13-h
date: 2016-09-11 16:19:50
tags:
- ACM
- 2016 暑期集训
- POJ
- 二分
categories:
- 2016暑期集训
---
## 题意
POJ 3484
给出N个X Y Z组合，其中X Y Z组合能够输出，X, X + Z,..,X + K * Z(X + K * Z <= Y)，问这些数中，有哪个数输出奇数次。题目保证，只有一个数输出奇数次

## 做法
这是一道非常脑筋急转弯的一题。假设一个数K，那么所有小于K的数出现次数之和为偶数，对于x >= K,那么所有小于等于x的数出现次数之和为奇数，那么我们二分即可。
这题读题和想到这个性质是难点。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const ll inf = 1ll << 32;
const int maxn = 1e6 + 5;
char str[100];
ll X[maxn], Y[maxn], Z[maxn];
int n;

ll count(ll x) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if(X[i] > x) continue;
        else {
            res += (min(x, (ll)Y[i]) - X[i]) / Z[i] + 1;
        }
    }
    return res;
}

ll count2(ll x) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if(x < X[i] || x > Y[i]) continue;
        else {
            if((x - X[i]) % Z[i] == 0) res++;
        }
    }
    return res;
}

bool judge(ll x) {
    ll res = count(x);
    return res % 2 == 1;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(gets(str) && str[0] == 0);
    while(true) {
        n = 0;
        sscanf(str, "%lld%lld%lld", &X[n], &Y[n], &Z[n]);
        n++;
        while(gets(str) && str[0]) {
            // prln(str);
            sscanf(str, "%lld%lld%lld", &X[n], &Y[n], &Z[n]);
            n++;
        }
        ll l = -1, r = inf;
        while(l < r - 1) {
            ll m = (l + r) >> 1;
            if(judge(m)) {
                r = m;
            } else l = m;
        }
        if(r == inf) {
            printf("no corruption\n");
        } else {
            printf("%lld %lld\n", r, count2(r));
        }
        int flag = 0;
        while(gets(str)) {
            flag++;
            if(str[0] != 0) break;
        }
        if(flag == 0 || str[0] == 0) return 0;
    }
    return 0;
}

```

---
title: 暑期集训-7-13-j
date: 2016-09-11 19:29:31
tags:
- ACM
- 2016 暑期集训
- POJ
- 构造
categories:
- 2016暑期集训
---
## 题意
一个用1..n组成的序列{An} 如果Ai - i是0..n-1组成的序列，那么{An}被称为完美序列。给定n，问能否构造出完美序列{An},如果能输出这个序列

## 做法
不知道为啥，反正这样凑能ac....
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1000 + 5;
int used[2][maxn];
int n;
bool dfs(int d) {
    if(d < 0) {
        return true;
    }
    for (int i = 1; i <= n; i++) {
        if(!used[0][i]) {
            if(i + d <= n && !used[1][i+d]) {
                used[0][i] = i + d;
                used[1][i+d] = i;
                if(dfs(d - 1)) {
                    return true;
                } else {
                    used[0][i] = 0;
                    used[1][i+d] = 0;
                }
            }
            if(i - d >= 1 && !used[1][i-d]) {
                used[0][i] = i - d;
                used[1][i-d] = i;
                if(dfs(d - 1)) {
                    return true;
                } else {
                    used[0][i] = 0;
                    used[1][i-d] = 0;
                }
            }
        }
    }
    return false;
}


void work(int x) {
    n = x;
    printf("{\n");
    if(n % 4 == 2 || n % 4 == 3) {
        printf("0,\n");
    } else {
        memset(used, 0, sizeof(used));
        bool suc = dfs(n - 1);
        prln(suc);
        for (int i = 1; i <= n; i++) {
            printf("%d,\n", used[0][i]);
        }
    }
    printf("-1\n},\n");
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for (int i = 1; i <= 1000; i++) {
        work(i);
    }
    return 0;
}

```


---
title: 暑期集训-7-13-k
date: 2016-09-11 16:11:28
tags:
- ACM
- 2016 暑期集训
- UVA
- 模拟题
categories:
- 2016暑期集训
---
## 题意
UVA 401
模拟题

## 做法
模拟
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
map<char, char> mp;

void init() {
    mp['A'] = 'A';
    mp['E'] = '3';
    mp['H'] = 'H';
    mp['I'] = 'I';
    mp['J'] = 'L';
    mp['L'] = 'J';
    mp['M'] = 'M';
    mp['O'] = 'O';
    mp['S'] = '2';
    mp['T'] = 'T';
    mp['U'] = 'U';
    mp['V'] = 'V';
    mp['W'] = 'W';
    mp['X'] = 'X';
    mp['Y'] = 'Y';
    mp['Z'] = '5';
    mp['1'] = '1';
    mp['2'] = 'S';
    mp['3'] = 'E';
    mp['5'] = 'Z';
    mp['8'] = '8';
}
const int maxn = 200 + 5;
char str[maxn];
char buf[maxn];
bool ismirroed(int len) {
    for (int i = 0; i < len; i++) {
        if(mp.find(str[i]) != mp.end()) {
            buf[i] = mp[str[i]];
        } else return false;
    }
    for (int i = 0; i < len; i++) {
        if(str[i] != buf[len - 1 - i]) {
            return false;
        }
    }
    return true;
}
bool ispali(int len) {
    for (int i = 0; i < len; i++) {
        if(str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}
char ans[4][100] = {
    "is not a palindrome.",
    "is a regular palindrome.",
    "is a mirrored string.",
    "is a mirrored palindrome."
};

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    while(scanf("%s", str) == 1) {
        int len = strlen(str);
        printf("%s -- ", str);
        int a1 = ispali(len), a2 = ismirroed(len);
        printf("%s\n", ans[a1 | (a2 << 1)]);
        puts("");
    }
    return 0;
}

```


---
title: 暑期集训-7-13-l
date: 2016-09-11 19:35:46
tags:
- ACM
- 2016 暑期集训
- UVA
- 插头dp
categories:
- 2016暑期集训
---

## 题意
UVA 11270
求用1\*2的木块将n\*m的矩阵填满的方案数。

## 做法
插头dp经典题
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 100;
ll dp[maxn][1<<10];
int n, m;
void dfs(int x, int pos, int cur, int mask) {
    if(pos >= n) {
        // prln(mask);
        dp[cur+1][mask] += dp[cur][x];
        return;
    }
    if((x >> pos) & 1) {
        dfs(x, pos + 1, cur, mask);
    }
    if(!((x >> pos) & 1)) {
        dfs(x, pos + 1, cur, mask | (1 << pos));
    }
    if(pos < n - 1 && !((x >> pos) & 1) &&
       !((x >> (pos + 1)) & 1)) {
        dfs(x, pos + 2, cur, mask);
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &n, &m) == 2) {
        if(n > m) swap(n, m);
        for (int i = 0; i <= m + 1; i++) {
            for (int j = 0; j < (1<<n); j++) {
                dp[i][j] ^= dp[i][j];
            }
        }
        
        dp[1][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < (1<<n); j++) {
                if(dp[i][j] > 0) dfs(j, 0, i, 0);
            }
        }
        printf("%lld\n", dp[m+1][0]);
    }
    return 0;
}
```


---
title: 暑期集训-7-13-m
date: 2016-09-11 19:39:13
tags:
- ACM
- 2016 暑期集训
- POJ
- 贪心
categories:
- 2016暑期集训
---

## 题意
一辆卡车要行驶L单位的距离。卡车初始有P单位油，行驶1单位距离花费1单位油。途中有N个加油站，加油站汽油有限，卡车油箱无限。给出加油站的位置和油量，问卡车从起点到终点至少要加几次油。

## 做法
考虑贪心，把卡车能够经过的加油站的油量压进优先队列，油空时取最大的油量来加。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e6 + 5;
int N;
int sta[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &N) == 1) {
        memset(sta, 0, sizeof(sta));
        for (int i = 0; i < N; i++) {
            int l, p; scanf("%d%d", &l, &p);
            sta[l] = p;
            // prln(sta[l]);
        }
        priority_queue<int> que;
        int L, P; scanf("%d%d", &L, &P);
        int ans = 0;
        for (int i = L; i > 0; i--) {
            if(sta[i] > 0) {
                que.push(sta[i]);
            }
            while(P <= 0 && !que.empty()) {
                int cur = que.top(); que.pop();
                P += cur;
                ans++;
            }
            if(P <= 0) {
                ans = -1;
                break;
            }
            P--;
        }
        printf("%d\n", ans);
    }
    return 0;
}

```

---
title: 暑期集训-7-13-p
date: 2016-09-11 19:44:37
tags:
- ACM
- 2016 暑期集训
- Codeforces
- 数学
categories:
- 2016暑期集训
---
## 题意
Codeforces 468C
```cpp
ans = solve(l, r) % a;
if (ans <= 0)
ans += a;
```
给出a，找到[l,r] 使得ans = 0

## 做法
f(x + 1e18) = f(x) + 1,所以solve(x + 1, x + 1e18) = solve(x, x + 1e18-1) + 1
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const ll x = 1e17;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ll a;
    cin >> a;
    ll d = 5 * (9 * (18 * x % a) % a) % a;
    d = a - d;
    cout << d  << " " << x * 10 - 1 + d << endl;
    return 0;
}

```


---
title: 暑期集训-7-13-r
date: 2016-09-11 19:51:22
tags:
- ACM
- 2016 暑期集训
- SOJ
- 数学
categories:
- 2016暑期集训
---

## 题意
求1/n的循坏节长度

## 做法
暴力
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 1e7 + 5;
int used[maxn];
pii work(int n) {
    for (int i = 0; i <= n; i++) used[i] = -1;
    int cnt = 0;
    int x = 1 % n;
    while(true) {
        if(used[x] != -1) {
            return pii(used[x], cnt - used[x]);
        }
        if(x == 0) {
            return pii(cnt, 0);
        }
        used[x] = cnt;
        x = x * 10 % n;
        cnt++;
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        pii ans = work(n);
        printf("%d %d\n", ans.xx, ans.yy);
    }
    return 0;
}

```


---
title: 暑期集训-7-15-b
date: 2016-09-11 19:55:09
tags:
- ACM
- 2016 暑期集训
- HDU 4775
- 模拟
categories:
- 2016暑期集训
---
## 题意
HDU 4775
模拟围棋

## 做法
并查集模拟
<!--more-->

## 代码
```cpp
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
typedef pair<ll, ll> pll;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
map<pll, int> board;
// 0 表示黑， 1 表示白
struct DSU {
    map<pll, pll> par;
    map<pll, ll> cnt;
    
    void init() {
        par.clear();
        cnt.clear();
    }
    
    void erase(pll pos) {
        par.erase(par.find(pos));
        cnt.erase(cnt.find(pos));
    }
    
    ll get_liberty(pll pos) {
        pos = find(pos);
        return cnt[pos];
    }
    
    pll find(pll x) {
        if(par.find(x) == par.end()) {
            par[x] = x;
            cnt[x] = 0;
        }
        if(par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }
    
    void modify(pll pos, int add) {
        pos = find(pos);
        cnt[pos] += add;
    }
    
    void merge(pll a, pll b) {
        a = find(a), b = find(b);
        cnt[a] += cnt[b];
        par[b] = a;
    }
}dsu;

void push(pll pos, int color) {
    int x = pos.xx, y = pos.yy;
    int add = 4;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(nx == 0 || ny == 0) add--;
        if(board.find(pll(nx, ny)) != board.end()) {
            dsu.modify(pll(nx, ny), -1);
            add--;
            if(board[pll(nx, ny)] == color) {
                dsu.merge(pos, pll(nx, ny));
            }
        }
    }
    board[pos] = color;
    dsu.modify(pos, add);
}

void dfs(pll pos, int color) {
    board.erase(board.find(pos));
    dsu.erase(pos);
    int x = pos.xx, y = pos.yy;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(board.find(pll(nx, ny)) != board.end()) {
            if(board[pll(nx, ny)] == color) {
                dfs(pll(nx, ny), color);
            } else {
                dsu.modify(pll(nx, ny), 1);
            }
        }
    }
}

void check(pll pos, int color) {
    int x = pos.xx, y = pos.yy;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(board.find(pll(nx, ny)) != board.end()) {
            if(board[pll(nx, ny)] != color &&
               dsu.get_liberty(pll(nx, ny)) == 0) {
                dfs(pll(nx, ny), board[pll(nx, ny)]);
            }
        }
    }
    if(dsu.get_liberty(pos) == 0) {
        dfs(pos, color);
    }
}

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        board.clear();
        dsu.init();
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            int color = i % 2;
            push(pll(x, y), color);
            check(pll(x, y), color);
        }
        map<pll, int>::iterator it;
        int cnt_b = 0, cnt_w = 0;
        for (it = board.begin(); it != board.end(); it++) {
            // printf("%lld %lld: %d\n", it->xx.xx, it->xx.yy, it->yy);
            // printf("%lld\n", dsu.get_liberty(it->xx));
            if(it->yy == 0) cnt_b++;
            else cnt_w++;
        }
        printf("%d %d\n", cnt_b, cnt_w);
    }
    return 0;
}

```


---
title: 暑期集训-7-15-g
date: 2016-09-11 20:00:31
tags:
- ACM
- 2016 暑期集训
- UVA
- 最大流
categories:
- 2016暑期集训
---
## 题意
UVA 11082
给出矩阵前i行，前j列之和，求出一个满足题意的矩阵。矩阵元素值在1~20范围。n,m最大为20

## 做法
经典网络流题目。注意对于每条边-1,就可以解决0流的问题。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int inf = 0x3f3f3f3f;
const int maxn = 300 + 5;
const int maxv = 300 + 5;
int d[maxn][maxn];

struct Dinic {
    struct edge {
        int to, cap, rev;
        edge() {}
        edge(int to, int cap, int rev):to(to), cap(cap), rev(rev) {}
    };
    
    vector<edge> G[maxv];
    int num_v;
    int level[maxv];
    int iter[maxv];
    
    void add_edge(int from, int to, int cap) {
        G[from].push_back(edge(to, cap, (int)G[to].size()));
        G[to].push_back(edge(from, 0, (int)G[from].size() - 1));
    }
    
    void init(int num_v) {
        this->num_v = num_v;
        for (int i = 0; i <= num_v; i++) G[i].clear();
    }
    
    void bfs(int s) {
        memset(level, -1, sizeof(level));
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()) {
            int v = que.front(); que.pop();
            for (int i = 0; i < (int)G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < (int)G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if( d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    
    int max_flow(int s, int t) {
        int flow = 0;
        for (;;) {
            bfs(s);
            if(level[t] < 0) return flow;
            memset(iter, 0, sizeof(iter));
            int f;
            while((f = dfs(s, t, inf)) > 0) {
                flow += f;
            }
        }
    }
}dinic;

int A[maxn];
int ans[maxn][maxn];
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int n, m;
        scanf("%d%d", &n, &m);
        int s = n + m + 1, t = s + 1;
        dinic.init(t + 1);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            dinic.add_edge(s, i, A[i] - A[i-1] - m);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &A[i]);
            dinic.add_edge(n + i, t, A[i] - A[i-1] - n);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dinic.add_edge(i, j + n, 19);
            }
        }
        int tmp = dinic.max_flow(s, t);
        // prln(tmp);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (int)dinic.G[i].size(); j++) {
                int u = i, v = dinic.G[i][j].to - n;
                if(v > m) continue;
                int c = 19 - dinic.G[i][j].cap + 1;
                ans[u][v] = c;
            }
        }
        printf("Matrix %d\n", Cas);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%d%c", ans[i][j], j == m ? '\n' : ' ');
            }
        }
    }
    return 0;
}

```


---
title: 暑期集训-7-15-j
date: 2016-09-11 20:06:47
tags:
- ACM
- 2016 暑期集训
- Codeforces
- 计算几何
categories:
- 2016暑期集训
---

## 题意
蟑螂有T时间，往各个方向跑，一些地方有半径为R的阴影，蟑螂在T时间内如果能够跑到阴影部分就安全。蟑螂一开始是随机往各个方向跑。问蟑螂安全的概率。

## 做法
枚举每个阴影部分，算出安全的角度区间，然后求区间并。
<!--more-->

## 代码
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e5 + 5;
const double eps = 1e-8;
const double pi = acos(-1.0);

int sign(long double x) {
    if(x < -eps) return -1;
    else if(x > eps) return 1;
    else return 0;
}

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y):x(x), y(y) {}
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
    double length() {
        return sqrt(x * x + y * y);
    }
    
    void read() {
        scanf("%lf%lf", &x, &y);
    }
};

double dis(Point a, Point b) {
    return (b - a).length();
}

long double sqrDis(Point a, Point b) {
    Point t = b - a;
    return (long double)t.x * t.x + t.y * t.y;
}

struct Circle {
    Point center;
    double r;
    Circle() {}
    Circle(Point center, double r):center(center), r(r) {};
    void read() {
        center.read();
        scanf("%lf", &r);
    }
};

bool isInCircle(Point p, Circle c) {
    return sign(sqrDis(p, c.center) - c.r * c.r) <= 0;
}

double cosc(double a, double b, double c) {
    return (a * a + b * b - c * c) / (2 * a * b);
}

Circle circles[maxn];
Point p;
double v, T, R;
int n;

vector<pair<double, int> > V;

double cal_range() {
    sort(V.begin(), V.end());
    double last;
    double res = 0;
    int cnt = 0;
    for (int i = 0; i < (int)V.size(); i++) {
        if(cnt > 0) {
            res += V[i].xx - last;
        }
        last = V[i].xx;
        cnt += V[i].yy;
    }
    return res;
}

void add_interval(double l, double r) {
    V.push_back(make_pair(l, 1));
    V.push_back(make_pair(r, -1));
}

double tangent_length(Point p, Circle c) {
    double d = dis(p, c.center);
    return sqrt(d * d - c.r * c.r);
}

bool isIntersect(Circle a, Circle b) {
    double d = sqrDis(a.center, b.center);
    return sign(d - (a.r + b.r) * (a.r + b.r)) < 0;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    p.read();
    scanf("%lf%lf", &v, &T);
    R = v * T;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        circles[i].read();
    }
    for (int i = 0; i < n; i++) {
        if(isInCircle(p, circles[i])) {
            // prln("fuck");
            printf("%.9f\n", 1.0);
            return 0;
        }
        
        if(!isIntersect(Circle(p, R), circles[i])) {
            continue;
        }
        
        double tangent = tangent_length(p, circles[i]);
        double d = dis(p, circles[i].center);
        double ang, mid;
        mid = atan2((circles[i].center - p).y,
                    (circles[i].center - p).x);
        if(R >= tangent) {
            ang = asin(circles[i].r / d);
        } else {
            ang = acos(cosc(R, d, circles[i].r));
        }
        double up = fmod(mid + ang + 2 * pi, 2 * pi);
        double down = fmod(mid - ang + 2 * pi, 2 * pi);
        // pr(down); prln(up);
        if(sign(down - up) <= 0) {
            add_interval(down, up);
        } else {
            add_interval(0, up);
            add_interval(down, 2 * pi);
        }
    }
    double range = cal_range();
    printf("%.9f\n", range / (2 * pi));
    return 0;
}
```


---
title: 暑期集训-7-15-k
date: 2016-09-11 20:10:44
tags:
- ACM
- 2016 暑期集训
- Codeforces
- 期望
categories:
- 2016暑期集训
---
## 题意
Codeforces 698B
给一颗有根数，求每个节点dfs序的期望

## 做法
这题的关键在于，对于任意兄弟节点a,b来说，先访问a在b之前访问的概率是1/2。
所以a对比的贡献是subtree(a) * 1/2，subtree(x)表示x为根节点的子树的节点数
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e5 + 5;
int subtree[maxn];
double E[maxn];
vector<int> G[maxn];
int n;
void dfs(int u) {
    subtree[u] = 1;
    for (int v: G[u]) {
        dfs(v);
        subtree[u] += subtree[v];
    }
}

void dfs2(int u) {
    for (auto v: G[u]) {
        E[v] = E[u] + 1 + (double)(subtree[u] - subtree[v] - 1) / 2;
        dfs2(v);
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p;
        scanf("%d", &p);
        G[p].push_back(i);
    }
    dfs(1);
    E[1] = 1;
    dfs2(1);
    for (int i = 1; i <= n; i++) {
        printf("%.9f%c", E[i], i == n ? '\n' : ' ');
    }
    return 0;
}
```

---
title: 暑期集训-7-15-l
date: 2016-09-11 20:17:48
tags:
- ACM
- 2016 暑期集训
- Codeforces
- 矩阵快速幂
categories:
- 2016暑期集训
---
## 题意
三个杯子，初始时有个物品在中间杯子里，在n此交换后，问物品在中间杯子的概率

## 做法
推出递推方程，用矩阵快速幂加速。
<!--more-->

## 代码
```cpp

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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const ll MOD = 1e9 + 7;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

ll mod_multiply(ll a, ll b, ll mod) {
    ll res = 0;
    while(b > 0) {
        if(b & 1) {
            res = (res + a) % mod;
        }
        b >>= 1;
        a = (a + a) % mod;
    }
    return res;
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    ll t = 1;
    ll flag = 1;
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        flag = (flag * a) % 2;
        t = mod_multiply(t, a, MOD - 1);
    }
    t = (t - 1 + MOD - 1) % (MOD - 1);
    ll p = mod_pow(2, t, MOD);
    ll q = p;
    if(flag == 0) p = (p + 1) % MOD;
    else p = (p - 1) % MOD;
    p = mod_multiply(p, mod_pow(3, MOD - 2, MOD), MOD);
    cout << p << "/" << q << endl;
    return 0;
}
```


---
title: 暑期集训-7-15-m
date: 2016-09-11 20:21:05
tags:
- ACM
- 2016 暑期集训
- Codeforces
- AC自动机
- 矩阵快速幂
categories:
- 2016暑期集训
---

## 题意
Codeforces 696D
给出一些模式串，构造一个长度不大于L的字符串，每个模式串有自己的价值，模式串每次出现都会有自己的贡献，求可能得到的最大的贡献值

## 做法
用AC自动机构造转移矩阵，然后矩阵快速幂加速，这里讲乘法改成取最大值即可
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 200 + 10;
struct Matrix {
    ll a[maxn][maxn];
    int n, m;
    Matrix() {
        n = m = 0;
        memset(a, -1, sizeof(a));
    }
    
    Matrix(int n, int m): n(n), m(m) {
        memset(a, -1, sizeof(a));
    }
    
    inline void I() {
        for (int i = 0; i < n; i++) a[i][i] = 0;
    }
    inline Matrix operator * (const Matrix &x) {
        Matrix res(n, x.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < x.m; j++) {
                for (int k = 0; k < m; k++) {
                    if(a[i][k] != -1 && x.a[k][j] != -1) {
                        res.a[i][j] = max(res.a[i][j], a[i][k] + x.a[k][j]);
                    }
                }
            }
        }
        return res;
    }
    void debug() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%lld ", a[i][j]);
            }
            puts("");
        }
    }
};

inline Matrix mat_pow(Matrix a, ll b) {
    Matrix c(a.n, a.m);
    c.I();
    while(b) {
        if(b & 1) {
            c = c * a;
        }
        a = a * a;
        b >>= 1;
    }
    return c;
}

char str[maxn][maxn];
ll n, l, A[maxn];
const int AC_SIGMA = 26, AC_N = 210;
struct AC_automaton {
    int next[AC_N][AC_SIGMA], fail[AC_N];
    ll end[AC_N];
    int root, L;
    int newnode() {
        for (int i = 0; i < AC_SIGMA; i++) {
            next[L][i] = -1;
        }
        end[L] = 0;
        return L++;
    }
    
    void init() {
        L = 0;
        root = newnode();
    }
    
    void insert(char buf[], int v) {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++) {
            if(next[now][buf[i] - 'a'] == -1) {
                next[now][buf[i] - 'a'] = newnode();
            }
            now = next[now][buf[i] - 'a'];
        }
        end[now] += v;
    }
    
    void build() {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < AC_SIGMA; i++) {
            if(next[root][i] == -1) {
                next[root][i] = root;
            } else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty()) {
            int now = Q.front();
            if(fail[now] != root) {
                end[now] += end[fail[now]];
            }
            Q.pop();
            for (int i = 0; i < 26; i++) {
                if(next[now][i] == -1) {
                    next[now][i] = next[fail[now]][i];
                } else {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
}ac;


int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%lld%lld", &n, &l);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
    }
    ac.init();
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i]);
        ac.insert(str[i], A[i]);
    }
    ac.build();
    Matrix dp(ac.L, ac.L);
    for (int i = 0; i < ac.L; i++) {
        for (int j = 0; j < 26; j++) {
            dp.a[ac.next[i][j]][i] = max(dp.a[ac.next[i][j]][i],
                                         ac.end[ac.next[i][j]]);
        }
    }
    Matrix ans(ac.L, 1);
    ans.a[0][0] = 0;
    dp = mat_pow(dp, l);
    // dp.debug();
    ans = dp * ans;
    ll res = 0;
    for (int i = 0; i < ac.L; i++) {
        res = max(res, ans.a[i][0]);
    }
    cout << res << endl;
    return 0;
}
```


---
title: 暑期集训-7-15-n
date: 2016-09-11 20:26:18
tags:
- ACM
- 2016 暑期集训
- Codeforces
- 模拟
categories:
- 2016暑期集训
---

## 题意
模拟
## 做法
模拟
<!--more-->
## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    int not_fastened = 0;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        if(x == 0) {
            not_fastened++;
        }
    }
    bool ok = true;
    if(n == 1 && not_fastened == 1) {
        ok = false;
    }
    if(n > 1 && not_fastened != 1) {
        ok = false;
    }
    if(ok) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

```



---
title: 暑期集训-7-15-o
date: 2016-09-11 20:30:54
tags:
- ACM
- 2016 暑期集训
- 模拟
categories:
- 2016暑期集训
---
## 题意
模拟

## 做法
模拟
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
map<char, char> mp;
void init() {
    mp['A'] = 'A';
    mp['b'] = 'd';
    mp['d'] = 'b';
    mp['H'] = 'H';
    mp['I'] = 'I';
    mp['M'] = 'M';
    mp['O'] = 'O';
    mp['o'] = 'o';
    mp['p'] = 'q';
    mp['q'] = 'p';
    mp['T'] = 'T';
    mp['U'] = 'U';
    mp['V'] = 'V';
    mp['v'] = 'v';
    mp['W'] = 'W';
    mp['w'] = 'w';
    mp['X'] = 'X';
    mp['x'] = 'x';
    mp['Y'] = 'Y';
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    string str;
    cin >> str;
    int len = (int)str.size();
    bool ok = true;
    for (int i = 0; i < len; i++) {
        if(mp.find(str[i]) == mp.end()) {
            ok = false;
            break;
        } else {
            if(mp[str[i]] != str[len - 1 - i]) {
                ok = false;
                break;
            }
        }
    }
    if(ok) printf("TAK\n");
    else printf("NIE\n");
    return 0;
}

```

---
title: 暑期集训-7-15-p
date: 2016-09-11 20:32:47
tags:
- ACM
- 2016 暑期集训
- 模拟
categories:
- 2016暑期集训
---

## 题意
模拟

## 做法
模拟
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

string str;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> str;
    int len = (int)str.size();
    int start = 0, point = len;
    while(start < len && (str[start] == '0' ||
                          str[start] == '.')) start++;
    for (int i = 0; i < len; i++) {
        if(str[i] == '.') {
            point = i;
        }
    }
    int end_int = start;
    for (int i = start; i < len; i++) {
        if(str[i] > '0' && str[i] <= '9') {
            end_int = i;
        }
    }
    if(start == len) {
        printf("0\n");
    } else {
        printf("%c", str[start]);
        if(end_int > start) {
            printf(".");
            for (int i = start + 1; i <= end_int; i++) {
                if(str[i] != '.') {
                    printf("%c", str[i]);
                }
            }
        }
        if(start != point - 1) {
            if(point > start) printf("E%d\n", point - start - 1);
            else printf("E%d\n", point - start);
        } else puts("");
    }
    return 0;
}

```


---
title: 暑期集训-7-15-q
date: 2016-09-11 20:34:05
tags:
- ACM
- 2016 暑期集训
- Codeforces
- sort
categories:
- 2016暑期集训
---
## 题意
给一个1..n的序列，和m个二元组(ai, bi),可以任意交换ai,bi位置上的数，求能够得到的最小字典序的序列

## 做法
把(ai,bi)看成边，每个位置看成点，任意连通块内的点都可以互换，所以这题就是求出连通块，对连通块内的数排个序就好
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e6 + 5;
int A[maxn];
bool used[maxn];
vector<int> G[maxn];
int n, m;
void dfs(int u, vector<int> &pos, vector<int> &val) {
    used[u] = true;
    pos.push_back(u); val.push_back(A[u]);
    for (auto v: G[u]) {
        if(!used[v]) {
            dfs(v, pos, val);
        }
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        vector<int> pos, val;
        if(!used[i]) {
            dfs(i, pos, val);
            sort(val.begin(), val.end(), greater<int>());
            sort(pos.begin(), pos.end());
            for (int i = 0; i < (int)pos.size(); i++) {
                A[pos[i]] = val[i];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d%c", A[i], i == n ? '\n' : ' ');
    }
    return 0;
}

```


---
title: 暑期集训-7-15-r
date: 2016-09-11 20:37:41
tags:
- ACM
- 2016 暑期集训
- Codeforces
- 矩阵快速幂
categories:
- 2016暑期集训
---
## 题意
给定一个长度为n的数组，从这个数组中选出k个数组成一个序列（每个数可以用多次），这个序列满足相邻另个数xor的二进制表示上1的个数是3的倍数，求方案数

## 做法
很明显的矩阵快速幂
<!--more-->
## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const ll MOD = 1e9 + 7;
const int maxn = 110;
struct Matrix {
    ll a[maxn][maxn];
    int n, m;
    Matrix() {
        n = m = 0;
        memset(a, 0, sizeof(a));
    }
    
    Matrix(int n, int m): n(n), m(m) {
        memset(a, 0, sizeof(a));
    }
    
    void I() {
        for (int i = 0; i < n; i++) a[i][i] = 1;
    }
    
    void zero() {
        memset(a, 0, sizeof(0));
    }
    
    Matrix operator * (const Matrix &b) const {
        Matrix res(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++) {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
                }
            }
        }
        
        return res;
    }
};

Matrix mat_pow(Matrix a, ll n) {
    Matrix res(a.n, a.m);
    res.I();
    while(n) {
        if(n & 1) {
            res = res * a;
        }
        a = a * a;
        n >>= 1;
    }
    return res;
}

ll A[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ll n, k;
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }
    Matrix dp(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(__builtin_popcountll(A[i] ^ A[j]) % 3 == 0) {
                dp.a[i][j] = 1;
            }
        }
    }
    
    dp = mat_pow(dp, k - 1);
    Matrix ans(n, 1);
    for (int i = 0; i < n; i++) ans.a[i][0] = 1;
    ans = dp * ans;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res = (res + ans.a[i][0]) % MOD;
    }
    printf("%lld\n", res);
    return 0;
}

```


---
title: 暑期集训-7-15-s
date: 2016-09-11 20:44:30
tags:
- ACM
- 2016 暑期集训
- Codeforces
- 暴力
categories:
- 2016暑期集训
---

## 题意
Codeforces 691F
## 做法
暴力
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 3e6 + 5;
int cnt[maxn];
ll sum[maxn];
int n, m;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
            if((ll)i * j >= maxn) {
                break;
            }
            if(i == j) sum[i*j] += (ll)cnt[i]*(cnt[i] - 1);
            else sum[i*j] += (ll)cnt[i] * cnt[j];
        }
    }
    for (int i = 1; i < maxn; i++) {
        sum[i] = sum[i] + sum[i-1];
    }
    
    scanf("%d", &m);
    ll tot = (ll)n * (n - 1);
    for (int i = 0; i < m; i++) {
        int p; scanf("%d", &p);
        printf("%lld\n", tot - sum[p-1]);
    }
    return 0;
}

```


---
title: 暑期集训-7-22-n
date: 2016-09-11 20:50:01
tags:
- ACM
- 2016 暑期集训
- 线段树
categories:
- 2016暑期集训
---
## 题意
线段树裸题

## 做法
线段树
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int MAXN = 2e5 + 5;

struct SegTree {
    int res[MAXN<<2];
    
    void push_up(int rt) {
        res[rt] = max(res[rt << 1], res[rt << 1 | 1]);
    }
    
    void build(int l, int r, int rt) {
        if(l == r) {
            scanf("%d", &res[rt]);
            return;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        push_up(rt);
    }
    
    int query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) {
            return res[rt];
        }
        int m = (l + r) >> 1;
        int tmp = 0;
        if(L <= m) tmp = max(tmp, query(L, R, lson));
        if(m < R ) tmp = max(tmp, query(L, R, rson));
        return tmp;
    }
    
    void modify(int p, int x, int l, int r, int rt) {
        if(l == p && r == p) {
            res[rt] = x;
            return;
        }
        int m = (l + r) >> 1;
        if(p <= m) modify(p, x, lson);
        if(m <  p) modify(p, x, rson);
        push_up(rt);
    }
}seg;
int N, M;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &N, &M) == 2) {
        seg.build(1, N, 1);
        for (int i = 0; i < M; i++) {
            char op[20];
            scanf("%s", op);
            if(op[0] == 'Q') {
                int A, B;
                scanf("%d%d", &A, &B);
                int res = seg.query(A, B, 1, N, 1);
                printf("%d\n", res);
            } else {
                int A, B;
                scanf("%d%d", &A, &B);
                seg.modify(A, B, 1, N, 1);
            }
        }
    }
    return 0;
}

```


---
title: 暑期集训-7-22-o
date: 2016-09-11 20:51:03
tags:
- ACM
- 2016 暑期集训
- 线段树
categories:
- 2016暑期集训
---

## 题意
线段树裸题

## 做法
线段树
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 50000 + 5;

struct SegTree {
    int sum[maxn << 2];
    
    void init() {
        memset(sum, 0, sizeof(sum));
    }
    
    void push_up(int rt) {
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    }
    
    void build(int l, int r, int rt) {
        if(l == r) {
            scanf("%d", &sum[rt]);
            return;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        push_up(rt);
    }
    
    void modify(int p, int add, int l, int r, int rt) {
        if(l == p && r == p) {
            sum[rt] += add;
            return;
        }
        int m = (l + r) >> 1;
        if(p <= m) modify(p, add, lson);
        if(m < p) modify(p, add, rson);
        push_up(rt);
    }
    
    int querry(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) {
            return sum[rt];
        }
        int m = (l + r) >> 1;
        int res = 0;
        if(L <= m) res += querry(L, R, lson);
        if(m <  R) res += querry(L, R, rson);
        return res;
    }
}segtree;

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        printf("Case %d:\n", Cas);
        int n; scanf("%d", &n);
        segtree.build(1, n, 1);
        char op[200];
        while(scanf("%s", op) == 1) {
            if(op[0] == 'Q') {
                int i, j;
                scanf("%d%d", &i, &j);
                printf("%d\n", segtree.querry(i, j, 1, n ,1));
            } else if(op[0] == 'A') {
                int i, j;
                scanf("%d%d", &i, &j);
                segtree.modify(i, j, 1, n, 1);
            } else if(op[0] == 'S') {
                int i, j;
                scanf("%d%d", &i, &j);
                segtree.modify(i, -j, 1, n, 1);
            } else {
                break;
            }
        }
    }
    return 0;
}

```


---
title: 暑期集训-7-22-t
date: 2016-09-11 20:53:16
tags:
- ACM
- 2016 暑期集训
- 最小生成树
- HDU
categories:
- 2016暑期集训
---

## 题意
HDU 1102
最小生成树裸题

## 做法
kruscal OR prim

<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 100 + 5;
struct DSU {
    int par[maxn];
    int n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }
    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    
    void merge(int a, int b) {
        a = find(a), b = find(b);
        par[a] = b;
    }
}dsu;

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int u, int v, int w):u(u), v(v), w(w) {}
    bool operator < (const Edge &b) const {
        return w < b.w;
    }
}edge[maxn*maxn];
int cnt_edge;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int N; scanf("%d", &N);
    cnt_edge = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x; scanf("%d", &x);
            edge[cnt_edge++] = Edge(i, j, x);
        }
    }
    int Q; scanf("%d", &Q);
    dsu.init(N);
    for (int i = 0; i < Q; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        dsu.merge(u, v);
    }
    int cost = 0;
    sort(edge, edge + cnt_edge);
    for (int i = 0; i < cnt_edge; i++) {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if(dsu.find(u) == dsu.find(v)) continue;
        // pr(u); prln(v);
        cost += w;
        dsu.merge(u, v);
    }
    printf("%d\n", cost);
    return 0;
}

```


---
layout: post
title: 暑期集训-7-4-a
date: 2016-09-05 15:40:39
tags:
- ACM
- 2016 暑期集训
categories:
- 2016暑期集训
---

## 题意
LightOJ 1027
> N 扇门，若这扇门权值xi为正，则花费|xi|的时间走出迷宫，否则花费|xi|时间回到原地。
求走出迷宫的期望。
<!--more-->

## 做法
简单期望题

## 代码
```cpp
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
typedef pair<int, int> pii;
typedef long long ll;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", 'w', stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int n;
        scanf("%d", &n);
        int a = 0, suma = 0, b = 0, sumb = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if(x > 0) {
                a++; suma += x;
            } else {
                b++; sumb += -x;
            }
        }
        int p = suma + sumb;
        int q = n - b;
        printf("Case %d: ", Cas);
        if(q == 0) {
            printf("inf\n");
        } else {
            int g = gcd(p, q);
            printf("%d/%d\n", p / g, q / g);
        }
    }
    return 0;
}
```


---
layout: post
title: 暑期集训-7-4-b
date: 2016-09-05 15:40:39
tags:
- ACM
- 2016 暑期集训
- LightOJ
categories:
- 2016暑期集训
---

## 题意
SOJ 3596
KMP 水题
<!--more-->

## 做法
kmp

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = 835672545;
const int maxn = 1000 + 5;
char words[maxn][maxn];
char str[maxn];
int match[maxn][maxn];
int n;
int dp[maxn];
int wordlen[maxn];
int lenstr;

struct KMP {
    int nxt[maxn];
    void get_next(int words_num) {
        char *s = words[words_num];
        int len = wordlen[words_num];
        int i, k;
        nxt[0] = k = -1;
        for (i = 0; i < len;) {
            if(k == -1 || s[i] == s[k]) {
                k++; i++;
                nxt[i] = k;
            } else k = nxt[k];
        }
    }
    
    void solve(int words_num) {
        char *w = words[words_num];
        int lw = wordlen[words_num], lstr = lenstr;
        int j = 0;
        for (int i = 0; i < lstr;) {
            if(j == -1 || w[j] ==str[i]) {
                i++; j++;
                if(j == lw) {
                    match[words_num][i-1] = 1;
                    j = nxt[j];
                    // pr(j);
                    // pr(words_num), prln(i);
                }
            } else {
                j = nxt[j];
            }
        }
    }
}kmp;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", words[i]);
            wordlen[i] = strlen(words[i]);
        }
        scanf("%s", str);
        lenstr = strlen(str);
        memset(match, 0, sizeof(match));
        for (int i = 0; i < n; i++) {
            kmp.get_next(i);
            kmp.solve(i);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int len = strlen(str);
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < n; j++) {
                if(match[j][i-1]) {
                    dp[i] = (dp[i] + dp[i-wordlen[j]]) % mod;
                }
            }
        }
        printf("%d\n", dp[len]);
    }
    return 0;
}
```

---
layout: post
title: 暑期集训-7-4-c
date: 2016-09-05 16:32:39
tags:
- ACM
- 2016 暑期集训
- POJ
- DSU
categories:
- 2016暑期集训
---

## 题意
POJ 2912
n个人玩石头剪刀布，其中有一个人是裁判，剩下的人分成3组，每一组的人出同一手形，裁判可以人溢出。问能否判断谁是裁判。

## 做法
枚举裁判，并查集判断

## 代码
<!--more-->
```cpp
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 500 + 5;
const int maxm = 2000 + 5;
struct DSU {
    int par[maxn], r[maxn], n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            par[i] = i; r[i] = 0;
        }
    }
    
    int find(int x) {
        if(x != par[x]) {
            int fx = par[x];
            par[x] = find(par[x]);
            r[x] = (r[x] + r[fx]) % 3;
        }
        return par[x];
    }
    
    bool merge(int x, int y, int t) {
        int fx = find(x), fy = find(y);
        if(fx == fy) {
            if((r[y] + t) % 3 != r[x]) return false;
            else return true;
        } else {
            par[fx] = fy;
            r[fx] = (r[y] -r[x] + t + 3) % 3;
            return true;
        }
    }
}dsu;

int N, M;
int err[maxn], maxerr, cnt;
int U[maxm], V[maxm], T[maxm];
int main() {
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", 'w', stdout);
#endif
    while(scanf("%d%d", &N, &M) != EOF) {
        for (int i = 0; i < M; i++) {
            char c;
            // scanf("%d%c%d", &U[i], &c, &V[i]);
            scanf("%d", &U[i]);
            while((c = getchar()) == ' ');
            scanf("%d", &V[i]);
            if(c == '=') T[i] = 0;
            if(c == '<') T[i] = 1;
            if(c == '>') T[i] = 2;
        }
        
        maxerr = 0, cnt = 0;
        int res = 0;
        memset(err, -1, sizeof(err));
        for (int judge = 0; judge < N; judge++) {
            dsu.init(N);
            for (int i = 0; i < M; i++) {
                int x = U[i], y = V[i], t = T[i];
                if(x == judge || y == judge) continue;
                if(!dsu.merge(x, y, t)) {
                    err[judge] = i + 1;
                    maxerr = max(maxerr, err[judge]);
                    break;
                }
            }
            if(err[judge] == -1) {
                cnt++;
                res = judge;
            }
        }
        if(cnt == 0) {
            printf("Impossible\n");
        } else if(cnt == 1) {
            printf("Player %d can be determined to be the judge after %d lines\n", res, maxerr);
        } else if(cnt > 1) {
            printf("Can not determine\n");
        }
    }
    return 0;
}
```


---
title: 暑期集训-7-4-d
date: 2016-09-05 16:59:44
tags:
- ACM
- 2016 暑期集训
- HDU
- 并查集
- 二分
categories:
- 2016暑期集训
---

## 题意
给一个n*m的矩阵，其中随着时间增长会出现一些障碍，问矩阵上端和下端开始隔开的时间

## 做法
1. 二分时间，判断是否联通
2. 并查集

## 代码
<!--more-->
并查集代码:
```cpp
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 500 + 5;
int mp[maxn][maxn];
struct DSU {
    int par[maxn*maxn], n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }
    
    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    
    void merge(int a, int b) {
        a = find(a), b = find(b);
        par[b] = a;
    }
}dsu;

int T, N, M, Q;
char str[maxn];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int id(int x, int y) {
    return x * M + y + 1;
}

int s, t;
void work(int x, int y) {
    if(x == 0) {
        dsu.merge(s, id(x, y));
    }
    if(x == N - 1) {
        dsu.merge(t, id(x, y));
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if(mp[nx][ny] == 0) {
                dsu.merge(id(x, y), id(nx, ny));
            }
        }
    }
}

int qx[maxn*maxn], qy[maxn*maxn];

int main() {
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", 'w', stdout);
#endif
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++) {
            scanf("%s", str);
            for (int j = 0; j < M; j++) {
                mp[i][j] = str[j] - '0';
            }
        }
        scanf("%d", &Q);
        for (int i = 1; i <= Q; i++) {
            scanf("%d%d", &qx[i], &qy[i]);
            mp[qx[i]][qy[i]] = 1;
        }
        
        dsu.init(N*M + 1);
        s = 0, t = N * M + 1;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(mp[i][j] == 0) {
                    work(i, j);
                }
            }
        }
        
        if(dsu.find(s) == dsu.find(t)) {
            printf("-1\n");
        } else {
            int i;
            for (i = Q; i >= 1; i--) {
                mp[qx[i]][qy[i]] = 0;
                work(qx[i], qy[i]);
                if(dsu.find(s) == dsu.find(t)) {
                    printf("%d\n", i);
                    break;
                }
            }
            if(i == 0) {
                printf("0\n");
            }
        }
    }
    return 0;
}
```

---
title: 暑期集训-7-4-e
date: 2016-09-06 11:04:14
tags:
- ACM
- 2016 暑期集训
- HDU
- 贪心
categories:
- 2016暑期集训
---

## 题意
给两个字符串，有四种操作，添加，删除，修改，复制。问把第一个字符串转化为第二个的最少步数。

## 做法
贪心
<!--more-->

## 代码
```cpp
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
typedef pair<int, int> pii;
typedef long long ll;
int main() {
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", 'w', stdout);
#endif
    string s1, s2;
    while(cin >> s1 >> s2) {
        int len1 = (int)s1.size(), len2 = (int)s2.size();
        if(len1 > len2) {
            int d = len1 - len2;
            for (int i = 0; i < d; i++) {
                printf("d %c\n", s1[i]);
            }
            for (int i = 0; i < len2; i++) {
                printf("m %c\n", s2[i]);
            }
        } else {
            int d = len2 - len1;
            for (int i = 0; i < d; i++) {
                printf("a %c\n", s2[i]);
            }
            for (int i = d; i < len2; i++) {
                printf("m %c\n", s2[i]);
            }
        }
    }
    return 0;
}
```


---
title: 暑期集训-7-4-f
date: 2016-09-06 12:09:33
tags:
- ACM
- 2016 暑期集训
- HDU
- 贪心
categories:
- 2016暑期集训
---
## 题意
HDU 4864
有n个机器，m个任务。每个机器至多能完成一个任务。每个机器有个最大运行时间xi和等级yi,对于每个任务j,只有当xi>=xj,yi>=yj时，机器i才能完成任务j。如果完成任务可以获得$500*xj+2*yj$的金钱。问最多可以完成几个任务，出现多种情况时，最多能获得多少金钱。

## 做法
贪心。讲任务按照二元组(x,y)，从大到小排序，机器按照y值不同装入不同的桶里，对于每个桶按照x从小到大排序。然后贪心的对任务和机器配对。
证明:对于当前任务j,机器i,如果存在其他任务(xk, yk)能够使用此机器，那么xj>=xk，则当前任务获得金钱更多，如果不存在任务(xk, yk)能够使用此机器，那么当前完成任务数更多。
<!--more-->
## 代码
```
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e5 + 7;
const int maxy = 100 + 5;
int sta[maxy][maxn];
int pos[maxy];
pii task[maxn];
int N, M;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &N, &M) == 2) {
        memset(pos, 0, sizeof(pos));
        for (int i = 0; i < N; i++) {
            int x, y; scanf("%d%d", &x, &y);
            sta[y][pos[y]++] = x;
        }
        
        for (int i = 0; i < M; i++) {
            int x, y; scanf("%d%d", &x, &y);
            task[i] = pii(x, y);
        }
        for (int i = 0; i < maxy; i++) {
            sort(sta[i], sta[i] + pos[i]);
        }
        sort(task, task + M, greater<pii>() );
        
        ll num = 0, money = 0;
        for (int i = 0; i < M; i++) {
            int x = task[i].xx, y = task[i].yy;
            for (int j = y; j <= 100; j++) {
                if(pos[j] > 0 && sta[j][pos[j] - 1] >= x) {
                    num++;
                    money += x * 500 + 2 * y;
                    pos[j]--;
                    break;
                }
            }
        }
        cout << num << " " << money << endl;
    }
    return 0;
}
```


---
title: 暑期集训-7-4-g
date: 2016-09-06 12:39:43
tags:
- ACM
- 2016 暑期集训
- POJ
- 网络流
- 二分
categories:
- 2016暑期集训
---

## 题意
K个产奶机，C头奶牛，每个产奶机最多可供M头奶牛使用。给出产奶机和奶牛之间的距离矩阵。问如何安排使得每头奶牛都有一个产奶机，并且使得奶牛到产奶机的最远距离最短。求最短距离。

## 做法
二分最远距离，对于小于此距离的边建图，跑最大流。做法还是很裸的。
<!--more-->
## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int inf = 0x3f3f3f3f;
const int maxn = 300 + 5;
const int maxv = 300 + 5;
int d[maxn][maxn];

struct Dinic {
    struct edge {
        int to, cap, rev;
        edge() {}
        edge(int to, int cap, int rev):to(to), cap(cap), rev(rev) {}
    };
    
    vector<edge> G[maxv];
    int num_v;
    int level[maxv];
    int iter[maxv];
    
    void add_edge(int from, int to, int cap) {
        G[from].push_back(edge(to, cap, (int)G[to].size()));
        G[to].push_back(edge(from, 0, (int)G[from].size() - 1));
    }
    
    void init(int num_v) {
        this->num_v = num_v;
        for (int i = 0; i <= num_v; i++) G[i].clear();
    }
    
    void bfs(int s) {
        memset(level, -1, sizeof(level));
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()) {
            int v = que.front(); que.pop();
            for (int i = 0; i < (int)G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < (int)G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if( d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    
    int max_flow(int s, int t) {
        int flow = 0;
        for (;;) {
            bfs(s);
            if(level[t] < 0) return flow;
            memset(iter, 0, sizeof(iter));
            int f;
            while((f = dfs(s, t, inf)) > 0) {
                flow += f;
            }
        }
    }
}dinic;

int K, C, M;

bool judge(int x) {
    int s = 0, t = K + C + 1;
    dinic.init(t + 1);
    for (int i = 1; i <= K; i++) {
        dinic.add_edge(i, t, M);
    }
    for (int i = K + 1; i <= K + C; i++) {
        dinic.add_edge(s, i, 1);
    }
    
    for (int i = 1; i <= K; i++) {
        for (int j = K + 1; j <= K + C; j++) {
            if(d[i][j] <= x) {
                dinic.add_edge(j, i, 1);
            }
        }
    }
    
    return dinic.max_flow(s, t) == C;
}


int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d%d", &K, &C, &M) == 3) {
        for (int i = 1; i <= K + C; i++) {
            for (int j = 1; j <= K + C; j++) {
                int x; scanf("%d", &x);
                if(x == 0) x = inf;
                d[i][j] = x;
            }
        }
        
        for (int k = 1; k <= K + C; k++) {
            for (int i = 1; i <= K + C; i++) {
                for (int j = 1; j <= K + C; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        
        int l = 0, r = inf;
        while(l < r - 1) {
            int m = (l + r) >> 1;
            if(judge(m)) {
                r = m;
            } else l = m;
        }
        printf("%d\n", r);
    }
    return 0;
}
```

---
title: 暑期集训-7-4-h
date: 2016-09-06 13:14:13
tags:
- ACM
- 2016 暑期集训
- HDU
- 二分图匹配
categories:
- 2016暑期集训
---
## 题意
有n条鱼，每条鱼有一个权值vi,给个01矩阵，如果G[i][j]=1，那么第i条鱼可以攻击第j条鱼，并获得价值vi xor vj，每条鱼只能攻击一次。求能够最获得的最大价值和

## 做法
很明显的最大权二分图匹配，对于G[i][j]=1,对i， j连边，边权为vi ^ vj，跑次KM算法。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 250;
const int maxm = 25005;
const int inf= 0x3f3f3f3f;
char s[200];
int a[maxn],mat[maxn][maxn];
struct Edge{
    int to,next,cap,flow,cost;
}edge[maxm];
int head[maxn],tot;
int pre[maxn],dis[maxn];
bool vis[maxn];int N;
void init(int n){
    N=n;
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int cap,int cost){
    edge[tot].to=v;
    edge[tot].cap=cap;
    edge[tot].cost=cost;
    edge[tot].flow=0;
    edge[tot].next=head[u];
    head[u]=tot++;
    edge[tot].to=u;
    edge[tot].cap=0;
    edge[tot].cost=-cost;
    edge[tot].flow=0;
    edge[tot].next=head[v];
    head[v]=tot++;
}
bool spfa(int s,int t){
    queue<int> q;
    for(int i=0;i<N;i++){
        dis[i]=inf;
        vis[i]=false;
        pre[i]=-1;
    } dis[s]=0;
    vis[s]=true;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if(edge[i].cap>edge[i].flow&&dis[v]>dis[u]+edge[i].cost){
                dis[v]=dis[u]+edge[i].cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }if(pre[t]==-1) return false;
    else return true;
}
int mincostmaxflow(int s,int t,int &cost){
    int flow=0;
    cost=0;
    while(spfa(s,t)){
        int Min=inf;
        for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
            if(Min>edge[i].cap-edge[i].flow) Min=edge[i].cap-edge[i].flow;
        }for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
            edge[i].flow+=Min;
            edge[i^1].flow-=Min;
            cost+=edge[i].cost*Min;
        }flow+=Min;
    }return flow;
}

char str[maxn];

int A[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    while(scanf("%d", &n) == 1 && n) {
        int s = 0, t = 2 * n + 1;
        init(2*n + 2);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        
        for (int i = 1; i <= n; i++) {
            addedge(s, i, 1, 0);
            addedge(i, t, 1, 0);
            addedge(i + n, t, 1, 0);
        }
        
        for (int i = 1; i <= n; i++) {
            scanf("%s", str + 1);
            for (int j = 1; j <= n; j++) {
                if(str[j] == '1') {
                    addedge(i, j + n, 1, -(A[i]^A[j]));
                }
            }
        }
        int cost;
        mincostmaxflow(s, t, cost);
        printf("%d\n", -cost);
    }
    return 0;
}
```

---
title: 暑期集训-7-4-k
date: 2016-09-06 17:05:24
tags:
- ACM
- 2016 暑期集训
- UVA
- 数学
categories:
- 2016暑期集训
---
## 题意
从[1,n]中选3个数，问能组成多少个三角形。

## 做法
简单组合计数，推出公式就好了
<!--more-->
## 代码
```cpp
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e6 + 5;
ll f[maxn];
ll c(ll x) {
    return ((x - 2) * (x - 1) / 2 - (x - 1) / 2) / 2;
}

void init() {
    f[3] = 0;
    for (int i = 4; i < maxn; i++) {
        f[i] = f[i - 1] + c(i);
    }
}
int main() {
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", 'w', stdout);
#endif
    init();
    int n;
    while(cin >> n && n >= 3) {
        printf("%lld\n", f[n]);
    }
    return 0;
}
```

---
title: 暑期集训-7-4-l
date: 2016-09-09 10:39:46
tags:
- ACM
- 2016 暑期集训
- UVA
- 容斥
categories:
- 2016暑期集训
---
## 题意
n行m列棋盘放k个石子。问第一行,第一列,最后一行,最后一列必须有石子有多少种放法。

## 做法
2^n 容斥一下
<!--more-->

## 代码
```cpp
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
#define yy second
#define lowbit(x) (x&-x)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = 1000007;
const int maxn = 500 + 5;
int C[maxn][maxn];

void init() {
    for (int i = 0; i < maxn; i++) {
        C[i][0] = 1; C[i][i] = 1;
    }
    for (int i = 2; i < maxn; i++) {
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
    }
}

int N, M, K;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d%d", &N, &M, &K);
        int ans = 0;
        for (int mask = 1; mask < 16; mask++) {
            int r = N, c = M, b = 0;
            if(mask & 1) r--, b++;
            if(mask & 2) r--, b++;
            if(mask & 4) c--, b++;
            if(mask & 8) c--, b++;
            if(b % 2 == 1) {
                ans = (ans + C[r * c][K] + mod) % mod;
            } else {
                ans = (ans + mod - C[r * c][K]) % mod;
            }
        }
        // prln(ans);
        ans = ((C[N*M][K] - ans) % mod + mod) % mod;
        printf("Case %d: %d\n", Cas, ans);
    }
    return 0;
}
```


---
title: 暑期集训-7-4-m
date: 2016-09-09 10:49:40
tags:
- ACM
- 2016 暑期集训
- HDU
- DP
- 单调队列
categories:
- 2016暑期集训
---
## 题意
HDU 3401
知道第i天股票的买卖价格(APi, BPi), 和第i天最多能够买卖的数量(ASi, BSi).两个交易日之间必须相隔W天，任何时间不能拥有超过MaxP只股票。
<!--more-->
## 做法
$$dp[i][j]$$ 表示第i天，拥有j只股票，最多能够赚多少钱。可以很容易推出
$dp[i][j] = max(dp[i-1][j], max(dp[r][k] - APi[i]*(j-k))(0<r<i-w,k<j),max(dp[r][k]+BPi[i]*(k-j))(0<r<i-w,k>j))$
但是这个dp复杂度不够，然后我们可以发现通过化简，$dp[i-w-1] - APi[i]*(j-k) = dp[i-w-1][k] + APi[i][k] + APi[i]*k-APi[i]*j$ (k < j),可以发现这个式子可以用单调队列优化。

## 代码
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const ll inf = 0x3fffffff;
const int maxn = 2000 + 5;
int dp[maxn][maxn];

int ap[maxn], bp[maxn], as[maxn], bs[maxn];
int T, MaxP, W;
int que[maxn], head, tail;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int cas; scanf("%d", &cas);
    while(cas--) {
        scanf("%d%d%d", &T, &MaxP, &W);
        for (int i = 1; i <= T; i++) {
            scanf("%d%d%d%d", &ap[i], &bp[i], &as[i], &bs[i]);
        }
        for (int i = 0; i <= T; i++) {
            for (int j = 0; j <= MaxP; j++) {
                dp[i][j] = -inf;
            }
        }
        
        for (int i = 1; i <= W + 1; i++) {
            for (int j = 0; j <= as[i]; j++) {
                dp[i][j] = max(dp[i][j], -ap[i] * j);
            }
        }
        
        for (int i = 2; i <= T; i++) {
            for (int j = 0; j <= MaxP; j++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
            if (i > W + 1) {
                head = tail = 0;
                for (int j = 0; j <= MaxP; j++) {
                    while(tail > head && que[tail-1] < dp[i-W-1][j] + ap[i] * j) tail--;
                    que[tail++] = dp[i-W-1][j] + ap[i] * j;
                    dp[i][j] = max(dp[i][j], que[head] - ap[i] * j);
                    if(j - as[i] >= 0) {
                        if(que[head] == dp[i-W-1][j-as[i]] + ap[i] * (j-as[i])) head++;
                    }
                }
                
                head = tail = 0;
                for (int j = MaxP; j >= 0; j--) {
                    while(tail > head && que[tail-1] < dp[i-W-1][j] + bp[i] * j) tail--;
                    que[tail++] = dp[i-W-1][j] + bp[i] * j;
                    dp[i][j] = max(dp[i][j], que[head] - bp[i] * j);
                    if(j + bs[i] <= MaxP) {
                        if(que[head] == dp[i-W-1][j+bs[i]] + bp[i] * (j+bs[i])) head++;
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= MaxP; j++) {
            ans = max(ans, dp[T][j]);
        }
        cout << ans << endl;
    }
    return 0;
}
```


---
title: 暑期集训-7-4-n
date: 2016-09-09 11:12:56
tags:
- ACM
- 2016 暑期集训
- POJ
- 最短路
categories:
- 2016暑期集训
---
## 题意
POJ 2387
给个无向图，求1到n的最短距离

## 做法
最短路裸题，随便跑个sfpa或者djikstra就好
<!--more-->
## 代码
```cpp
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define xx first
#define yy second
#define pr(x) cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;
int d[maxn];
struct Edge {
    int  to, w;
    Edge() {}
    Edge(int to, int w):to(to), w(w) {};
};

vector<Edge> G[maxn];

int T, N;
int dij() {
    memset(d, 0x3f, sizeof(d));
    priority_queue<pii, vector<pii>, greater<pii> > que;
    d[1] = 0;
    que.push(pii(d[1], 1));
    while(!que.empty()) {
        pii cur = que.top(); que.pop();
        int u = cur.yy, dist = cur.xx;
        if(u == N) {
            return dist;
        }
        for (int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i].to;
            if(d[v] > d[u] + G[u][i].w) {
                d[v] = d[u] + G[u][i].w;
                que.push(pii(d[v], v));
            }
        }
    }
    return -1;
}

int main() {
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", 'w', stdout);
#endif
    scanf("%d%d", &T, &N);
    for (int i = 0; i < T; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        G[u].push_back(Edge(v, c));
        G[v].push_back(Edge(u, c));
    }
    int ans = dij();
    printf("%d\n", ans);
    return 0;
}
```


---
title: 暑期集训-7-4-o
date: 2016-09-09 11:22:07
tags:
- ACM
- 2016 暑期集训
- POJ
- 最短路
categories:
- 2016暑期集训
---
## 题意
POJ 1797
给出每条道路的最大负载，求1到n之间最大负载的路径，输出这条路径的最大负载。

## 做法
最短路变形，把一条路径的长度规定为这条路径上的道路的最小负载，跑个最短路就好
<!--more-->
## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
vector<pii> G[maxn];
int d[maxn];
int n, m;

int bfs() {
    memset(d, -1, sizeof(d));
    queue<int> que;
    d[1] = inf;
    que.push(1);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for (int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i].xx;
            int t = min(d[u], G[u][i].yy);
            if(d[v] < t) {
                d[v] = t;
                que.push(v);
            }
        }
    }
    return d[n];
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 0; i < m; i++) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            G[u].push_back(pii(v, c));
            G[v].push_back(pii(u, c));
        }
        printf("Scenario #%d:\n%d\n\n", Cas, bfs());
    }
    return 0;
}

```


---
title: 暑期集训-7-4-p
date: 2016-09-09 11:34:02
tags:
- ACM
- 2016 暑期集训
- POJ
- 计算几何
categories:
- 2016暑期集训
---
## 题意
POJ 2398
给一个矩形，然后k条线段讲其划分为k+1块，给n个点坐标，问对于每一个正数t，有多少块包含t个点

## 做法
对线段排个序，然后用叉积判断点和线段的关系，二分查找点在哪一块
<!--more-->

## 代码
```cpp
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
typedef pair<int, int> pii;
typedef long long ll;

struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y):x(x), y(y) {}
    bool operator < (const Point &b) const {
        return x < b.x;
    }
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
};
typedef Point vec;

ll cross_product(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

struct Line {
    Point s, t;
    Line() {}
    Line(Point s, Point t):s(s), t(t) {}
    bool operator < (const Line &b) const {
        return s < b.s;
    }
    vec get_vec() {
        return t - s;
    }
};

const int maxn = 1000 + 5;
Line ls[maxn];
int n, m, X1, Y1, X2, Y2, cntls;

bool judge(Line a, Line b) {
    return cross_product(a.get_vec(), b.get_vec()) > 0;
}

int get_id(int x, int y) {
    int l = 0, r = cntls - 1;
    while(l < r - 1) {
        int m = (l + r) >> 1;
        if(!judge(ls[m], Line(ls[m].s, Point(x, y)))) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

int res[maxn];
int cnt[maxn];
int main() {
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", 'w', stdout);
#endif
    while(scanf("%d%d", &n, &m) == 2 && n) {
        scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
        cntls = 0;
        ls[cntls++] = Line(Point(X1, Y2), Point(X1, Y1));
        ls[cntls++] = Line(Point(X2, Y2), Point(X2, Y1));
        for (int i = 0; i < n; i++) {
            int u, l;
            scanf("%d%d", &u, &l);
            ls[cntls++] = Line(Point(l, Y2), Point(u, Y1));
        }
        sort(ls, ls + cntls);
        memset(cnt, 0, sizeof(cnt));
        memset(res, 0, sizeof(res));
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            int id = get_id(x, y);
            cnt[id]++;
        }
        
        for (int i = 0; i < cntls; i++) {
            res[cnt[i]]++;
        }
        
        printf("Box\n");
        for (int i = 1; i <= m; i++) {
            if(res[i] > 0) {
                printf("%d: %d\n", i, res[i]);
            }
        }
    }
    
    return 0;
}
```


---
title: 暑期集训-7-4-q
date: 2016-09-09 11:38:59
tags:
- ACM
- 2016 暑期集训
- POJ
- 计算几何
- 线段交
categories:
- 2016暑期集训
---
## 题意
给个矩形，给n条线段，每条线段均从矩形四边出发，到矩形四边结束。给出宝藏的坐标。问从外面进入宝藏所在的位置至少需要开几道门。门只能开在一条线段的中间。

## 做法
可以发现这样一个性质，从矩形边长上一个点，到达宝藏需要开的门的最少个数，等于宝藏所在点与此点连线与其他线段的交点数。所以枚举起点，暴力求线段交就好。
<!--more-->
## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 300 + 5;
const double eps = 1e-9;

int sgn(double x) {
    if(x > eps) return 1;
    else if(x < -eps) return -1;
    else return 0;
}

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y):x(x), y(y) {}
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    double det(const Point &b) const {
        return x * b.y - y * b.x;
    }
    double dot(const Point &b) const {
        return x * b.x + y * b.y;
    }
    
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
}ps[maxn];

struct Line {
    Point s, t;
    Line(Point s, Point t): s(s), t(t) {}
    Line() {}
    void read() {
        s.read(); t.read();
    }
}ls[maxn];


bool strict_cross(Line a, Line b) {
    return sgn((b.t - b.s).det(a.s - b.s)) * sgn((b.t - b.s).det(a.t - b.s)) < 0 &&
    sgn((a.t - a.s).det(b.s - a.s)) * sgn((a.t - a.s).det(b.t - a.s)) < 0;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    Point X;
    int cntps = 0;
    ps[cntps++] = Point(0, 0);
    // ps[cntps++] = Point(0, 100);
    // ps[cntps++] = Point(100, 0);
    // ps[cntps++] = Point(100, 100);
    for (int i = 0; i < n; i++) {
        ls[i].read();
        ps[cntps++] = ls[i].s;
        ps[cntps++] = ls[i].t;
    }
    X.read();
    int ans = maxn;
    for (int i = 0; i < cntps; i++) {
        Line l(X, ps[i]);
        int t = 1;
        for (int j = 0; j < n; j++) {
            if(strict_cross(l, ls[j])) {
                t++;
            }
        }
        ans = min(ans,  t);
    }
    printf("Number of doors = %d\n", ans);
    return 0;
}

```

---
title: 暑期集训-7-6-a
date: 2016-09-10 09:44:39
tags:
- ACM
- 2016 暑期集训
- HDU
- 图论
- Tarjan
categories:
- 2016暑期集训
---
## 题意
HDU 2586
给一颗树，询问u,v两点的距离

## 做法
转化为有根树，从根root开始跑单源最短路，求个最近公共祖先fa，然后d[u][v] = d[root][u] + d[root][v] - 2 * d[root][fa];
<!--moer-->
## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxm = 200 + 5;
const int maxn = 4e4 + 5;

struct DSU {
    int par[maxn], n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }
    
    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    
    void merge(int a, int b) {
        a = find(a), b = find(b);
        par[a] = b;
    }
}dsu;

struct Edge {
    int to, w;
    Edge() {}
    Edge(int to, int w): to(to), w(w) {}
};

vector<Edge> G[maxn], querry[maxn];
int used[maxn];
int ans[maxm];
int dist[maxn];
int n, m;

void dfs(int u, int d, int fa) {
    dist[u] = d;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i].to;
        if(v == fa) continue;
        dfs(v, d + G[u][i].w, u);
    }
}

void tarjan(int u, int fa) {
    used[u] = true;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i].to;
        if(v == fa) continue;
        tarjan(v, u);
        dsu.merge(v, u);
    }
    
    for (int i = 0; i < (int)querry[u].size(); i++) {
        int v = querry[u][i].to;
        if (used[v]) {
            ans[querry[u][i].w] = dist[u] + dist[v] - 2 * dist[dsu.find(v)];
        }
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++) {
            G[i].clear();
            querry[i].clear();
        }
        for (int i = 1; i <= n - 1; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(Edge(v, w));
            G[v].push_back(Edge(u, w));
        }
        
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            querry[u].push_back(Edge(v, i));
            querry[v].push_back(Edge(u, i));
        }
        memset(dist, -1, sizeof(dist));
        dfs(1, 0, -1);
        memset(used, 0, sizeof(used));
        dsu.init(n);
        tarjan(1, -1);
        for (int i = 0; i < m; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}

```


---
title: 暑期集训-7-6-e
date: 2016-09-10 09:50:17
tags:
- ACM
- 2016 暑期集训
- POj
- 贪心
categories:
- 2016暑期集训
---

## 题意
POJ 1700
N个人过河，船每次只能坐连个人，船载每个人过河的所需的时间不同，问最快的过河时间

## 做法
贪心，n <= 3的时候可以直接算出，n > 3时，考虑最慢的两个人过河最快的两种方案取最小值，即min(A[0] + A[n-1] + A[n-2] + A[0], A[1] + A[0] + A[1] + A[n-1]);

<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e3 + 5;
int A[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        int ans = 0;
        while(n) {
            if(n <= 2) {
                ans += A[n - 1]; n = 0;
            } else if(n == 3) {
                ans += A[0] + A[1] + A[2]; n = 0;
            } else {
                ans += min(A[0] + A[n-1] + A[n-2] + A[0],
                           A[1] + A[0] + A[1] + A[n-1]);
                n -= 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

```


---
title: 暑期集训-7-6-g
date: 2016-09-10 09:57:51
tags:
- ACM
- 2016 暑期集训
- UVA
- 简单题
categories:
- 2016暑期集训
---
## 题意
UVA 10881
许多蚂蚁在一条直线上，每个蚂蚁的移动速度都是1，并且有一个初始方向。两个蚂蚁相撞时会转向，问t世间后各个蚂蚁的位置。

## 做法
经典题，蚂蚁相撞后可以等价于直接穿过，然后排个序对应一下就好。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e4 + 5;
pair<pii, int> A[maxn];
pii buf[maxn];
int pos[maxn], sta[maxn];
int L, T, n;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Case; scanf("%d", &Case);
    for (int Cas = 1; Cas <= Case; Cas++) {
        scanf("%d%d%d", &L, &T, &n);
        for (int i = 0; i < n; i++) {
            int x; char ch;
            cin >> x >> ch;
            A[i].xx.xx = x;
            A[i].yy = i;
            A[i].xx.yy = (ch == 'R' ? 1 : -1);
        }
        sort(A, A + n);
        for (int i = 0; i < n; i++) {
            buf[i].xx = A[i].xx.xx + A[i].xx.yy * T;
            buf[i].yy = A[i].xx.yy;
        }
        sort(buf, buf + n);
        printf("Case #%d:\n", Cas);
        
        for (int i = 0; i < n; i++) {
            pos[A[i].yy] = buf[i].xx;
            // prln(A[i].yy);
            if(buf[i].xx < 0 || buf[i].xx > L) {
                sta[A[i].yy] = 1;
            } else {
                // printf("%d ", buf[i].xx);
                if((i > 0 && buf[i].xx == buf[i-1].xx) ||
                   (i < n - 1 && buf[i].xx == buf[i+1].xx)) {
                    sta[A[i].yy] = 2;
                } else {
                    if(buf[i].yy == 1) {
                        sta[A[i].yy] = 3;
                    } else {
                        sta[A[i].yy] = 4;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if(sta[i] == 1) {
                printf("Fell off\n");
            }
            if(sta[i] == 2) {
                printf("%d Turning\n", pos[i]);
            }
            if(sta[i] == 3) {
                printf("%d R\n", pos[i]);
            }
            if(sta[i] == 4) {
                printf("%d L\n", pos[i]);
            }
        }
        puts("");
    }
    return 0;
}

```

---
title: 暑期集训-7-6-i
date: 2016-09-10 10:02:10
tags:
- ACM
- 2016 暑期集训
- POJ
- 开关问题
categories:
- 2016暑期集训
---
## 题意
POJ 3185
给一列碗，将其翻转为全部碗口向上，最少需要翻转多少次，翻转一个碗时其两边的碗也会被翻转。

## 做法
这里有两种做法
1. 因为碗只有20个，所以我们可以直接枚举翻转方案，然后check最后碗是否是全部向上。这里枚举方案有2^20,check可以O(1)完成。
2. 可以枚举第一个碗是否翻转，然后后面可以直接递推出现，复杂度2*20

<!--more-->

## 代码
这里给出做法1的代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int s = 0;
    for (int i = 0; i < 20; i++) {
        int x; scanf("%d", &x);
        s |= x<<i;
    }
    int ans = 100;
    for (int i = 0; i < (1<<20); i++) {
        int t = i ^ (i << 1) ^ (i >> 1);
        t %= (1<<20);
        if((s ^ t) == 0) {
            ans = min(ans, __builtin_popcount(i));
        }
    }
    cout << ans << endl;
    return 0;
}

```


---
title: 暑期集训-7-6-j
date: 2016-09-10 10:09:59
tags:
- ACM
- 2016 暑期集训
- POJ
categories:
- 2016暑期集训
---
## 题意
给一个M*N的01矩阵，每次可以反转一个位置，但其上下左右的位置也会跟着反转，问最后能否把这个矩阵反转为全为0，并输出方案

## 做法
枚举第一行的反转方案，递推 O(2^m * n)
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int inf = 0x3f3f3f3f;
const int maxn = 15;
int M, N;
int src[maxn];
int dp[maxn];
int buf[maxn];
int ans[maxn];
void work(int &x, int mask) {
    for (int i = 0; i < N; i++) {
        if((mask >> i) & 1) {
            x ^= 1<<i;
            x ^= (1<<i) >> 1;
            if(i < N - 1) x ^= ((1<<i)<<1);
        }
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &M, &N);
    memset(dp, 0, sizeof(0));
    memset(src, 0, sizeof(src));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int x; scanf("%d", &x);
            src[i] |= x << (N - j - 1);
        }
    }
    int cnt = inf;
    for (int mask = 0; mask < (1 << N); mask++) {
        memcpy(dp, src, sizeof(src));
        int t = mask;
        for (int i = 0; i < M; i++) {
            work(dp[i], t);
            buf[i] = t;
            if(i + 1 < M) {
                dp[i+1] ^= t;
            }
            t = dp[i];
        }
        if(dp[M-1] == 0) {
            int t = 0;
            for (int i = 0; i < M; i++) {
                t += __builtin_popcount(buf[i]);
            }
            if(t < cnt) {
                cnt = t;
                memcpy(ans, buf, sizeof(buf));
            }
        }
    }
    if(cnt == inf) {
        printf("IMPOSSIBLE\n");
    } else {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d%c", ((ans[i]>>(N-1-j)) & 1),
                       j == N - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}

```


---
title: 暑期集训-7-6-k
date: 2016-09-10 10:16:49
tags:
- ACM
- 2016 暑期集训
- POJ
- two pointers
categories:
- 2016暑期集训
---
## 题意
POJ 3320
找一段最小的连续的区间，包含所有出现过的数字

## 做法
two pointers
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 6;
int A[maxn];
int V[maxn];
int n;
int cnt[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            V[i-1] = A[i];
        }
        sort(V, V + n);
        int m = unique(V, V + n) - V;
        for (int i = 1; i <= n; i++) {
            A[i] = lower_bound(V, V + m, A[i]) - V;
        }
        int ans = inf;
        memset(cnt, 0, sizeof(cnt));
        for (int l = 1, r = 1, c = 0; r <= n; r++) {
            if(cnt[A[r]]++ == 0) c++;
            while(c == m) {
                ans = min(ans, r - l + 1);
                cnt[A[l]]--;
                if(cnt[A[l]] == 0) c--;
                l++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

```


---
title: 暑期集训-7-6-l
date: 2016-09-10 10:20:43
tags:
- ACM
- 2016 暑期集训
- POJ
- two pointers
categories:
- 2016暑期集训
---
## 题意
POJ 2566
给一个序列，让找到一个连续的子序列，使其和的绝对值最接近target.

## 做法
非常经典的一个题。求出所有的前缀和，对前缀和排序，然后two pointers
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int A[maxn];
pii sum[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, k;
    while(scanf("%d%d", &n, &k) == 2) {
        if(n == 0 && k == 0) return 0;
        memset(A, 0, sizeof(A));
        memset(sum, 0, sizeof(sum));
        sum[0] = pii(0, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            sum[i].xx = sum[i-1].xx + A[i];
            sum[i].yy = i;
        }
        sort(sum, sum + n + 1);
        for (int i = 0; i < k; i++) {
            int t; scanf("%d", &t);
            int tmp = inf, ans = inf, ansl = -1, ansr = -1;
            for (int l = 0, r = 1; r <= n; r++) {
                if(l < r && abs(sum[r].xx - sum[l].xx - t) < tmp) {
                    tmp = abs(sum[r].xx - sum[l].xx - t);
                    ans = sum[r].xx - sum[l].xx;
                    ansl = sum[l].yy, ansr = sum[r].yy;
                }
                while(l < r && sum[r].xx - sum[l].xx >= t) {
                    l++;
                    if(l < r && abs(sum[r].xx - sum[l].xx - t) < tmp) {
                        tmp = abs(sum[r].xx - sum[l].xx - t);
                        ans = sum[r].xx - sum[l].xx;
                        ansl = sum[l].yy; ansr = sum[r].yy;
                    }
                }
            }
            if(ansl > ansr) swap(ansl, ansr);
            printf("%d %d %d\n", ans, ansl + 1, ansr);
        }
    }
    return 0;
}

```


---
title: 暑期集训-7-6-m
date: 2016-09-10 10:31:18
tags:
- ACM
- 2016暑期集训
- Codeforces
- dp
categories:
- 2016暑期集训
---
## 题意
Codeforces 687C
给n个数，问在n个数里面选一些数字，和为k的条件下，这些集合的子集元素和可以为多少

## 做法
简单dp，dp[i][sum][k]表示前i个数，和为sum，k是否能为子集和
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 500 + 5;
int subset[maxn][maxn];
int sum[maxn];
int C[maxn];
int n, K;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &C[i]);
    }
    sum[0] = 1, subset[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int c = C[i];
        for (int j = K; j >= c; j--) {
            if(sum[j-c]) {
                sum[j] = 1;
                for (int k = 0; k <= j - c; k++) {
                    if(subset[j-c][k]) {
                        subset[j][k] = 1;
                        subset[j][k+c] = 1;
                    }
                }
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i <= K; i++) {
        if(subset[K][i]) {
            ans.push_back(i);
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto x: ans) {
        printf("%d ", x);
    }
    return 0;
}

```

---
title: 暑期集训-7-6-n
date: 2016-09-10 10:37:40
tags:
- ACM
- 2016 暑期集训
- Codeforces
- DSU
categories:
- 2016暑期集训
---
## 题意
Codeforces	687D
给一个图n个点，m条边，q个询问
每次询问l，r，用l，r以内的边，构成一个图几何。把这个图中的点，分成两个部分，这个图的hardness定义为同一部分里面最长边的长度，求这个hardness的最小值。

## 做法
对所有边从大大小排序，对于每个询问，暴力跑一下所有边，用并查集判断一下就好。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1000 + 5;

struct DSU {
    int par[4*maxn], n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }
    
    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    
    bool merge(int a, int b) {
        if(find(a << 1) == find(b << 1)) {
            return false;
        }
        par[find(a << 1)] = find(b << 1 | 1);
        par[find(b << 1)] = find(a << 1 | 1);
        return true;
    }
}dsu;

struct Edge {
    int u, v, w, num;
    Edge() {}
    Edge(int u, int v, int w):u(u), v(v), w(w) {}
}es[maxn*maxn];

bool cmp(const Edge &a, const Edge &b) {
    return a.w > b.w;
}

int n, m, q;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].w);
        es[i].u--; es[i].v--;
        es[i].num = i + 1;
    }
    sort(es, es + m, cmp);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        int res = -1;
        dsu.init(2*n);
        for (int j = 0; j < m && res == -1; j++) {
            if(es[j].num >=l && es[j].num <= r) {
                if(!dsu.merge(es[j].u, es[j].v)) {
                    res = es[j].w;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
```

---
title: 暑期集训-7-6-o
date: 2016-09-10 10:51:02
tags:
- ACM
- 2016 暑期集训
- POJ
- 概率
- dp
categories:
- 2016暑期集训
---
## 题意
一个软件系统有s个子系统，会产生n种bug，某人一天发现一个bug，这个bug属于一个子系统和一个分类。每个bug属于某个子系统的概率是1/s,属于一个分类，问发现n中bug，并且每个子系统都发现bug的天数的期望。

## 做法
设dp[i][j]表示已经找到i种bug，j个系统的bug，需要达到目标状态的天数期望
dp[n][s] = 0;
然后分成四种情况转移就好，转移到自己很特殊，所以只有3种情况，注意概率的转化
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1000 + 5;
double dp[maxn][maxn];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, s;
    scanf("%d%d", &n, &s);
    dp[n][s] = 0;
    for (int i = n; i >= 0; i--) {
        for (int j = s; j >= 0; j--) {
            if(i == n && j == s) continue;
            double p1 = double(i) / n, p2 = double(j) / s;
            double t = 1 - p1 * p2;
            dp[i][j] += (dp[i+1][j] + 1/ t) * (1 - p1) * p2 / t;
            dp[i][j] += (dp[i+1][j+1] + 1/ t) * (1 - p1)*(1-p2)/t;
            dp[i][j] += (dp[i][j+1] + 1/ t) * p1 * (1 - p2) / t;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            printf("%.4f ", dp[i][j]);
        }
        puts("");
    }
    
    printf("%.4f\n", dp[0][0]);
    return 0;
}
```

---
title: 暑期集训-7-6-q
date: 2016-09-10 10:59:17
tags:
- ACM
- 2016 暑期集训
- POJ
- dp
categories:
- 2016暑期集训
---
## 题意
POJ 2955
求最长匹配的括号子序列

## 做法
区间dp一下就好
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 100 + 5;
int dp[maxn][maxn];
int ans[maxn];
char str[maxn];

int dfs(int i, int j) {
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    else {
        if((str[i] == '(' && str[j] == ')') ||
           (str[i] == '[' && str[j] == ']')) {
            dp[i][j] = max(dp[i][j], dfs(i+1, j-1) + 2);
        }
        for (int k = i; k <= j; k++) {
            dp[i][j] = max(dp[i][j], (dfs(i, k) + dfs(k+1, j)));
        }
        return dp[i][j];
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%s", str) == 1) {
        if(strcmp(str, "end") == 0) {
            return 0;
        }
        int len = strlen(str);
        memset(dp, -1, sizeof(dp));
        dfs(0, len - 1);
        printf("%d\n", dfs(0, len-1));
    }
    return 0;
}

```



---
title: 暑期集训-7-6-r
date: 2016-09-10 11:04:23
tags:
- ACM
- 2016 暑期集训
- Codeforces
- dp
categories:
- 2016暑期集训
---
## 题意
石头剪子布，分别有r,s,p个，相互碰到输的一方会死去，两两之间等概率相遇，最后每种是唯一活下去的概率

## 做法
考虑dp[i][j][k]表示石头剪子布分别剩i,j,k个的概率。因为同种相遇不改变状态。所以tot = i * j + j * k + i * k
然后考虑三种相遇情况转移就好.

<!--more-->
## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 100 + 5;
double dp[maxn][maxn][maxn];

bool judge(int a, int b, int c) {
    int t = (a > 0) + (b > 0) + (c > 0);
    return t >= 2;
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int r, s, p;
    scanf("%d%d%d", &r, &s, &p);
    dp[r][s][p] = 1;
    double ansr = 0, anss = 0, ansp = 0;
    
    for (int i = r; i >= 0; i--) {
        for (int j = s; j >= 0; j--) {
            for (int k = p; k >= 0; k--) {
                if(judge(i + 1, j, k)) dp[i][j][k] += dp[i+1][j][k] * double((i+1)*k)/double((i+1)*j + (i+1)*k + j*k);
                if(judge(i, j + 1, k)) dp[i][j][k] += dp[i][j+1][k] * double((j+1)*i)/double(i*(j+1) + i*k + (j+1)*k);
                if(judge(i, j, k + 1)) dp[i][j][k] += dp[i][j][k+1] * double((k+1)*j)/double(i*j + i*(k+1) + j*(k+1));
            }
        }
    }
    
    for (int i = 1; i < maxn; i++) {
        ansr += dp[i][0][0];
        anss += dp[0][i][0];
        ansp += dp[0][0][i];
    }
    
    printf("%.9f %.9f %.9f\n", ansr, anss, ansp);
    return 0;
}
```


---
title: 暑期集训-7-6-s
date: 2016-09-10 11:10:35
tags:
- ACM
- 2016 暑期集训
- Codeforces
- 简单题
categories:
- 2016暑期集训
---
## 题意
给个长度为n的学列A，m个询问。每个询问给出li，ri, xi. 对于每个询问，找到pi(li <= pi <= ri),A[pi] != xi

## 做法
对于每个位置，预处理下和当前位置上的数不同的最近的右边/左边的位置就好
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 2e5 + 5;
int A[maxn], dp[maxn];
int n, m;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if(A[i] == A[i-1]) dp[i] = dp[i-1];
        else dp[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        if(A[r] == x) {
            if(dp[r] <= l) {
                printf("%d\n", -1);
            } else printf("%d\n", dp[r] - 1);
        } else {
            printf("%d\n", r);
        }
    }
    return 0;
}
```


---
title: 暑期集训-7-6-t
date: 2016-09-10 11:14:46
tags:
- ACM
- 2016 暑期集训
- HDU
- dp
categories:
- 2016暑期集训
---
## 题意
给定一些长方体，求其能叠放的最大高度。一个长方体能叠在另一个上面的条件是，其底面的长和宽都严格大于另一个

## 做法
把一个长方体拆成3个，然后排个序，dp一下
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 200;
struct Block {
    int x, y, z;
    Block(int x, int y, int z):x(x), y(y), z(z) {}
    Block() {}
    bool operator < (const Block &b) const {
        return x < b.x || (x == b.x && y < b.y) ||
        (x == b.x && y == b.y && z < b.z);
    }
    bool greater(const Block &b) const {
        return x > b.x && y > b.y;
    }
}blocks[maxn];

int dp[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    int Cas = 0;
    while(scanf("%d", &n) == 1 && n) {
        int cnt = 0;
        blocks[cnt++] = Block(0, 0, 0);
        for (int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            blocks[cnt++] = Block(x, y, z);
            blocks[cnt++] = Block(x, z, y);
            blocks[cnt++] = Block(y, x, z);
            blocks[cnt++] = Block(y, z, x);
            blocks[cnt++] = Block(z, x, y);
            blocks[cnt++] = Block(z, y, x);
        }
        sort(blocks, blocks + cnt);
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < i; j++) {
                if(blocks[i].greater(blocks[j])) {
                    dp[i] = max(dp[i], dp[j] + blocks[i].z);
                    ans = max(ans, dp[i]);
                }
            }
        }
        printf("Case %d: maximum height = %d\n", ++Cas, ans);
    }
    return 0;
}

```


---
title: 暑期集训-7-8-a
date: 2016-09-10 22:47:28
tags:
- ACM
- 2016 暑期集训
- SOJ
- KMP
categories:
- 2016暑期集训
---
## 题意
给一个只包含小写字母的字符串，给n个单词，问这个字符串能有多少种解读方法
## 做法
KMP 预处理一下当前match[i][j],i位置为单词结束，能否和单词j匹配，然后dp一下即可。
<!--more-->
## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = 835672545;
const int maxn = 1000 + 5;
char words[maxn][maxn];
char str[maxn];
int match[maxn][maxn];
int n;
int dp[maxn];
int wordlen[maxn];
int lenstr;

struct KMP {
    int nxt[maxn];
    void get_next(int words_num) {
        char *s = words[words_num];
        int len = wordlen[words_num];
        int i, k;
        nxt[0] = k = -1;
        for (i = 0; i < len;) {
            if(k == -1 || s[i] == s[k]) {
                k++; i++;
                nxt[i] = k;
            } else k = nxt[k];
        }
    }
    
    void solve(int words_num) {
        char *w = words[words_num];
        int lw = wordlen[words_num], lstr = lenstr;
        int j = 0;
        for (int i = 0; i < lstr;) {
            if(j == -1 || w[j] ==str[i]) {
                i++; j++;
                if(j == lw) {
                    match[words_num][i-1] = 1;
                    j = nxt[j];
                    // pr(j);
                    // pr(words_num), prln(i);
                }
            } else {
                j = nxt[j];
            }
        }
    }
}kmp;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", words[i]);
            wordlen[i] = strlen(words[i]);
        }
        scanf("%s", str);
        lenstr = strlen(str);
        memset(match, 0, sizeof(match));
        for (int i = 0; i < n; i++) {
            kmp.get_next(i);
            kmp.solve(i);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int len = strlen(str);
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < n; j++) {
                if(match[j][i-1]) {
                    dp[i] = (dp[i] + dp[i-wordlen[j]]) % mod;
                }
            }
        }
        printf("%d\n", dp[len]);
    }
    return 0;
}

```


---
title: 暑期集训-7-8-b
date: 2016-09-10 23:21:39/Users/mathon/workspace/doldre.github.io/source/_posts/暑期集训-7-13-j.md

tags:
- ACM
- 2016 暑期集训
- HDU
- 二分图最大权匹配
categories:
- 2016暑期集训
---
## 题意
给个二分图，求最大权匹配
## 做法
KM算法，或者最小费用流可行流
<!--more-->
## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 250;
const int maxm = 25005;
const int inf= 0x3f3f3f3f;
char s[200];
int a[maxn],mat[maxn][maxn];
struct Edge{
    int to,next,cap,flow,cost;
}edge[maxm];
int head[maxn],tot;
int pre[maxn],dis[maxn];
bool vis[maxn];int N;
void init(int n){
    N=n;
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int cap,int cost){
    edge[tot].to=v;
    edge[tot].cap=cap;
    edge[tot].cost=cost;
    edge[tot].flow=0;
    edge[tot].next=head[u];
    head[u]=tot++;
    edge[tot].to=u;
    edge[tot].cap=0;
    edge[tot].cost=-cost;
    edge[tot].flow=0;
    edge[tot].next=head[v];
    head[v]=tot++;
}
bool spfa(int s,int t){
    queue<int> q;
    for(int i=0;i<N;i++){
        dis[i]=inf;
        vis[i]=false;
        pre[i]=-1;
    } dis[s]=0;
    vis[s]=true;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if(edge[i].cap>edge[i].flow&&dis[v]>dis[u]+edge[i].cost){
                dis[v]=dis[u]+edge[i].cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }if(pre[t]==-1) return false;
    else return true;
}
int mincostmaxflow(int s,int t,int &cost){
    int flow=0;
    cost=0;
    while(spfa(s,t)){
        int Min=inf;
        for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
            if(Min>edge[i].cap-edge[i].flow) Min=edge[i].cap-edge[i].flow;
        }for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
            edge[i].flow+=Min;
            edge[i^1].flow-=Min;
            cost+=edge[i].cost*Min;
        }flow+=Min;
    }return flow;
}

char str[maxn];

int A[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    while(scanf("%d", &n) == 1 && n) {
        int s = 0, t = 2 * n + 1;
        init(2*n + 2);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        
        for (int i = 1; i <= n; i++) {
            addedge(s, i, 1, 0);
            addedge(i, t, 1, 0);
            addedge(i + n, t, 1, 0);
        }
        
        for (int i = 1; i <= n; i++) {
            scanf("%s", str + 1);
            for (int j = 1; j <= n; j++) {
                if(str[j] == '1') {
                    addedge(i, j + n, 1, -(A[i]^A[j]));
                }
            }
        }
        int cost;
        mincostmaxflow(s, t, cost);
        printf("%d\n", -cost);
    }
    return 0;
}

```

---
title: 暑期集训-7-8-k
date: 2016-09-11 14:36:58
tags:
- ACM
- 2016 暑期集训
- HDU
- 线段树
categories:
- 2016暑期集训
---
## 题意
给定一个长度为1e5的序列，给1e5个操作，两种操作，一种是将一段区间内的数开方，一种操作区间和

## 做法
用线段树维护一下，并且当区间所有数位1的时候开方操作就可以不用递归下去，每个数最后可以开方logn次，所以最坏复杂度为nlogn。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn = 1e5 + 5;
struct SegTree {
    ll sum[maxn<<2];
    bool eqone[maxn<<2];
    
    void push_up(int rt) {
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
        eqone[rt] = eqone[rt<<1] && eqone[rt<<1|1];
    }
    
    void init() {
        memset(sum, 0, sizeof(sum));
        memset(eqone, false, sizeof(eqone));
    }
    
    void build(int l, int r, int rt) {
        // pr(l); pr(r); prln(rt);
        if(l == r) {
            scanf("%lld", &sum[rt]);
            // pr("leaf");  pr(rt);
            // prln(sum[rt]);
            if(sum[rt] == 1) eqone[rt] = true;
            return;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        push_up(rt);
        // pr(rt); prln(sum[rt]);
    }
    
    void update(int L, int R, int l, int r, int rt) {
        if(eqone[rt]) return;
        if(l == r) {
            sum[rt] = sqrt(sum[rt]);
            if(sum[rt] == 1) eqone[rt] = true;
            return;
        }
        int m = (l + r) >> 1;
        if(L <= m) update(L, R, lson);
        if(m + 1 <= R) update(L, R, rson);
        push_up(rt);
    }
    
    ll querry(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) {
            return sum[rt];
        }
        int m = (l + r) >> 1;
        ll res = 0;
        if(L <= m) res += querry(L, R, lson);
        if(m + 1 <= R) res += querry(L, R, rson);
        return res;
    }
}seg;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Case = 0;
    int n, m;
    while(scanf("%d", &n) == 1) {
        seg.init();
        seg.build(1, n, 1);
        scanf("%d", &m);
        printf("Case #%d:\n", ++Case);
        for (int i = 0; i < m; i++) {
            int t, x, y;
            scanf("%d%d%d", &t, &x, &y);
            if(x > y) swap(x, y);
            if(t == 0) {
                seg.update(x, y, 1, n, 1);
            } else {
                ll res = seg.querry(x, y, 1, n, 1);
                printf("%lld\n", res);
            }
        }
        puts("");
    }
    return 0;
}

```

---
title: 暑期集训-7-8-n
date: 2016-09-11 14:40:57
tags:
- ACM
- 2016 暑期集训
- HDU 1255
- 矩形面积并
categories:
- 2016暑期集训
---

## 题意
HDU 1255
给定平面上若干矩形,求出被这些矩形覆盖过至少两次的区域的面积.

## 做法
做法1:扫描线+线段树
做法2:离散化+二维前缀和
<!--more-->
## 代码
因为这里矩形数量<=1000,所以用二维前缀和的写法会简单很多
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1000 + 5;
double X1[maxn], Y1[maxn], X2[maxn], Y2[maxn];
int cnt_vx, cnt_vy;
double Vx[2*maxn];
double Vy[2*maxn];
int get_xid(double x) {
    return lower_bound(Vx, Vx + cnt_vx, x) - Vx;
}

int get_yid(double y) {
    return lower_bound(Vy, Vy + cnt_vy, y) - Vy;
}

int N;
short mt[2*maxn][2*maxn];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        cnt_vx = cnt_vy = 0;
        for (int i = 0; i < N; i++) {
            scanf("%lf%lf%lf%lf", &X1[i], &Y1[i], &X2[i], &Y2[i]);
            Vx[cnt_vx++] = X1[i];
            Vy[cnt_vy++] = Y1[i];
            Vx[cnt_vx++] = X2[i];
            Vy[cnt_vy++] = Y2[i];
        }
        sort(Vx, Vx + cnt_vx);
        sort(Vy, Vy + cnt_vy);
        memset(mt, 0, sizeof(mt));
        for (int i = 0; i < N; i++) {
            double x1 = X1[i], y1 = Y1[i], x2 = X2[i], y2 = Y2[i];
            int idx1 = get_xid(x1);
            int idy1 = get_yid(y1);
            int idx2 = get_xid(x2);
            int idy2 = get_yid(y2);
            mt[idx1+1][idy1+1]++;
            mt[idx2+1][idy1+1]--;
            mt[idx1+1][idy2+1]--;
            mt[idx2+1][idy2+1]++;
        }
        double ans = 0;
        for (int i = 0; i < cnt_vx; i++) {
            int t = 0;
            for (int j = 0; j < cnt_vy; j++) {
                t += mt[i][j];
                mt[i][j] = t;
                if(i > 0) mt[i][j] += mt[i-1][j];
                if(mt[i][j] > 1) {
                    ans += (Vx[i] - Vx[i-1]) * (Vy[j] - Vy[j-1]);
                }
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}

```


---
title: 暑期集训-7-8-o
date: 2016-09-11 14:44:55
tags:
- ACM
- 2016 暑期集训
- HDU
- DLX
categories:
- 2016暑期集训
---

## 题意
N个城市选出K个城市，建飞机场,1<=N<=60,1<=K<=N,使得所有城市中到最近机场的最大距离最小。

## 做法
二分城市到机场的最大距离，然后建立01矩阵，用DLX可重复覆盖判断是否合法
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int MaxM = 60 + 5, MaxN = 60 + 5;
const int maxnode = MaxM * MaxN;

struct DLX {
    // n 个雷达，m个城市，能否用 K 个雷达 覆盖所有的m个城市。
    // 可重复覆盖
    int n, m, size;
    int K;
    int U[maxnode], D[maxnode], R[maxnode], L[maxnode];
    int Row[maxnode], Col[maxnode];
    int H[MaxN], S[MaxN];
    int ind[MaxN];
    
    int ands, ans[MaxN];
    void init(int _n, int _m) {
        n = _n;
        m = _m;
        for (int i = 0; i <= m; i++) {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[m] = 0; L[0] = m;
        size = m;
        for (int i = 1; i <= n; i++) {
            H[i] = -1;
        }
    }
    
    void Link(int r, int c) {
        ++S[Col[++size] = c];
        Row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0) {
            H[r] = L[size] = R[size] = size;
        } else {
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }
    
    void remove(int c) {
        for (int i = D[c]; i != c; i = D[i]) {
            L[R[i]] = L[i], R[L[i]] = R[i];
        }
    }
    
    void resume(int c) {
        for (int i = U[c]; i != c; i = U[i]) {
            L[R[i]] = R[L[i]] = i;
        }
    }
    
    bool v[maxnode];
    
    int f() {
        int ret = 0;
        for (int c = R[0]; c != 0; c = R[c]) v[c] = true;
        for (int c = R[0]; c != 0; c = R[c]) {
            if(v[c]) {
                ret++;
                v[c] = false;
                for (int i = D[c]; i != c; i = D[i]) {
                    for (int j = R[i]; j != i; j = R[j]) {
                        v[Col[j]] = false;
                    }
                }
            }
        }
        return ret;
    }
    
    bool Dance(int d) {
        if (d + f() > K) return false;
        if (R[0] == 0) return d <= K;
        int c = R[0];
        for (int i = R[0]; i != 0; i = R[i]) {
            if(S[i] < S[c]) {
                c = i;
            }
        }
        for (int i = D[c]; i != c; i = D[i]) {
            remove(i);
            for (int j = R[i]; j != i; j = R[j]) remove(j);
            if(Dance(d + 1)) return true;
            for (int j = L[i]; j != i; j = L[j]) resume(j);
            resume(i);
        }
        return false;
    }
}dlx;


const int maxn = 60 + 5;
int X[maxn], Y[maxn];
ll dis[maxn*maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    int N, K;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; Case++) {
        scanf("%d%d", &N, &K);
        dlx.K = K;
        for (int i = 1; i <= N; i++) {
            scanf("%d%d", &X[i], &Y[i]);
        }
        int cnt_d = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dis[cnt_d++] = (ll)abs(X[i] - X[j]) + (ll)abs(Y[i] - Y[j]);
            }
        }
        sort(dis, dis + cnt_d);
        cnt_d = unique(dis, dis + cnt_d) - dis;
        int l = -1, r = cnt_d;
        while(l < r - 1) {
            int m = (l + r) >> 1;
            ll mid = dis[m];
            dlx.init(N, N);
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if((ll)abs(X[i] - X[j]) + (ll)abs(Y[i] - Y[j]) <= mid) {
                        dlx.Link(i, j);
                    }
                }
            }
            if(dlx.Dance(0)) r = m;
            else l = m;
        }
        printf("Case #%d: %lld\n", Case, dis[r]);
    }
    return 0;
}
```

---
title: 暑期集训-7-8-p
date: 2016-09-11 14:50:26
tags:
- ACM
- 2016 暑期集训
- HDU
- DLX
categories:
- 2016暑期集训
---
## 题意
HDU 2295
N个城市，M个雷达，每个雷达有自己的覆盖范围，选出K个雷达覆盖所有的城市。

## 做法
DLX 重复覆盖模板题
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxnode = 3000;
const int MaxM = 55, MaxN = 55;
int K;
struct DLX {
    int n, m, size;
    int U[maxnode], D[maxnode], R[maxnode], L[maxnode];
    int Row[maxnode], Col[maxnode];
    int H[MaxN], S[MaxN];
    int ands, ans[MaxN];
    void init(int _n, int _m) {
        n = _n;
        m = _m;
        for (int i = 0; i <= m; i++) {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[m] = 0; L[0] = m;
        size = m;
        for (int i = 1; i <= n; i++) {
            H[i] = -1;
        }
    }
    
    void Link(int r, int c) {
        ++S[Col[++size] = c];
        Row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0) {
            H[r] = L[size] = R[size] = size;
        } else {
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }
    
    void remove(int c) {
        for (int i = D[c]; i != c; i = D[i]) {
            L[R[i]] = L[i], R[L[i]] = R[i];
        }
    }
    
    void resume(int c) {
        for (int i = U[c]; i != c; i = U[i]) {
            L[R[i]] = R[L[i]] = i;
        }
    }
    
    bool v[maxnode];
    
    int f() {
        int ret = 0;
        for (int c = R[0]; c != 0; c = R[c]) v[c] = true;
        for (int c = R[0]; c != 0; c = R[c]) {
            if(v[c]) {
                ret++;
                v[c] = false;
                for (int i = D[c]; i != c; i = D[i]) {
                    for (int j = R[i]; j != i; j = R[j]) {
                        v[Col[j]] = false;
                    }
                }
            }
        }
        return ret;
    }
    
    bool Dance(int d) {
        if (d + f() > K) return false;
        if (R[0] == 0) return d <= K;
        int c = R[0];
        for (int i = R[0]; i != 0; i = R[i]) {
            if(S[i] < S[c]) {
                c = i;
            }
        }
        for (int i = D[c]; i != c; i = D[i]) {
            remove(i);
            for (int j = R[i]; j != i; j = R[j]) remove(j);
            if(Dance(d + 1)) return true;
            for (int j = L[i]; j != i; j = L[j]) resume(j);
            resume(i);
        }
        return false;
    }
}dlx;

const double eps = 1e-8;
struct Point {
    int x, y;
    void input() {
        scanf("%d%d", &x, &y);
    }
}city[MaxM], station[MaxN];

double dis(Point a, Point b) {
    return sqrt(((double)(a.x - b.x)*(a.x - b.x) + (double)(a.y - b.y)*(a.y-b.y)));
}


int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    int n, m;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &K);
        for (int i = 0; i < n; i++) city[i].input();
        for (int i = 0; i < m; i++) station[i].input();
        double l = 0, r = 1e8;
        while(r - l >= eps) {
            double mid = (l + r) / 2;
            dlx.init(m, n);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if(dis(station[i], city[j]) < mid - eps) {
                        dlx.Link(i + 1, j + 1);
                    }
                }
            }
            // prln(mid);
            if(dlx.Dance(0)) r = mid - eps;
            else l = mid + eps;
        }
        printf("%.6f\n", l);
    }
    return 0;
}
```


---
title: 2016-Multi-University-Traning-Contest1-1001
date: 2016-09-11 20:59:17
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 最小生成树
categories:
- 2016暑期集训
---
## 题意
给定n个点m条边的带权无向图，每条边边权互不相同。求最小生成树上随机取两点构成的路径长度的期望。

## 做法
因为边权互不相同，所以最小生成树是唯一确定的。随机取两点路径长度的期望，就是求树上任意两点的距离之和。可以发现对于一条边，统计一下其左右两边的点数乘积就是贡献次数。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

struct DSU {
    int par[maxn];
    int n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }
    
    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    
    void merge(int a, int b) {
        a = find(a), b = find(b);
        par[a] = b;
    }
}dsu;

struct Edge {
    int from, to, w;
    Edge() {}
    Edge(int from, int to, int w):from(from), to(to), w(w) {}
}es[maxm];

bool cmp(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

vector<Edge> G[maxn];

int n, m;
int child[maxn];
double tmp;

void dfs(int u, int fa) {
    child[u] = 1;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i].to;
        if(v == fa) continue;
        dfs(v, u);
        child[u] += child[v];
        tmp += ((double)child[v] * (n - child[v])) * G[u][i].w * 2;
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            es[i] = Edge(u, v, w);
        }
        
        sort(es, es + m, cmp);
        dsu.init(n);
        ll tot_w = 0;
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 0; i < m; i++) {
            Edge &e = es[i];
            int u = e.from, v = e.to, w = e.w;
            if(dsu.find(u) == dsu.find(v)) continue;
            tot_w += w;
            dsu.merge(u, v);
            G[u].push_back(Edge(u, v, w));
            G[v].push_back(Edge(v, u, w));
        }
        for (int i = 0; i <= n; i++) child[i] = 0;
        tmp = 0;
        dfs(1, -1);
        printf("%lld %.2f\n", tot_w, tmp / ((double)n*(n-1)));
    }
    return 0;
}

```


---
title: 2016-Multi-University-Traning-Contest1-1002
date: 2016-09-11 21:03:59
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 博弈
categories:
- 2016暑期集训
---
## 题意
n行20列的棋盘上有若干旗子。Alice和Bob每次可以将一枚棋子移动到距离它最近的右边的空格里。谁不能移动，即负。两人都采取最优策略，问先手是否必胜。

## 做法
因为每一行只有20个格子，所以2^20预处理出sg函数，然后求nim和求好
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 20;
int sg[1<<maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sg[0] = 0;
    for (int mask = 1; mask < (1<<maxn); mask++) {
        int last = -1;
        int used[maxn + 5];
        memset(used, 0, sizeof(used));
        for (int i = 0; i < maxn; i++) {
            if(!((mask >> i) & 1)) {
                last = i;
            }
            if(((mask >> i) & 1) && last != - 1) {
                used[sg[mask ^ (1<<i) ^ (1<<last)]] = 1;
            }
        }
        int t = 0;
        while(used[t]) t++;
        sg[mask] = t;
    }
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        while(n--) {
            int m;
            scanf("%d", &m);
            int mask = 0;
            for (int i = 0; i < m; i++) {
                int x;
                scanf("%d", &x);
                mask |= (1<<(20 - x));
            }
            ans ^= sg[mask];
        }
        if(ans) {
            printf("YES\n");
        } else printf("NO\n");
    }
    return 0;
}

```

---
title: 2016-Multi-University-Traning-Contest1-1004
date: 2016-09-11 21:07:36
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 数论
- 线段树
categories:
- 2016暑期集训
---

## 题意
给定长度为n的数列a，q个询问，每次询问l，r，求gcd(al,al+1,...,ar)和有多少对[L,R]，满足1<=L<=R<=n 且gcd(aL, aL+1,...,aR) = gcd(al,al+1,...,ar)

## 做法
对于第一个问，我们可以用线段树维护。
对于第二个问，可以发现对于一个固定端点的区间，其gcd的值最多只有logn个，所以我们nlogn预处理对于每个数x，有多少个区间的gcd等于x，然后查询即可。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 1e5 + 5;
int A[maxn];
int N;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct SegT {
    int a[maxn<<2];
    
    void push_up(int rt) {
        a[rt] = gcd(a[rt<<1], a[rt<<1|1]);
        // pr(rt);
        // prln(a[rt]);
    }
    
    void init() {
        memset(a, 0, sizeof(a));
    }
    
    void build(int l, int r, int rt) {
        if(l == r) {
            a[rt] = A[l - 1];
            // pr(rt); prln(a[rt]);
            return;
        }
        int m = (l + r) >> 1;
        if(l <= m) build(l, m, rt << 1);
        if(m < r) build(m + 1, r, rt << 1 | 1);
        push_up(rt);
    }
    
    int querry(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) {
            return a[rt];
        }
        int m = (l + r) >> 1;
        int res = 0;
        if(L <= m) res = gcd(res, querry(L, R, l, m, rt << 1));
        if(m < R) res = gcd(res, querry(L, R, m + 1, r, rt << 1 | 1));
        return res;
    }
}seg;
int nxt[maxn];
long long sum[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        map<int, long long> m;
        int q, j, pre;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            nxt[i] = i + 1;
        }
        seg.init();
        seg.build(1, N, 1);
        for (int i = N - 1; i >= 0; i--) {
            pre = i;
            for (j = i; j < N; j = nxt[j]) {
                A[j] = gcd(A[j], A[pre]);
                if(A[j] == A[pre]) nxt[pre] = nxt[j];
                m[A[j]] += (nxt[j] - j);
                pre = j;
            }
        }
        scanf("%d", &q);
        printf("Case #%d:\n", Cas);
        for (int i = 0; i < q; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            int a = seg.querry(l, r, 1, N, 1);
            int b = m[a];
            printf("%d %d\n", a, b);
        }
    }
    return 0;
}

```


---
title: 2016-Multi-University-Traning-Contest1-1005
date: 2016-09-11 21:17:39
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 二分图匹配
categories:
- 2016暑期集训
---
## 题意
有n个阴宝石，n个阳宝石。给m个条件，x阳宝石和y阴宝石相邻时，x会变暗。求一个确定的宝石的环排列，满足阴阳相间，且变暗的宝石数目最少。输出最少的变暗宝石数目。

## 做法
标算是爆搜+剪枝
这里有个优雅的复杂度稳定的算法。枚举阴宝石的排列，然后跑二分图匹配。
<!--more-->

## 代码
```cpp
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
#define prln(x) cout << #x << " = " << x << endl
#define pr(x) cout << #x << " = " << x << " "

const int maxn = 9  + 5;
bool can_adj[maxn][maxn];

int G[2*maxn][2*maxn];
int yin[maxn];
int n, m;

bool vis[maxn*2];
int match[maxn*2];

bool dfs(int u) {
    for (int i = 0; i < 2 * n; i++) {
        if(!G[u][i]) continue;
        int v = i;
        if(!vis[v]) {
            vis[v] = 1;
            if(match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
    }
    return false;
}

int bin_match() {
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < 2 * n; i++) {
        if(match[i] == -1) {
            for (int j = 0; j < 2 * n; j++) {
                vis[j] = 0;
            }
            if(dfs(i)) {
                ans++;
            }
        }
    }
    // prln(ans);
    return ans;
}

int solve() {
    memset(G, 0, sizeof(G));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(can_adj[i][yin[j]] && can_adj[i][yin[(j+1) % n]]) {
                // pr(i); prln(yin[j]);
                // pr(i); prln(j);
                G[i][j + n] = 1;
                G[j + n][i] = 1;
            }
        }
    }
    
    return n - bin_match();
}

int work() {
    int ans = n;
    for (int i = 0; i < n; i++) {
        yin[i] = i;
    }
    
    srand(time(NULL));
    for (int i = 0; i < 200; i++) {
        random_shuffle(yin + 1, yin + n);
        ans = min(ans, solve());
    }
    return ans;
}

int main() {
    while(scanf("%d%d", &n, &m) == 2) {
        memset(can_adj, true, sizeof(can_adj));
        
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            // pr(u); prln(v);
            can_adj[u][v] = false;
        }
        int ans;
        if(n == 0) {
            ans = 0;
        } else ans = work();
        printf("%d\n", ans);
    }
}
```

---
title: 2016-Multi-University-Traning-Contest1-1009
date: 2016-09-11 21:24:16
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 插头dp
- 容斥
categories:
- 2016暑期集训
---
## 题意
n\*m的棋盘，有多少种1x2骨牌的完美覆盖，满足棋盘上不会有完整的直线。

## 做法
插头dp，然后2^m容斥行，m^2容斥列。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int mod = 1e9 + 7;
const int maxn = 16;
ll d[maxn + 5][maxn + 5], dp[2][(1<<maxn) + 100];
ll memo[maxn + 5][maxn + 5];

void update(int a, int b, int m, int cur) {
    if((b >> m) & 1) {
        dp[cur][b ^ (1 << m)] = (dp[cur][b ^ (1 << m)] +
                                 dp[cur ^ 1][a]) % mod;
    }
}

void init() {
    // for (int n = 1; n <= maxn; n++) {
    int n = 16;
    for (int m = 1; m <= maxn; m++) {
        int cur = 0;
        memset(dp[cur], 0, sizeof(dp[cur]));
        dp[0][(1<<m) - 1] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cur ^= 1;
                memset(dp[cur], 0, sizeof(dp[cur]));
                for (int  k = 0; k < (1<<m); k++) {
                    update(k, k << 1, m, cur);
                    if(i && !((k >> (m-1)) & 1)) {
                        update(k, (k << 1) ^ (1 << m) ^ 1, m, cur);
                    }
                    if(j && !(k & 1)) {
                        update(k, (k << 1) ^ 3, m, cur);
                    }
                }
                if(j == m - 1) {
                    d[i + 1][m] = dp[cur][(1<<m)-1];
                }
            }
        }
        // d[n][m] = dp[cur][(1<<m)-1];
        // pr(n); pr(m);
        // prln(d[n][m]);
    }
    // }
}

ll cal(int n, int m) {
    if(memo[n][m] != -1) return memo[n][m];
    ll ans = 0;
    for (int mask = 0; mask < (1<<(m-1)); mask++) {
        // prln(mask);
        int last = -1;
        vector<int> w;
        for (int i = 0; i < m - 1; i++) {
            if((mask >> i) & 1) {
                w.push_back(i - last);
                last = i;
            }
        }
        w.push_back(m - 1 - last);
        ll g[maxn + 1];
        for (int i = 1; i <= n;  i++) {
            ll tmp = 1;
            for (int j = 0; j < (int)w.size(); j++) {
                // pr(i); prln(w[j]);
                tmp = tmp * d[i][w[j]] % mod;
                // pr(d[i][w[j]]);
                // prln(tmp);
            }
            g[i] = tmp;
            // printf("i = %d, g[i] = %lld\n", i, g[i]);
        }
        
        ll f[maxn + 1];
        for (int i = 1; i <= n; i++) {
            f[i] = g[i];
            for (int j = 1; j < i; j++) {
                f[i] = (f[i] - f[j] * g[i - j] % mod + mod) % mod;
            }
            // pr(i); prln(f[i]);
        }
        if(__builtin_popcount(mask) & 1) {
            ans = (ans - f[n] + mod) % mod;
        } else {
            ans = (ans + f[n] + mod) % mod;
        }
    }
    return memo[n][m] = ans;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    memset(memo, -1, sizeof(memo));
    init();
    int n, m;
    while(scanf("%d%d", &n, &m) == 2) {
        ll ans = cal(n, m);
        printf("%lld\n", ans);
    }
    return 0;
}

```

---
title: 2016-Multi-University-Traning-Contest1-1011
date: 2016-09-11 21:27:26
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 数学
categories:
- 2016暑期集训
---

## 题意
给出三维空间中的四个点，若它们能构成四面体，输出其内切球心。

## 做法
公式题，没啥意思。

<!--more-->
## 代码
```cpp
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
typedef long double ld;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const double eps = 1e-9;

int sign(ld x) {
    if(x < -eps) {
        return -1;
    } else if(x > eps) {
        return 1;
    } else return 0;
}

struct Point3 {
    ld x, y, z;
    Point3() {}
    Point3(ld x, ld y, ld z): x(x), y(y), z(z) {}
    Point3 operator - (const Point3 &b) const {
        return Point3(x - b.x, y - b.y, z - b.z);
    }
    
    Point3 operator + (const Point3 &b) const {
        return Point3(x + b.x, y + b.y, z + b.z);
    }
    
    ld dot(const Point3 &b) const {
        return x * b.x + y * b.y + z * b.z;
    }
    
    Point3 cross(const Point3 &b) const {
        return Point3(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);
    }
};

typedef Point3 Vector3;


ld sqr(ld x) {
    return x * x;
}

ld dist(const Point3 &a, const Point3 &b) {
    return sqrt((b - a).dot(b - a));
};

ld Area2(Point3 A, Point3 B, Point3 C) {
    ld a = dist(B, C), b = dist(A, C), c = dist(A, B);
    ld s = (a + b + c) / 2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

ld Volume6(Point3 A, Point3 B, Point3 C, Point3 D) {
    return (D-A).dot((B-A).cross(C-A));
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
    while(cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >>
          x4 >> y4 >> z4) {
        Point3 A(x1, y1, z1), B(x2, y2, z2), C(x3, y3, z3), D(x4, y4, z4);
        ld s1 = Area2(B, C, D);
        ld s2 = Area2(A, C, D);
        ld s3 = Area2(A, B, D);
        ld s4 = Area2(B, C, A);
        if(s1 == 0 || s2 == 0 || s3 == 0 || s4 == 0) {
            puts("O O O O");
            continue;
        }
        double x, y, z, r;
        ld t = s1 + s2 + s3 + s4;
        x = (s1 * x1  + s2 * x2 + s3 * x3 + s4 * x4) / t;
        y = (s1 * y1  + s2 * y2 + s3 * y3 + s4 * y4) / t;
        z = (s1 * z1  + s2 * z2 + s3 * z3 + s4 * z4) / t;
        r = abs(Volume6(A, B, C, D))/2/t;
        if(r == 0) {
            puts("O O O O");
        } else {
            printf("%.4f %.4f %.4f %.4f\n", x, y, z, r);
        }
    }
    return 0;
}

```

---
title: 2016-Multi-University-Traning-Contest2-1002
date: 2016-09-11 21:33:57
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 博弈
categories:
- 2016暑期集训
---
## 题意
给定n个点的带权有根树，点i的权值为$W_i$，对于某点s，定义f(s) 为，选择一个点序$v_1,v_2,...,v_m$，要求$v_1 = s$, $v_i$是$v_{i-1}$的祖先。
$$ f(s) = W_{v_1} + \sum_{i=2}^{m}{W_{v_i} \, opt \, W_{v_{i-1}}} $$

## 做法
二进制分块暴力

## 代码
```cpp
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
const int mod = 1e9 + 7;
const int maxn = (1<<16) + 100;
const int maxm = (1<<8);
const int inf = 0x3f3f3f3f;
const ll inff = 0x3f3f3f3f3f3fLL;
ll ds[maxm][maxm];
int A[maxn];
char opt[20];
int OP;
int n;
ll f[maxn];

vector<int> G[maxn];

int op(int a, int b) {
    if(OP == 1) return a & b;
    else if(OP == 2) return a ^ b;
    else return a | b;
}

void dfs(int u) {
    ll ma = 0;
    int low_8 = A[u] & ((1<<8)-1);
    int high_8 = A[u] >> 8;
    for (int h = 0; h < (1<<8); h++) {
        ma = max(ma, (op(high_8, h) << 8) + ds[h][low_8]);
    }
    f[u] = ma;
    ll *buf = new ll[maxm];
    memcpy(buf, ds[high_8], sizeof(ll) * maxm);
    for (int l = 0; l < (1<<8); l++) {
        ds[high_8][l] = max(ds[high_8][l], f[u] + op(l, low_8));
    }
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        dfs(v);
    }
    memcpy(ds[high_8], buf, sizeof(ll) * maxm);
    delete[] buf;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        scanf("%s", opt);
        if(strcmp(opt, "AND") == 0) OP = 1;
        if(strcmp(opt, "XOR") == 0) OP = 2;
        if(strcmp(opt, "OR") == 0) OP = 3;
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i <= n; i++) {
            G[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            int fa;scanf("%d", &fa);
            G[fa].push_back(i);
        }
        for (int i = 0; i < maxm; i++) {
            for (int j = 0; j < maxm; j++) {
                ds[i][j] = -inf;
            }
        }
        memset(f, 0, sizeof(f));
        dfs(1);
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = (ans + ((ll)f[i] + A[i]) * i % mod) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
```

---
title: 2016-Multi-University-Traning-Contest2-1005
date: 2016-09-11 21:42:00
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 计算几何
- 计数
categories:
- 2016暑期集训
---
## 题意
给定平面上n个点的坐标，求有多少点集，满足集合中所有点都在一条直线上。

## 做法
从1到n，枚举一个点，然后按照共线划分等价类搞搞就行，注意点重合的情况。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const ll MOD = 1e9 + 7;
const double inf = 1e15;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) {
            res = (res * x) % mod;
        }
        n >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

const int maxn = 1000 + 5;
struct Point {
    ll x, y;
    double k;
    Point() {}
    Point(ll x, ll y): x(x), y(y) {}
    
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
    
    void read() {
        scanf("%lld%lld", &x, &y);
    }
    
    
    void get_k() {
        if(x != 0) {
            ll g = gcd(x, y);
            ll a = y / g, b = x / g;
            k = double(a) / b;
        } else {
            k = inf;
        }
    }
    
}ps[maxn];
int n;

bool cmp(const Point &a, const Point &b) {
    return a.k < b.k;
}

Point buf[maxn];
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            ps[i].read();
        }
        
        ll ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int cnt = 0;
            int same = 0;
            for (int j = i + 1; j < n; j++) {
                Point t = ps[j] - ps[i];
                if(t.x == 0 && t.y == 0) {
                    same++;
                    continue;
                }
                buf[cnt] = t;
                buf[cnt].get_k();
                // prln(buf[cnt].k);
                cnt++;
            }
            
            ll cnt_same = mod_pow(2, same, MOD);
            sort(buf, buf + cnt, cmp);
            int tmp = 1;
            for (int j = 1; j < cnt; j++) {
                if(buf[j].k == buf[j-1].k) {
                    tmp++;
                } else {
                    ans = (ans + (mod_pow(2, tmp, MOD) - 1) * cnt_same) % MOD;
                    // prln(ans);
                    tmp = 1;
                    // prln(tmp);
                }
            }
            // prln(cnt);
            // prln(tmp);
            if(cnt > 0) ans = (ans + (mod_pow(2, tmp, MOD) - 1) * cnt_same) % MOD;
            ans = (ans + (cnt_same - 1) + MOD) % MOD;
            // prln(ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

```


---
title: 2016-Multi-University-Traning-Contest2-1006
date: 2016-09-11 21:45:31
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 图论
- 树形dp
- tarjan
categories:
- 2016暑期集训
---
## 题意
给定n个点m条边的带权无向图G。定义Gi是从G中删除点i得到的图。
定义一个图G的权值如下：
1. 如果图联通，权值为所有点权的乘积。
2. 如果图不连通，权值为所有连通块权值和。
对于1<=i<=n,求出Gi的权值

## 做法
可以先预处理出原图的权值，对于点i，如果点i不为割点，那么去除点i就是对应联通块的权值除上点i的权值，如果点i为割点，则可以发现它讲图分裂几个部分，其实就是对应图dfs树的祖先和几个子树，所以dfs预处理出每棵子树的权值，然后树形dp转移，注意考虑只有1个点，和根节点时的特殊情况。

<!--more-->
## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const ll mod = 1e9 + 7;

inline ll fast_pow(ll x, ll n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % mod;
        n >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

inline ll inv(ll x) {
    return fast_pow(x, mod - 2);
}

const int maxn = 1e5 + 5;
const int maxm = 4e5 + 5;
struct Edge {
    int to, nxt;
    Edge() {};
}edge[maxm];
int head[maxn], tot;
int n, m;

void init() {
    tot = 0;
    memset(head, -1, sizeof(int) * (n + 1));
}
void add_edge(int u, int v) {
    edge[tot].to = v;
    edge[tot].nxt = head[u];
    head[u] = tot++;
}

int DFN[maxn], Low[maxn], dfsNum;
int w[maxn];
int rt[maxn], cnt_rt;
bool vised[maxn];
ll val[maxn];
ll ans[maxn];
ll Sum;
void dfs(int u) {
    val[u] = w[u];
    vised[u] = true;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if(vised[v]) continue;
        dfs(v);
        val[u] = val[u] * val[v] % mod;
    }
}

ll tarjan(int u, int fa, int root) {
    // pr(u); prln(fa);
    ll res = w[u], sum = 0, rest = w[u];
    DFN[u] = Low[u] = ++dfsNum;
    int cnt_child = 0;
    bool is_cut = false;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if(DFN[v] == -1) {
            cnt_child++;
            ll tmp = tarjan(v, u, root);
            res = (res * tmp) % mod;
            Low[u] = min(Low[v], Low[u]);
            if(fa == -1) {
                sum = (sum + tmp) % mod;
            }
            if(fa == -1 && cnt_child > 1) {
                is_cut = true;
            }
            if(fa != -1 && Low[v] >= DFN[u]) {
                is_cut = true;
                rest = (rest * tmp) % mod;
                sum = (sum + tmp) % mod;
            }
        } else {
            Low[u] = min(Low[u], DFN[v]);
        }
    }
    if(!is_cut) {
        // 孤立点
        if(fa == -1 && cnt_child == 0) {
            ans[u] = (Sum - w[u] + mod) % mod;
        } else {
            ans[u] = ((Sum - val[root] + mod) % mod +
                      val[root] * inv(rest) % mod) % mod;
        }
    } else {
        ll val_fa = val[root] * inv(rest) % mod;
        // prln(sum);
        if(fa != -1) {
            sum = (sum + val_fa) % mod;
        }
        ans[u] = ((Sum - val[root] + mod) % mod + sum) % mod;
    }
    // prln(res);
    return res;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &w[i]);
        }
        init();
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        memset(vised, 0, sizeof(int) * (n + 1));
        cnt_rt = 0;
        Sum = 0;
        for (int i = 1; i <= n; i++) {
            if(!vised[i]) {
                rt[cnt_rt++] = i;
                dfs(i);
                Sum = (Sum + val[i]) % mod;
            }
        }
        memset(DFN, -1, sizeof(int) * (n + 1));
        dfsNum = 0;
        for (int i = 0; i < cnt_rt; i++) {
            int u = rt[i];
            // prln(u);
            tarjan(u, -1, u);
        }
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            // prln(ans[i]);
            res = (res + ans[i] * i) % mod;
        }
        printf("%lld\n", res);
    }
    return 0;
}

```

---
title: 2016-Multi-University-Traning-Contest2-1008
date: 2016-09-11 21:55:33
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 正交凸包
- 扫描线
- bit
categories:
- 2016暑期集训
---

## 题意
给定一个长度为n的01串，m个询问，询问是否存在一个子串，恰好有a个0和b个1.

## 做法
预处理出可行的区间，即对于a属于[l1,r1],b属于[l2,r2]中都是符合条件的，可以发现其刚好对应二维坐标系中的一个矩形，所以可以n^2处理出n^2个这样的矩形。问题等价于(ai,bi)是否位于某个矩形内部，然后可以发现这题很像矩形面积并，我们可以对(ai,bi)按照ai排序，然后用扫描线+线段树处理，这里线段树会超时，换成bit维护线段上一点是否被区间覆盖即可。这题正解是正交凸包+二分，实在想不到。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
//const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;
const int maxm = 5e5 + 5;
struct Bit {
    int bit[maxn * maxn * 2 + 100];
    int n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            bit[i] = 0;
        }
    }
    
    void add(int i, int x) {
        for (; i <= n; i += lowbit(i)) {
            bit[i] += x;
        }
    }
    
    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= lowbit(i)) {
            res += bit[i];
        }
        return res;
    }
}bit;

struct Seg {
    int l1, r1, l2, r2;
    Seg() {}
    Seg(int l1, int r1, int l2, int r2):l1(l1), r1(r1), l2(l2), r2(r2){}
}segs[maxn*maxn*2], buf[maxn*maxn*2];

int cnt_buf;
int V[maxn * maxn * 2 + 100], cnt_v;
int A[maxn];
int ans[maxm];
int n, m;
int cnt_segs;
pair<pii, int> query[maxm];

int id(int x) {
    return lower_bound(V, V + cnt_v, x) - V + 1;
}

bool seg_cmp(const Seg &a, const Seg &b) {
    return a.l1 < b.l1;
}

void add_seg(int l1, int r1, int l2, int r2) {
    segs[cnt_segs++] = Seg(l1, r1, l2, r2);
}


void pre_work() {
    cnt_v = 0;
    cnt_buf = 0;
    cnt_segs = 0;
    for (int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            add_seg(1, A[i], 0, 0);
        } else {
            add_seg(0, 0, 1, A[i]);
        }
        int cnt[2] = {0, 0};
        int l[2], r[2];
        for (int j = i + 1; j < n; j++) {
            l[0] = r[0] = cnt[0];
            l[1] = r[1] = cnt[1];
            l[j % 2] += 1;
            r[j % 2] += A[j];
            l[i % 2] += 1;
            r[i % 2] += A[i];
            add_seg(l[0], r[0], l[1], r[1]);
            cnt[j % 2] += A[j];
        }
    }
    
    for (int i = 0; i < cnt_segs; i++) {
        int &l1 = segs[i].l1, &l2 = segs[i].l2;
        int &r1 = segs[i].r1, &r2 = segs[i].r2;
        // printf("%d %d %d %d\n", l1, r1, l2, r2);
        buf[cnt_buf++] = Seg(l1, 1, l2, r2);
        buf[cnt_buf++] = Seg(r1 + 1, -1, l2, r2);
        // V[cnt_v++] = segs[i].l2;
        V[cnt_v++] = segs[i].l2;
        // V[cnt_v++] = segs[i].r2;
        V[cnt_v++] = segs[i].r2 + 1;
    }
    for (int i = 0; i < m; i++) {
        V[cnt_v++] = query[i].xx.yy;
    }
    sort(V, V + cnt_v);
    cnt_v = unique(V, V + cnt_v) - V;
    // prln("ok");
}

void solve() {
    sort(query, query + m);
    sort(buf, buf + cnt_buf, seg_cmp);
    bit.init(cnt_v + 2);
    for (int i = 0, j = 0; i < m; i++) {
        int a = query[i].xx.xx, b = query[i].xx.yy;
        // prln(a);
        while(j < cnt_buf && buf[j].l1 <= a) {
            bit.add(id(buf[j].l2), buf[j].r1);
            bit.add(id(buf[j].r2) + 1, -buf[j].r1);
            // printf("%d %d %d %d\n", buf[j].l1, buf[j].r1, buf[j].l2,
            //buf[j].r2);
            j++;
        }
        if(bit.sum(id(b)) > 0) {
            ans[query[i].yy] = 1;
        } else {
            ans[query[i].yy] = 0;
        }
        // prln(ans[query[i].yy]);
    }
}

int main() {
#ifdef MATHON
    freopen("1008.in", "r", stdin);
    freopen("1008.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        // pr(n); prln(m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &query[i].xx.xx, &query[i].xx.yy);
            query[i].yy = i;
        }
        pre_work();
        solve();
        for (int i = 0; i < m; i++) {
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}

```

---
title: 2016-Multi-University-Traning-Contest2-1009
date: 2016-09-11 22:05:28
tags:
- ACM
- 2016 暑期集训
- 2016 多校
categories:
- 2016暑期集训
---

## 题意
给定长度为n的数列A的一部分。已知A单调不增，且$A_i \in \,[0,100]$, A不是全0数列
$$ k = \frac{A_1 + A_2}{\sum_{i=1}^{n}A_i} $$
求最大的k

## 做法
贪心一下即可
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 100 + 5;
int A[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(A, -1, sizeof(A));
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            A[x] = y;
        }
        int last = 100;
        for (int i = 1; i <= 2; i++) {
            if(A[i] == -1) {
                A[i] = last;
            }
            last = A[i];
        }
        last = 0;
        for (int i = n; i >= 3; i--) {
            if(A[i] == -1) {
                A[i] = last;
            }
            last = A[i];
        }
        int p = A[1] + A[2], q = 0;
        for (int i = 1; i <= n; i++) {
            q += A[i];
        }
        int g = __gcd(p, q);
        p /= g; q /= g;
        printf("%d/%d\n", p, q);
    }
    return 0;
}
```

---
title: 2016-Multi-University-Traning-Contest2-1011
date: 2016-09-11 22:11:48
tags:
- ACM
- 2016 暑期集训
- 2016 多校
categories:
- 2016暑期集训
---

## 题意
给定n种字符，第i种字符有ai个。求用这些字符构造一些回文串，且字符要全部用完。
最大化最短的回文串长度。输出该长度。

## 做法
贪心
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        int sum = 0, cnt_odd = 0;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            if(x % 2) {
                cnt_odd++;
                sum += x - 1;
            } else {
                sum += x;
            }
        }
        if(cnt_odd == 0) {
            printf("%d\n", sum);
        } else {
            printf("%d\n", sum / (2 * cnt_odd) * 2 + 1);
        }
    }
    return 0;
}

```

---
title: 2016-Multi-University-Traning-Contest2-1012
date: 2016-09-11 22:14:27
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 简单题
categories:
- 2016暑期集训
---
## 题意
暴力模拟题

## 做法
暴力模拟
<!--more-->
## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e5 + 5;
const int maxm = 5e3 + 5;
char s[maxn], p[maxm];
char buf[maxm];
bool used[maxm];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s%s", s, p);
        for (int i = 0; i < n; i++) {
            memcpy(buf, p, m + 1);
            memset(used, false,  m + 1);
            // prln("ok");
            if(i + m <= n) {
                bool ok = true;
                for (int j = 0; j < m - 1; j++) {
                    if(s[i+j] != buf[j] && used[j]) {
                        ok = false;
                        break;
                    } else if(s[i+j] != buf[j] && !used[j]) {
                        if(s[i+j] == buf[j+1]) {
                            swap(buf[j], buf[j+1]);
                            used[j+1] = true;
                        } else {
                            ok = false;
                            break;
                        }
                    }
                }
                if(s[i+m-1] != buf[m-1]) ok = false;
                if(ok) printf("1");
                else printf("0");
            } else printf("0");
        }
        puts("");
    }
    return 0;
}
```


---
title: 2016-Multi-University-Traning-Contest3-1001
date: 2016-09-11 22:19:12
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 简单题
categories:
- 2016暑期集训
---
## 题意
定义$f(n) = floor(sqrt(n)), f^1(n) = f(n),f^y(n)=f(f^{y-1}(n))$

## 做法
简单题
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 100 + 5;
char str[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    vector<ll> V;
    ll x = 2;
    for (int i = 1; i <= 6; i++) {
        // prln(x);
        V.push_back(x);
        x = x * x;
    }
    while(scanf("%s", str) == 1) {
        int len = strlen(str);
        if(len > 12) {
            printf("TAT\n");
        } else {
            sscanf(str, "%lld", &x);
            int p = upper_bound(V.begin(), V.end(), x) - V.begin();
            if(p > 5 || x == 0) {
                printf("TAT\n");
            } else {
                printf("%d\n", p);
            }
        }
    }
    return 0;
}

```

---
title: 2016-Multi-University-Traning-Contest3-1002
date: 2016-09-11 22:22:19
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 高斯消元
categories:
- 2016暑期集训
---
## 题意
签到题

## 做法
<!--more-->
## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    while(scanf("%d", &n) == 1) {
        if(n == 1) {
            double x;
            scanf("%lf", &x);
            printf("%.9f\n", x);
            continue;
        }
        double p1 = 0;
        for (int i = 1; i <= n; i++) {
            p1 += 1.0 * (i - 1);
        }
        p1 /= double(n) * (n - 1);
        double p2 = 0;
        for (int i = 1; i <= n; i++) {
            p2 += 1.0 * (i - 1) * (i - 2);
        }
        p2 /= double(n) * (n - 1) * (n - 2);
        double ans = 0;
        double x;
        scanf("%lf", &x);
        ans += x * p1;
        for (int i = 2; i <= n - 1; i++) {
            scanf("%lf", &x);
            ans += x * p2;
        }
        scanf("%lf", &x);
        ans += x * p1;
        printf("%.9f\n", ans);
    }
    return 0;
}

```


---
title: 2016-Multi-University-Traning-Contest3-1004
date: 2016-09-11 22:26:05
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 简单题
categories:
- 2016暑期集训
---
## 题意
给定一个nxm的矩阵，每个格子中有0，1，2中的一个整数。
可以对矩阵进行若干次如下操作。选定一个格子将其值+2，其上下左右四个格子分别+1。均在模3的意义下进行。求一种方案可以将矩阵清零。

## 做法
高斯消元，因为这里0元素很多，所以高斯消元复杂度并不会超。
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int MAXN = 900 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 3;
int a[MAXN][MAXN];
int x[MAXN];

inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

inline int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

ll inv(ll a, ll m) {
    if(a == 1) return 1;
    return inv(m % a, m) * (m - m / a) % m;
}

int Gauss(int equ, int var) {
    int max_r, col, k;
    for (k = 0, col = 0; k < equ && col < var; k++, col++) {
        max_r = k;
        for (int i = k + 1; i < equ; i++) {
            if(abs(a[i][col]) > abs(a[max_r][col])) max_r = i;
        }
        
        if(a[max_r][col] == 0) {
            // k--;
            continue;
        }
        
        if(max_r != k) {
            for (int j = col; j < var + 1; j++) {
                swap(a[k][j], a[max_r][j]);
            }
        }
        for (int i = k + 1; i < equ; i++) {
            if(a[i][col] != 0) {
                int LCM = lcm(abs(a[i][col]), abs(a[k][col]));
                int ta = LCM / abs(a[i][col]);
                int tb = LCM / abs(a[k][col]);
                if(a[i][col] * a[k][col] < 0) tb = -tb;
                for (int j = col; j < var + 1; j++) {
                    a[i][j] = ((a[i][j] * ta - a[k][j] * tb) % MOD
                               + MOD) % MOD;
                }
            }
        }
    }
    // for (int i = k; i < equ; i++) {
    // if(a[i][col] != 0) {
    // return -1; //无解
    // }
    // }
    //if(k < var) return var - k; // 多解
    for (int i = var - 1; i >= 0; i--) {
        int temp = a[i][var];
        for (int j = i + 1; j < var; j++) {
            if(a[i][j] != 0) {
                temp -= a[i][j] * x[j];
                temp = (temp % MOD + MOD) % MOD;
            }
        }
        if(a[i][i] == 0) x[i] = 0;
        else x[i] = (temp * inv(a[i][i], MOD)) % MOD;
    }
    return 0;
}

int N, M;

void init() {
    memset(a, 0, sizeof(a));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int t = i * M + j;
            if(i > 0) {
                a[(i-1)*M + j][t] = (a[(i-1)*M + j][t] + 1) % MOD;
            }
            a[t][t] = (a[t][t] + 2) % MOD;
            if(i < N - 1) {
                a[(i+1)*M +j][t] = (a[(i+1)*M + j][t] + 1) % MOD;
            }
            if(j > 0) {
                a[i*M + j - 1][t] = (a[i*M + j - 1][t] + 1) % MOD;
            }
            if(j < M - 1) {
                a[i*M + j + 1][t] = (a[i*M + j + 1][t] + 1) % MOD;
            }
        }
    }
}
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &M);
        init();
        int equ = N * M, var = N * M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int x; scanf("%d", &x);
                a[i*M + j][var] = (MOD - x) % MOD;
            }
        }
        // for (int i = 0; i < equ; i++) {
        // for (int j = 0; j <= var; j++) {
        // printf("%d ", a[i][j]);
        // }
        // puts("");
        // }
        // puts("");
        Gauss(equ, var);
        // for (int i = 0; i < equ; i++) {
        // for (int j = 0; j <= var; j++) {
        // printf("%d ", a[i][j]);
        // }
        // puts("");
        // }
        // puts("");
        int cnt = 0;
        for (int i = 0; i < var; i++) {
            cnt += x[i];
        }
        printf("%d\n", cnt);
        for (int i = 0; i < var; i++) {
            for (int j = 0; j < x[i]; j++) {
                printf("%d %d\n", i / M + 1, i % M + 1);
            }
        }
    }
    return 0;
}

```


---
title: 2016-Multi-University-Traning-Contest3-1005
date: 2016-09-11 22:31:53
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 主席树
categories:
- 2016暑期集训
---
## 题意
给定n个点的有根数，根为1.
给出q个询问。每次询问给出一个点集A1,A2,...,Ax。
定义x是好点当且仅当不存在一个A中的点事x的祖先。
对于每个询问，求出好点之间距离的最大值，最小值，以及和。
<!--more-->
## 做法
我们可以用主席树对于所有点，维护出他到所有点的距离。

大致过程就是，对于一号点，他到所有点的距离为该点的深度减一。
接着我们~DFS~整棵树，每到一个节点，就将子树中的点距离减一，不是子树的点距离加一。
我们可以得到每一个点的~DFS~序，这样只需要用主席树支持区间加减，维护区间和、区间最小值、区间最大值即可。

对于每次询问，所给的~Ai~都对应一些~DFS~序区间，我们把这些区间取并，然后取补集。
这样整个~DFS~序会有~KK~段区间是

## 代码
```cpp
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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }
const ll INF = 1e15;
const int maxk = 2e5 + 5;
const int MAXN = 5e4 + 5;
vector<int> G[MAXN];
int L[MAXN], R[MAXN], dfsNum;
int root[MAXN];
int dep[MAXN];
int N, Q;

void dfs(int u, int fa, int deep) {
    L[u] = ++dfsNum;
    dep[dfsNum] = deep;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa) continue;
        dfs(v, u, deep + 1);
    }
    R[u] = dfsNum;
}

struct HJT_Tree {
    struct Node {
        int ls, rs, Max, Min;
        ll sum, lazy;
    }T[MAXN * 50];
    int tot;
    void init() {
        tot = 0;
    }
    
    void up(int u, int len) {
        T[u].sum = T[T[u].ls].sum + T[T[u].rs].sum + T[u].lazy * len;
        T[u].Min = min(T[T[u].ls].Min, T[T[u].rs].Min) + T[u].lazy;
        T[u].Max = max(T[T[u].ls].Max, T[T[u].rs].Max) + T[u].lazy;
    }
    
    void build(int &u, int l, int r) {
        u = ++tot;
        T[u].lazy = 0;
        int m = (l + r) >> 1;
        if(l == r) {
            T[u].Max = T[u].Min = T[u].sum = dep[l];
            return;
        }
        build(T[u].ls, l, m);
        build(T[u].rs, m + 1, r);
        up(u, r - l + 1);
    }
    
    void Modify(int &u, int l, int r, int x, int y, int z) {
        T[++tot] = T[u];
        u = tot;
        int m = (l + r) >> 1;
        if(x <= l && r <= y) {
            T[u].Max += z;
            T[u].Min += z;
            T[u].sum += (ll)z * (r - l + 1);
            T[u].lazy += z;
            return;
        }
        if(x <= m) Modify(T[u].ls, l, m, x, y, z);
        if(m  < y) Modify(T[u].rs, m + 1, r, x, y, z);
        up(u, r - l + 1);
    }
    
    ll query1(int u, int l, int r, int x, int y) {
        if(x == l && r == y) {
            return T[u].sum;
        }
        int m = (l + r) >> 1;
        ll ans = (ll)(y - x + 1) * T[u].lazy;
        if(y <= m) ans += query1(T[u].ls, l, m, x, y);
        else if(x > m) ans += query1(T[u].rs, m + 1, r, x, y);
        else {
            ans += query1(T[u].ls, l, m, x, m);
            ans += query1(T[u].rs, m + 1, r, m + 1, y);
        }
        // pr(l); prln(r);
        // pr(u);
        // prln(ans);
        return ans;
    }
    
    ll query2(int u, int l, int r, int x, int y) {
        ll ans = INF;
        if(x <= l && r <= y) {
            return T[u].Min;
        }
        int m = (l + r) >> 1;
        if(x <= m) ans = min(ans, query2(T[u].ls, l, m, x, y) + T[u].lazy);
        if(m < y) ans = min(ans, query2(T[u].rs, m + 1, r, x, y) + T[u].lazy);
        return ans;
    }
    
    ll query3(int u, int l, int r, int x, int y) {
        ll ans = 0;
        if(x <= l && r <= y) {
            return T[u].Max;
        }
        int m = (l + r) >> 1;
        if(x <= m) ans = max(ans, query3(T[u].ls, l, m, x, y) + T[u].lazy);
        if(m < y) ans = max(ans, query3(T[u].rs, m + 1, r, x, y) + T[u].lazy);
        return ans;
    }
    
}tree;

void dfs2(int u, int fa) {
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa) continue;
        root[v] = root[u];
        tree.Modify(root[v], 1, N, 1, N, 1);
        tree.Modify(root[v], 1, N, L[v], R[v], -2);
        dfs2(v, u);
    }
}

pii inter[maxk*2];
int cnt_inter;
int main(void) {
#ifdef MATHON
    freopen("1005.in", "r", stdin);
    freopen("1005.txt", "w", stdout);
#endif
    int Cas = 0;
    while(scanf("%d%d", &N, &Q) == 2) {
        for (int i = 0; i <= N; i++) {
            G[i].clear();
        }
        for (int i = 0; i < N - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v); G[v].push_back(u);
        }
        memset(root, 0, sizeof(root));
        dfsNum = 0;
        dfs(1, -1, 0);
        tree.init();
        tree.build(root[1], 1, N);
        dfs2(1, -1);
        int last_ans = 0;
        while(Q--) {
            int K, P, T;
            ++Cas;
            bool debug = false;
            // if(Cas == 11) debug = true;
            scanf("%d%d%d", &K, &P, &T);
            if(debug) {
                printf("K = %d P = %d T = %d\n", K, P, T);
            }
            P = (P + last_ans) % N + 1;
            if(debug) {
                printf("K = %d P = %d T = %d\n", K, P, T);
            }
            cnt_inter = 0;
            for (int i = 1; i <= K; i++) {
                int x; scanf("%d", &x);
                // inter.push_back(pii(L[x], 1));
                // inter.push_back(pii(R[x] + 1, -1));
                inter[cnt_inter++] = pii(L[x], 1);
                inter[cnt_inter++] = pii(R[x] + 1, -1);
                // pr(L[x]); prln(R[x]);
            }
            // inter.push_back(pii(N + 1, 1));
            inter[cnt_inter++] = pii(N + 1, 1);
            sort(inter, inter + cnt_inter);
            int last = 1, flag = 0, ok = 1;
            ll ans;
            if(T == 1) {
                ans = 0;
            } else if(T == 3) {
                ans = -1;
            } else ans = INF;
            
            bool suc = false;
            for (int i = 0; i < cnt_inter; i++) {
                flag += inter[i].yy;
                if(flag == 0) {
                    last = inter[i].xx;
                    ok = 1;
                }
                if(flag == 1 && ok) {
                    ok = 0;
                    int l = last, r = inter[i].xx - 1;
                    if(l > r) continue;
                    if(debug) {
                        pr(l); prln(r);
                    }
                    suc = true;
                    if(T == 1) {
                        // pr(l); prln(r);
                        ll tmp = tree.query1(root[P], 1, N, l, r);
                        // prln(tmp);
                        ans += tmp;
                    } else if(T == 2) {
                        ans = min(ans, tree.query2(root[P], 1, N, l, r));
                    } else if(T == 3) {
                        ll tmp = tree.query3(root[P], 1, N, l, r);
                        // prln(tmp);
                        ans = max(ans, tmp);
                    }
                }
            }
            if(T == 1 && suc == false) ans = -1;
            if(T == 2 && ans == INF) ans = -1;
            if(ans == -1) last_ans = 0;
            else last_ans = ans;
            printf("%lld\n", ans);
        }
    }
    return 0;
}

```

---
title: 2016-Multi-University-Traning-Contest3-1007
date: 2016-09-11 22:39:54
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 树形dp
categories:
- 2016暑期集训
---

## 题意
给定一棵n个点的数。
你可以任意选取一个起点，每次可以经过一条边走到一个相邻的结点，也可以使用一次传送到任意一个结点。要求一条边不能连续经过两次。结束条件是经过树上每条边至少一次。
求在最小化传送次数的情况下，最少需要经过的边数。
## 做法
树形dp
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int cnt_leaves[maxn];
int dp[maxn][2];
vector<int> G[maxn];

void dfs(int u, int fa) {
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa) continue;
        dfs(v, u);
        cnt_leaves[u] += cnt_leaves[v];
        dp[u][0] += dp[v][0] + ((cnt_leaves[v] & 1) ? 1 : 2);
    }
    
    dp[u][1] = dp[u][0];
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa) continue;
        dp[u][1] = min(dp[u][1],
                       dp[u][0] - dp[v][0] + dp[v][1] + ((cnt_leaves[v] & 1) ? 1 : -1));
    }
    if(G[u].size() == 1) {
        dp[u][0] = 0;
        dp[u][1] = 0;
        cnt_leaves[u] =  1;
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    int n;
    while(T--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        memset(cnt_leaves, 0, sizeof(cnt_leaves));
        memset(dp, 0, sizeof(dp));
        if(n == 2) {
            puts("1");
            continue;
        }
        int u = 1;
        for (u = 1; u <= n && G[u].size() == 1; u++);
        dfs(u, -1);
        printf("%d\n", dp[u][cnt_leaves[u] & 1]);
    }
    return 0;
}

```

---
title: 2016-Multi-University-Traning-Contest3-1010
date: 2016-09-11 22:42:43
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 物理题
categories:
- 2016暑期集训
---
## 题意
平面直角坐标系上，有一艘小船在(0,a)。河流带着小船朝x轴正方向运动，速度v2。小船船速v1，航向始终指向(0,0)。求需要多少时间小船能到达(0,0)。如果永远无法到达，输出"Infinity"。

## 做法
推出公式即可
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int a, v1, v2;
    while(scanf("%d%d%d", &a, &v1, &v2) == 3) {
        if(a == 0) {
            printf("0\n");
        } else {
            if(v1 <= v2) {
                printf("Infinity\n");
            } else {
                printf("%.10f\n", double(a) * v1 / (v1 * v1 - v2 * v2));
            }
        }
    }
    return 0;
}

```


---
title: 2016-Multi-University-Traning-Contest4-1001
date: 2016-09-11 22:47:46
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- kmp
categories:
- 2016暑期集训
---

## 题意
给一个模式串p，一个字符串s，p有两种题意，问s可以解释为多少种意思。
## 做法
kmp + dp
<!--more-->
## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

void get_next(char x[], int m, int next[]) {
    int i, j;
    j = next[0] = -1;
    i = 0;
    while(i < m) {
        while(j != -1 && x[i] != x[j]) j = next[j];
        next[++i] = ++j;
    }
}

/* 优化版本 */
void get_next_o(char x[], int m, int kmpNext[]) {
    int i, j;
    j = kmpNext[0] = -1;
    i = 0;
    while(i < m) {
        while(j != -1 && x[i] != x[j]) j = kmpNext[j];
        if(x[++i] == x[++j]) kmpNext[i] = kmpNext[j];
        else kmpNext[i] = j;
    }
}

const int maxn = 1e5 + 5;
int nxt[maxn];
bool vised[maxn];
int kmp_count(char x[], int m, char y[], int n) {
    int i, j;
    int ans = 0;
    get_next_o(x, m, nxt);
    i = j = 0;
    while(i < n) {
        while(j != -1 && y[i] != x[j]) j = nxt[j];
        i++; j++;
        if(j >= m) {
            vised[i] = true;
            ans++;
            j = nxt[j];
        }
    }
    return ans;
}

char A[maxn], B[maxn];
ll dp[maxn][2];
const ll mod = 1e9 + 7;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%s%s", A, B);
        int lena = strlen(A), lenb = strlen(B);
        memset(vised, 0, sizeof(vised));
        kmp_count(B, lenb, A, lena);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= lena; i++) {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
            if(vised[i]) {
                dp[i][1] = (dp[i-lenb][0] + dp[i-lenb][1]) % mod;
            }
        }
        printf("Case #%d: %lld\n", Cas, (dp[lena][0] + dp[lena][1]) % mod);
    }
    return 0;
}

```

---
title: 2016-Multi-University-Traning-Contest4-1003
date: 2016-09-11 22:49:34
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 高维前缀和
categories:
- 2016暑期集训
---
## 题意
给定n个点m条边的无向连通图。求图中极小割集的数量。
定义一个图的割集为一个边集，且删去该集合中的边后图不再连通。
定义一个图的极小割集为不包含任何子割集的割集。

## 做法
极小割边集的定义下割边集恰好会将原图分成两块。枚举左右两块是否独立连通。块连通必然可以删掉一个点，这个点与剩下的点有边且剩下的点连通，可以先状压每个点的边, DP转移即可。
接下来要处理的是将两个块之间的边加一。这部分可以处理成将左块中的边减一，右块中的边减一，整体加一。操作变成了把一个块的边加权值的操作。考虑一条边表达成形如 0..010..010..00..010..010..0的形式，它在所有块中的权值总和，便是求一遍把这个形式作为子集的集合的权值和，求一遍高维前缀和就可以了。

<!--more-->
## 代码
```cpp

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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 22;
int edge[maxn];
int n, m;
int cnt[1<<maxn];
int U[maxn*maxn], V[maxn*maxn];
int ind[1<<maxn];

inline int lowbit(int x) {
    return x & (-x);
}

bool check(int mask) {
    int done = 0;
    int did = lowbit(mask);
    while(ind[lowbit(did^done)] != -1) {
        int u = ind[lowbit(did^done)];
        // prln(u);
        done |= 1<<u;
        int v = mask & edge[u];
        did |= v;
    }
    // pr(mask); prln(done);
    return done == mask;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    memset(ind, -1, sizeof(ind));
    for (int i = 0; i < maxn; i++) ind[1<<i] = i;
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d", &n, &m);
        memset(edge, 0, sizeof(edge));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            edge[u] |= 1 << v;
            edge[v] |= 1 << u;
            U[i] = u; V[i] = v;
        }
        int base = (1<<n) - 1;
        int tot = 0;
        for (int mask = 1; mask < base; mask++) {
            if(mask & 1) {
                if(check(mask) && check(mask ^ base)) {
                    // prln(mask);
                    cnt[mask] = 1; cnt[mask ^ base] = 1;
                    tot++;
                }
            }
        }
        for (int i = 1<<n; i > 0; i >>= 1) {
            for (int j = 0; j <= base; j++) {
                if(i & j) {
                    cnt[j ^ i] += cnt[j];
                }
            }
        }
        printf("Case #%d:", Cas);
        for (int i = 0; i < m; i++) {
            int u = U[i], v = V[i];
            printf(" %d", tot - cnt[(1<<u) | (1<<v)]);
        }
        puts("");
    }
    return 0;
}

```

---
title: 2016-Multi-University-Traning-Contest4-1005
date: 2016-09-11 22:52:01
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 中国剩余定理
categories:
- 2016暑期集训
---
## 题意
给定n元数组p和a。
求[L,R]中有多少整数k满足k mod pi ≠ ai，且k是7的倍数

## 做法
中国剩余定理,这里需要注意直接乘法会溢出，需要快速乘
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

ll Extended_Euclid(ll a,ll b,ll &x,ll &y)    //扩展欧几里得算法
{
    ll d;
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    d= Extended_Euclid(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

ll mod_multipy(ll a, ll b, ll mod) {
    ll res = 0;
    while(b > 0) {
        if(b & 1) {
            res = (res + a) % mod;
        }
        b >>= 1;
        a = (a + a) % mod;
    }
    return res;
}

ll Chinese_Remainder(ll a[],ll w[],ll len)    //中国剩余定理  a[]存放余数  w[]存放两两互质的数
{
    ll i,d,x,y,m,n,ret;
    ret=0;
    n=1;
    for (i=0;i<len;i++)
        n*=w[i];
    for (i=0;i<len;i++)
    {
        m = n/w[i];
        d=Extended_Euclid(w[i],m,x,y);
        ret=(ret+(__int128)y*m*a[i])%n;
        // ret = (ret + mod_multipy(mod_multipy(y, m, n), a[i], n)) % n;
    }
    return (n+ret%n)%n;
}

ll cal(ll x, ll y, ll m, ll a) {
    ll ans1 = (x - 1) / m + ((x - 1) % m >= a);
    ll ans2 = y / m + (y % m >= a);
    return ans2 - ans1;
}

const int maxn = 25;
int n;
ll x, y;
int p[maxn], a[maxn];
ll A[maxn], M[maxn];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%lld%lld", &n, &x, &y);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p[i], &a[i]);
        }
        __int128 ans = 0;
        M[0] = 7, A[0] = 0;
        int cnt_n = 1;
        for (int mask = 0; mask < (1<<n); mask++) {
            int cnt_one = __builtin_popcount(mask);
            cnt_n = 1;
            ll tot = 7;
            for (int i = 0; i < n; i++) {
                if((mask>>i) & 1) {
                    M[cnt_n] = p[i];
                    A[cnt_n++] = a[i];
                    tot *= p[i];
                }
            }
            ll rem = Chinese_Remainder(A, M, cnt_n);
            if(cnt_one & 1) {
                ans -= cal(x, y, tot, rem);
            } else {
                ans += cal(x, y, tot, rem);
            }
            // pr(mask);
            // prln(ans);
        }
        printf("Case #%d: %lld\n", Cas, (ll)ans);
    }
    return 0;
}

```

---
title: 2016-Multi-University-Traning-Contest4-1009
date: 2016-09-11 22:55:33
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- 网络流
categories:
- 2016暑期集训
---
## 题意
最大权闭合子图问题

## 做法
网络流，详情见国家集训队论文
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int inf = 0x3f3f3f3f;
const int maxv = 30000+ 5;

struct Dinic {
    struct edge {
        int to, cap, rev;
        edge() {}
        edge(int to, int cap, int rev):to(to), cap(cap), rev(rev) {}
    };
    
    vector<edge> G[maxv];
    int num_v;
    int level[maxv];
    int iter[maxv];
    
    void add_edge(int from, int to, int cap) {
        G[from].push_back(edge(to, cap, (int)G[to].size()));
        G[to].push_back(edge(from, 0, (int)G[from].size() - 1));
    }
    
    void init(int num_v) {
        this->num_v = num_v;
        for (int i = 0; i <= num_v; i++) G[i].clear();
    }
    
    void bfs(int s) {
        memset(level, -1, sizeof(level));
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()) {
            int v = que.front(); que.pop();
            for (int i = 0; i < (int)G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < (int)G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if( d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    
    int max_flow(int s, int t) {
        int flow = 0;
        for (;;) {
            bfs(s);
            if(level[t] < 0) return flow;
            memset(iter, 0, sizeof(iter));
            int f;
            while((f = dfs(s, t, inf)) > 0) {
                flow += f;
            }
        }
    }
}dinic;

const int maxn = 100 + 5;
char str[maxn];
int A[10], B[10];
int w[maxn][maxn];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int n; scanf("%d", &n);
        scanf("%s", str);
        for (int i = 0; i < 10; i++) {
            scanf("%d%d", &A[i], &B[i]);
        }
        int tot = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &w[i][j]);
                tot += w[i][j];
            }
        }
        dinic.init(maxv - 1);
        int s = n * n + n + 15, t = s + 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dinic.add_edge(i * n + j, n * n + i, inf);
                dinic.add_edge(i * n + j, n * n + j, inf);
                dinic.add_edge(s, i * n + j, w[i][j] + w[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            dinic.add_edge(n * n + i, t, A[str[i] - '0']);
            dinic.add_edge(n * n + i, n * n + n + str[i] - '0', inf);
        }
        for (int i = 0; i < 10; i++) {
            dinic.add_edge(n * n + n + i, t, B[i] - A[i]);
        }
        int min_cut = dinic.max_flow(s, t);
        // prln(min_cut);
        printf("Case #%d: %d\n", Cas, tot - min_cut);
    }
    return 0;
}

```


---
title: 2016-Multi-University-Traning-Contest4-1010
date: 2016-09-11 22:58:25
tags:
- ACM
- 2016 暑期集训
- 2016 多校
- LIS
categories:
- 2016暑期集训
---

## 题意
给定长度为n的数列a。你可以将0改成任意整数。
求改动后最长上升子序列的最大值

## 做法
LIS问题变种，我是设置一个flag，然后二分来做，也可以对于每个权值S[i],减去i前面的0的个数，在做LIS，最后加上0的个数
<!--more-->

## 代码
```cpp
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e5 + 5;
int dp[maxn*2];
int S[maxn];
int off;
int n;
int head, tail;

int bin_search(int x) {
    int l = head - 1, r = tail;
    while(l < r - 1) {
        int m = (l + r) >> 1;
        if(dp[m] + off >= x) {
            r = m;
        } else l = m;
    }
    return r;
}
const int inf = 0x3f3f3f3f;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &S[i]);
        }
        memset(dp, -inf, sizeof(dp));
        head = tail = maxn;
        off = 0;
        for (int i = 0; i < n; i++) {
            int a = S[i];
            if(a == 0) {
                head--;
                off++;
                dp[head] = -off;
            } else {
                int p = bin_search(a);
                if(p == tail) {
                    dp[tail++] = a - off;
                } else {
                    dp[p] = a - off;
                }
            }
        }
        printf("Case #%d: %d\n", Cas, tail - head);
    }
    return 0;
}

```


---
title: 2016-Multi-University-Traning-Contest5-1001
date: 2016-09-11 23:02:43
tags:
- ACM
- 2016 暑期集训
- 2016 多校
categories:
- 2016暑期集训
---
<!--more-->
## 代码
```cpp
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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }
const int maxn = 2000 + 5;
double dp[maxn][25];
const double inf = 1e15;
int K, W;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    K = 2001, W = 15;
    W = min(W, 15);
    
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = inf;
        }
    }
    
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= W; j++) {
            for (int k = 1; k <= i; k++) {
                dp[i][j] = min(dp[i][j],
                               dp[k-1][j-1] * k / (i + 1) +
                               dp[i-k][j] * (i + 1 - k) / (i + 1) + 1);
            }
        }
    }
    while(~scanf("%d%d", &K, &W)) {
        W = min(W, 15);
        printf("%.6f\n", dp[K][W]);
    }
    return 0;
}

```

---
title: 2016-Multi-University-Traning-Contest5-1003
date: 2016-09-11 23:03:40
tags:
- ACM
- 2016 暑期集训
- 2016 多校
categories:
- 2016暑期集训
---
<!--more-->
## 代码
```cpp
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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }
const int maxn = 1e6 + 5;
int A[maxn];
int n;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        int ans = 0;
        ll sum = 0;
        for (int i = n; i > 0; i--) {
            sum += A[i];
            if(sum >= 0) {
                ans++;
                sum = 0;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

```

---
title: 2016-Multi-University-Traning-Contest5-1004
date: 2016-09-11 23:04:43
tags:
- ACM
- 2016 暑期集训
- 2016 多校
categories:
- 2016暑期集训
---
<!--more-->
## 代码
```cpp
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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }
const int MAXN = 2000 + 5;

struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y): x(x), y(y) {}
    void read() {
        scanf("%lld%lld", &x, &y);
    }
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
    ll cross(const Point &b) const {
        return x * b.y - y * b.x;
    }
    ll dot(const Point &b) const {
        return x * b.x + y * b.y;
    }
    void print() {
        printf("x = %lld, y = %lld\n", x, y);
    }
}ps[MAXN];
int n;

bool cmp(const Point &a, const Point &b) {
    if(a.y * b.y <= 0) {
        if(a.y > 0 || b.y > 0) return a.y < b.y;
        if(a.y == 0 && b.y == 0) return a.x < b.x;
    }
    return a.cross(b) > 0;
}

Point buf[MAXN * 2];

int main(void) {
#ifdef MATHON
    freopen("1004.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            ps[i].read();
        }
        ll ans = 0;
        for (int k = 0; k < n; k++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if(k == j) continue;
                buf[cnt++] = ps[j] - ps[k];
            }
            sort(buf, buf + cnt, cmp);
            memcpy(buf + cnt, buf, sizeof(Point) * cnt);
            ll tmp = 0;
            for (int i = 0, j = 0; i < cnt; i++) {
                if(i == j) while(j < i + cnt && buf[i].cross(buf[j]) == 0 && buf[i].dot(buf[j]) > 0) j++;
                while(j < i + cnt && buf[i].cross(buf[j]) > 0 && buf[i].dot(buf[j]) > 0) j++;
                tmp += j - i - 1;
            }
            tmp = (cnt) * (cnt - 1) / 2  - tmp;
            ans += tmp;
        }
        ans = ll(n) * (n -1) * (n - 2) / 6 - ans;
        printf("%lld\n", ans);
    }
    return 0;
}

```


---
title: 2016-Multi-University-Traning-Contest5-1005
date: 2016-09-11 23:05:30
tags:
- ACM
- 2016 暑期集训
- 2016 多校
categories:
- 2016暑期集训
---
<!--more-->
## 代码
```cpp
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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
struct Manacher {
    char s[MAXN << 1];
    int n, p[MAXN << 1];
    void init(char *a, int len) {
        s[0] = '@'; s[1] = '#'; n = 2;
        for (int i = 0; i < len; i++) {
            s[n++] = a[i];
            s[n++] = '#';
        }
        s[n] = '\0';
    }
    
    int run() {
        int mx = 0, id = 0, ret = 0;
        for (int i = 1; i < n; i++) {
            p[i] = mx > i ? min(mx - i, p[2 * id - i]) : 1;
            while(s[i - p[i]] == s[i + p[i]]) p[i]++;
            if(i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
            ret = max(ret, p[i] - 1);
        }
        return ret;
    }
} manacher;


char str[MAXN];
ll cnt_pre[MAXN<<1], cnt_back[MAXN<<1];
ll flag[MAXN<<1], flag2[MAXN<<1];
int main(void) {
#ifdef MATHON
    freopen("1005.in", "r", stdin);
    freopen("1005.txt", "w", stdout);
#endif
    while(scanf("%s", str) == 1) {
        int len = strlen(str);
        manacher.init(str, len);
        manacher.run();
        int *p = manacher.p, n = manacher.n;
        memset(cnt_pre, 0, sizeof(ll) * n);
        memset(cnt_back,0, sizeof(ll) * n);
        memset(flag, 0, sizeof(ll) * n);
        memset(flag2, 0, sizeof(ll) * n);
        
        for (int i = 1; i < n; i++) {
            flag[i] += i;
            flag[i + p[i]] -= i;
            flag2[i] += 1;
            flag2[i + p[i]] -= 1;
        }
        
        ll tmp = 0, tmp2 = 0;
        for (int i = 1; i < n; i++) {
            // pr(i);
            // prln(flag[i]);
            tmp += flag[i];
            tmp2 += flag2[i];
            if(i % 2 == 0) {
                cnt_pre[i/2] = tmp  - i * tmp2 / 2;
            }
        }
        memset(flag, 0, sizeof(ll) * n);
        memset(flag2, 0, sizeof(ll) * n);
        for (int i = 1; i < n; i++) {
            flag[i] += i;
            flag[i - p[i]] -= i;
            flag2[i] += 1;
            flag2[i - p[i]] -= 1;
        }
        tmp = 0, tmp2 = 0;
        for (int i = n - 1; i >= 1; i--) {
            tmp += flag[i];
            tmp2 += flag2[i];
            if(i % 2 == 0) {
                cnt_back[i / 2] = tmp - i * tmp2/ 2;
            }
        }
        ll ans = 0;
        for (int i = 1; i < len; i++) {
            ans = (ans + (cnt_pre[i] % mod) * (cnt_back[i+1] % mod)) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}

```


---
title: 2016-Multi-University-Traning-Contest5-1007
date: 2016-09-11 23:06:01
tags:
- ACM
- 2016 暑期集训
- 2016 多校
categories:
- 2016暑期集训
---
<!--more-->
## 代码
```cpp
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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }
const int MAX_LEN = 20;
const int MAXK = 6;
map<vector<int>, ll> dp[MAX_LEN][MAXK];
ll L, R;
int K;
ll dfs(int pos, vector<int> pre, int limit, vector<int> &dig) {
    if(pos < 0) return 1;
    if(!limit && dp[pos][K].find(pre) != dp[pos][K].end()) {
        return dp[pos][K][pre];
    }
    int last = limit ? dig[pos] : 9;
    ll ret = 0;
    for (int i = 0; i <= last; i++) {
        if(find(pre.begin(), pre.end(), i) != pre.end()) continue;
        vector<int> nxt;
        for(int j = ((int)pre.size() == K - 1 ? 1 : 0); j < (int)pre.size(); j++) {
            nxt.emplace_back(pre[j]);
        }
        if(!pre.empty() || i != 0) nxt.emplace_back(i);
        ret += dfs(pos - 1, nxt, limit && i == last, dig);
    }
    if (!limit) {
        dp[pos][K][pre] = ret;
    }
    return ret;
}

ll cal(ll x) {
    vector<int> dig;
    if(x == 0) dig.push_back(0);
    while(x > 0) {
        dig.emplace_back(x % 10);
        x /= 10;
    }
    return dfs(dig.size() - 1, vector<int>(), 1, dig);
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%lld%lld%d", &L, &R, &K) == 3) {
        printf("%lld\n", cal(R) - cal(L-1));
    }
    return 0;
}

```


---
title: 2016-Multi-University-Traning-Contest5-1011
date: 2016-09-11 23:07:24
tags:
- ACM
- 2016 暑期集训
- 2016 多校
categories:
- 2016暑期集训
---
<!--more-->
## 代码
```cpp
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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }
const ll mod = 1e9 + 7;
const int maxn = 1000 + 5;
ll dp[maxn][maxn];
int n, m;
int A[maxn], B[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &B[i]);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if(A[i] == B[j]) {
                    dp[i][j] = (dp[i-1][j-1] + 1) % mod;
                }
                dp[i][j] = (dp[i][j] + dp[i-1][j] +
                            dp[i][j-1] - dp[i-1][j-1] + mod) % mod;
            }
        }
        printf("%lld\n", dp[n][m]);
    }
    return 0;
}

```


---
title: 2016-Multi-University-Traning-Contest5-1012
date: 2016-09-11 23:07:56
tags:
- ACM
- 2016 暑期集训
- 2016 多校
categories:
- 2016暑期集训
---
<!--more-->
## 代码
```cpp
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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const int maxn = 5e4 + 5;
struct BIT {
    int bit[maxn + 5];
    int n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            bit[i] = 0;
        }
    }
    void update(int i, int add) {
        for (; i <= n; i += lowbit(i)) {
            bit[i] += add;
        }
    }
    
    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= lowbit(i)) {
            res += bit[i];
        }
        return res;
    }
}bit;
int n;
int A[maxn];
int pre_small[maxn], pre_greater[maxn], back_small[maxn],
back_greater[maxn];
int V[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            V[i-1] = A[i];
        }
        sort(V, V + n);
        bit.init(n + 4);
        for (int i = 1; i <= n; i++) {
            int id = lower_bound(V, V + n, A[i]) - V + 2;
            pre_small[i] = bit.sum(id - 1);
            pre_greater[i] = (i - 1) - bit.sum(id);
            // pr(pre_small[i]); prln(pre_greater[i]);
            bit.update(id, 1);
        }
        bit.init(n + 4);
        for (int i = n; i >= 1; i--) {
            int id = lower_bound(V, V + n, A[i]) - V + 2;
            back_small[i] = bit.sum(id - 1);
            back_greater[i] = (n - i) - bit.sum(id);
            // pr(back_small[i]); prln(back_greater[i]);
            bit.update(id, 1);
        }
        ll ans = 0;
        ll sum_1 = 0, sum_2 = 0;
        for (int i = 1; i <= n; i++) {
            sum_1 += pre_small[i];
            sum_2 += pre_greater[i];
        }
        // pr(sum_1); prln(sum_2);
        ans = sum_1 * sum_2;
        for (int i = 1; i <= n; i++) {
            // ans -= (ll)back_greater[i] * back_small[i];
            // ans -= (ll)back_greater[i] * pre_greater[i];
            // ans -= (ll)pre_small[i] * back_greater[i];
            // ans -= (ll)pre_small[i] * pre_greater[i];
            ans -= (ll)pre_small[i] * back_small[i];
            ans -= (ll)back_greater[i] * back_small[i];
            ans -= (ll)pre_small[i] * pre_greater[i];
            ans -= (ll)back_greater[i] * pre_greater[i];
        }
        cout << ans << endl;
    }
    return 0;
}

```


