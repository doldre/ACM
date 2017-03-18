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

const int MAXN = 1e5 + 5;
int prime[MAXN], cnt_prime;
bool is_prime[MAXN];

void init() {
    memset(is_prime, true, sizeof(is_prime));
    cnt_prime = 0;
    for (int i = 2; i <= MAXN; i++) {
        if(is_prime[i]) {
            prime[cnt_prime++] = i;
            for (int j = i + i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}


const int inf = 0x3f3f3f3f;
const int maxv = 1000 + 5;

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

bool isprime(int x) {
    for (int i = 0; i < cnt_prime && (ll)prime[i] * prime[i] <= x; i++) {
        if(x % prime[i] == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int n, s;
        scanf("%d%d", &n, &s);
        int s1 = max(s + 1, n + 1);
        int cnt = 0;
        for (int i = s1; i <= s + n; i++) {
            if(isprime(i)) cnt++;
            if(cnt >= 2) break;
        }
        printf("Case #%d: ", Cas);
        if(cnt >= 2) {
            puts("No");
        } else {
            int e2 = min(n, s);
            dinic.init(s + n - s1 + e2 + 10);
            for (int i = s1; i <= s + n; i++) {
                for (int j = 1; j <= e2; j++) {
                    if(i % j == 0) {
                        dinic.add_edge(i - s1 + 1 + e2, j, 1);
                    }
                }
            }
            int st = e2 * 2 + 1, ed = st + 1;
            for (int i = s1; i <= s + n; i++) {
                dinic.add_edge(st, i - s1 + 1 + e2, 1);
            }
            for (int i = 1; i <= e2; i++) {
                dinic.add_edge(i, ed, 1);
            }
            
            if(dinic.max_flow(st, ed) == e2) {
                puts("Yes");
            } else puts("No");
        }
    }
    return 0;
}

