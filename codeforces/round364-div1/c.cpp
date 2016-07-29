#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define prln(x) cout << #x << " = " << x << endl
#define pr(x) cout << #x << " = " << x << " "
using namespace std;
const int INF = 0x7fffffff;
const int MAXN = 1000 + 5;
const int MAXM = 3e4 + 5;
struct Edge{
    int nxt, cost, id, to;
    bool used, cut;
}edge[MAXM << 1];

int head[MAXN], tot;
int visd[MAXN];

void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int cost, int id) {
    edge[tot].to = v;
    edge[tot].nxt = head[u];
    edge[tot].cost = cost;
    edge[tot].id = id;
    edge[tot].used = false;
    edge[tot].cut = false;
    head[u] = tot++;
}

bool get_path(int u, int &dest, vector<int> &path) {
    if(u == dest) return true;
    visd[u] = true;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if(visd[v] || edge[i].used) continue;
        if(get_path(v, dest, path)) {
            path.push_back(i);
            return true;
        }
    }
    return false;
}

int DFN[MAXN], Low[MAXN], dfsNum;

void Tarjan(int u, int pre) {
    DFN[u] = Low[u] = ++dfsNum;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        if(edge[i].used || (i ^ pre) == 1) continue;
        int v = edge[i].to;
        if(DFN[v] == -1) {
            Tarjan(v, i);
            Low[u] = min(Low[u], Low[v]);
            if(Low[v] > DFN[u]) {
                edge[i].cut = true;
                edge[i^1].cut = true;
            }
        } else {
            Low[u] = min(Low[u], DFN[v]);
        }
    }
}


int main() {
    int n, m, s, t;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &s, &t);
    init();
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        if(x == y) continue;
        add_edge(x, y, w, i);
        add_edge(y, x, w, i);
    }
    memset(visd, 0, sizeof(visd));
    vector<int> path;
    if(!get_path(s, t, path)) {
        printf("0\n0\n");
        return 0;
    }
    int res = INF; 
    vector<int> cut, tmp;
    vector<int> spath;
    for (int i = 0; i < (int)path.size(); i++) {
        tmp.clear();
        tmp.push_back(edge[path[i]].id);
        edge[path[i]].used = edge[path[i]^1].used = true;
        memset(DFN, -1, sizeof(DFN));
        memset(visd, 0, sizeof(visd));
        dfsNum = 0;
        Tarjan(s, -1);
        spath.clear();
        memset(visd, 0, sizeof(visd));
        if(!get_path(s, t, spath)) {
            if(res > edge[path[i]].cost) {
                res = edge[path[i]].cost;
                cut = tmp;
            }
        } else {
            int sed = -1;
            for (int j = 0; j < (int)spath.size(); j++) {
                if(edge[spath[j]].cut && 
                        (sed == -1 || edge[spath[j]].cost < edge[sed].cost)) {
                    sed = spath[j];
                }
            }
            if(sed >= 0) {
                tmp.push_back(edge[sed].id);
                if(res > edge[path[i]].cost + edge[sed].cost) {
                    res = edge[path[i]].cost + edge[sed].cost;
                    cut = tmp;
                }
            }
        }
        edge[path[i]].used = edge[path[i]^1].used = false;
        for (int j = 0; j < tot; j++) edge[j].cut = false;
    }
    if(res == INF) {
        printf("-1\n");
    } else {
        printf("%d\n%d\n", res, (int)cut.size());
        for (auto i: cut) {
            printf("%d ", i);
        }
    }
    return 0;
}

