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

const int len = 18;
const int MAXT = 1e5 + 5;
struct Node {
    int ch[2], v;
}nds[MAXT*100];
int tot;
int new_node() {
    nds[tot].ch[0] = nds[tot].ch[1] = -1;
    nds[tot].v = 0;
    return tot++;
}
int root;
void insert(ll x) {
    int p = root;
    for (int i = 0; i < len; i++) {
        int t = x % 10;
        x /= 10;
        t = t & 1;
        if(nds[p].ch[t] == -1) {
            nds[p].ch[t] = new_node();
        }
        p = nds[p].ch[t];
    }
    nds[p].v++;
}

void del(ll x) {
    int p = root;
    for (int i = 0; i < len; i++) {
        int t = x % 10;
        x /= 10;
        t = t & 1;
        p = nds[p].ch[t];
    }
    nds[p].v--;
}
char str[20];
char buf[100];
int query() {
    int p = root;
    for (int i = 17; i >= 0; i--) {
        int t = str[i];
        if(nds[p].ch[t] == -1) {
            return 0;
        } else p = nds[p].ch[t];
    }
    return nds[p].v;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    tot = 0;
    root = new_node();
    while(T--) {
        char op[20];
        scanf("%s", op);
        if(op[0] == '+') {
            ll x; scanf("%lld", &x);
            insert(x);
        } else if(op[0] == '-') {
            ll x; scanf("%lld", &x);
            del(x);
        } else {
            scanf("%s", buf);
            int slen = strlen(buf);
            memset(str, 0, sizeof(str));
            int p = 18 - slen;
            for (int i = 0; i < slen; i++) {
                str[i+p] = buf[i] - '0';
            }
            int x = query();
            printf("%d\n", x);
        }
    }
    return 0;
}

