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
const double INF = 1e15;
const int MAXN = 10 + 5;
struct Edge {
    int to, c, d, nxt;
}edge[MAXN*MAXN];
int head[MAXN], tot;
int n, m, T;
double dis[MAXN];
int inque[MAXN];
void init() {
    memset(head, -1, sizeof(head));
    tot = 0;
}

void add_edge(int a, int b, int c, int d) {
    edge[tot].to = b;
    edge[tot].c = c;
    edge[tot].d = d;
    edge[tot].nxt = head[a];
    head[a] = tot++;
}
    
double f(double x){
    /**/
    for (int i = 1; i <= n; i++) dis[i] = INF;
    memset(inque, 0, sizeof(inque));
    queue<int> que;
    dis[1] = 0;
    inque[1] = true;
    que.push(1);
    while(!que.empty()) {
        int cur = que.front(); que.pop();
        inque[cur] = false;
        for (int i = head[cur]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            double cost = edge[i].c * x + edge[i].d;
            if(dis[cur] + cost < dis[v]) {
                dis[v] = dis[cur] + cost;
                if(!inque[v]) {
                    que.push(v);
                    inque[v] = true;
                }
            }
        }
    }
    // pr(dis[n]);
    return dis[n];
}
double simpson(double a, double b) {
    double c = a + (b - a) / 2;
    return (f(a) + 4 * f(c) + f(b)) * (b - a) / 6;
}
double asr(double a, double b, double eps, double A) {
    double c = a + (b - a) / 2;
    double L = simpson(a, c), R = simpson(c, b);
    if(fabs(L + R - A) <= 15 * eps) return L + R + (L + R - A) / 15.0;
    return asr(a, c, eps / 2, L) + asr(c, b, eps / 2, R);
}
double asr(double a, double b, double eps) {
    return asr(a, b, eps, simpson(a, b));
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d%d", &n, &m, &T) == 3) {
        init();
        for (int i = 1; i <= m; i++) {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            add_edge(a, b, c, d);
        }
        double ans = asr(0, T, 1e-6);
        ans /= T;
        printf("%.9f\n", ans);
    }
    return 0;
}

