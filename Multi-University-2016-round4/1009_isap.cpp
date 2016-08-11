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

const int MAXN = 100010; //点数的最大值
const int MAXM = 400010; //边数的最大值
const int INF = 0x3f3f3f3f;
struct Edge {
    int to, next, cap, flow;
}edge[MAXM];
int tol;
int head[MAXN];
int gap[MAXN], dep[MAXN], cur[MAXN];

void init() {
    tol = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w, int rw = 0) {
    edge[tol].to = v; edge[tol].cap = w; edge[tol].flow = 0;
    edge[tol].next = head[u]; head[u] = tol++;
    edge[tol].to = u; edge[tol].cap = rw; edge[tol].flow = 0;
    edge[tol].next = head[v]; head[v] = tol++;
}

int Q[MAXN];
void BFS(int start, int end) {
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    gap[0] = 1;
    int front = 0, rear = 0;
    dep[end] = 0;
    Q[rear++] = end;
    while(front != rear) {
        int u = Q[front++];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if(dep[v] != -1) continue;
            Q[rear++] = v;
            dep[v] = dep[u] + 1;
            gap[dep[v]]++;
        }
    }
}
int S[MAXN];
//起点,终点，点的数目
int sap(int start, int end, int N) {
    BFS(start, end);
    memcpy(cur, head, sizeof(head));
    int top = 0;
    int u = start;
    int ans = 0;
    while(dep[start] < N) {
        if(u == end) {
            int Min = INF;
            int inser;
            for (int i = 0; i < top; i++) {
                if(Min > edge[S[i]].cap - edge[S[i]].flow) {
                    Min = edge[S[i]].cap - edge[S[i]].flow;
                    inser = i;
                }
            }
            for (int i = 0; i < top; i++) {
                edge[S[i]].flow += Min;
                edge[S[i] ^ 1].flow -= Min;
            }
            ans += Min;
            top = inser;
            u = edge[S[top]^1].to;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = cur[u]; i != -1; i = edge[i].next) {
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u]) {
                flag = true;
                cur[u] = i;
                break;
            }
        }
        if(flag) {
            S[top++] = cur[u];
            u = v;
            continue;
        }
        int Min = N;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min) {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        }
        gap[dep[u]]--;
        if(!gap[dep[u]]) return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if(u != start) u = edge[S[--top] ^ 1].to;
    }
    return ans;
}
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
        init();
        int s = n * n + n + 15, t = s + 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                add_edge(i * n + j, n * n + i, INF, 0);
                add_edge(i * n + j, n * n + j, INF, 0);
                add_edge(s, i * n + j, w[i][j] + w[j][i], 0);
            }
        }
        for (int i = 0; i < n; i++) {
            add_edge(n * n + i, t, A[str[i] - '0'], 0);
            add_edge(n * n + i, n * n + n + str[i] - '0', INF, 0);
        }
        for (int i = 0; i < 10; i++) {
            add_edge(n * n + n + i, t, B[i] - A[i], 0);
        }
        int min_cut = sap(s, t, n * (n - 1) / 2 + n + 10 + 2);
        // prln(min_cut);
        printf("Case #%d: %d\n", Cas, tot - min_cut);
    }
    return 0;
}

