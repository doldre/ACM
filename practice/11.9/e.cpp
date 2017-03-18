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

const int MAXN = 2e4 + 5;
vector<int> G[MAXN];
map<string, int> name2id;
map<int, string> id2name;
int u, v, m;
int used[MAXN];
vector<int> ans;

void dfs(int u) {
    if(used[u]) return;
    used[u] = true;
    ans.push_back(u);
    for (auto v: G[u]) {
        dfs(v);
    }
}

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        for (int i = 0; i < MAXN; i++) G[i].clear();
        scanf("%d%d%d", &u, &v, &m);
        name2id.clear(); id2name.clear();
        set<string> U, V;
        int cid = 0;
        for (int i = 0; i < u; i++) {
            string str; cin >> str;
            U.insert(str);
            if(name2id[str] == 0) {
                name2id[str] = ++cid;
                id2name[cid] = str;
            }
        }
        for (int i = 0; i < v; i++) {
            string str; cin >> str;
            V.insert(str);
            if(name2id[str] == 0) {
                name2id[str] = ++cid;
                id2name[cid] = str;
            }
        }
        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            int ida = (name2id.find(a) != name2id.end() ? name2id[a] : name2id[a] = ++cid);
            int idb = (name2id.find(b) != name2id.end() ? name2id[b] : name2id[b] = ++cid);
            G[ida].push_back(idb);
        }
        memset(used, 0, sizeof(used));
        ans.clear();
        for (auto u: U) {
            dfs(name2id[u]);
        }
        set<string> res;
        for (auto x: ans) {
            string name = id2name[x];
            if(V.find(name) != V.end()) {
                res.insert(name);
            }
        }
        for (auto x: res) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}

