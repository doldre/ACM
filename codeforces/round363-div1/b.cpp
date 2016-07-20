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
        a = find(a); b = find(b);
        par[a] = b;
    }
}dsu;

int A[maxn];
int n;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    dsu.init(n);
    vector<int> buf;
    int root = -1;
    for (int i = 1; i <= n; i++) {
        int u = i, v =  A[i];
        if(root == -1 && u == v) {
            root = u;
            continue;
        }
        if(dsu.find(u) == dsu.find(v)) {
            buf.push_back(u);
        }
        dsu.merge(u, v);
    }
    int cnt = 0; 
    for (int i = 0; i < (int)buf.size() - 1; i++) {
        int u = buf[i], v = buf[i+1];
        A[u] = v;
        cnt++;
    }
    if(buf.size() > 0) {
        int last = buf[buf.size() - 1]; 
        if(root != -1) {
            A[last] = root;
            cnt++;
        } else {
            A[last] = last;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) {
        printf("%d%c", A[i], i == n ? '\n' : ' ');
    }
    return 0;
}

