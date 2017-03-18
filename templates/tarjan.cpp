int dfsNum, DFN[MAXN], low[MAXN];
int fa[MAXN], min_cost[MAXN], gid;
int indeg[MAXN];
bool insta[MAXN];
stack<int> sta;
void tarjan(int u) {
    DFN[u] = low[u] = ++dfsNum;
    sta.push(u);
    insta[u] = true;
    for (auto v: G[u]) {
        if(DFN[v] != -1) {
            if(insta[v]) low[u] = min(low[u], DFN[v]);
        } else {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == DFN[u]) {
        int mc = INF;
        ++gid;
        while(true) {
            int v = sta.top(); sta.pop();
            insta[v] = false;
            fa[v] = gid;
            mc = min((ll)mc, bombs[v].c);
            if(u == v) break;
        }
        min_cost[gid] = mc;
    }
}

