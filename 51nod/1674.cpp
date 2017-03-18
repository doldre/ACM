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

namespace IO {
    const int MT = 1e7; //1e7占用内存11000kb
    char buf[MT]; int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MT, stdin);
    }
    inline bool read(int &t) {
        while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

int last[32][MAXN][2];
int n, A[MAXN];

ll pow2[32];

void init() {
    pow2[0] = 1;
    for (int i = 1; i < 32; i++) {
        pow2[i] = pow2[i-1] * 2 % MOD;
    }
}

struct Node {
    int flag, pos, mask;
    Node(){}
    Node(int flag, int pos, int mask):flag(flag), pos(pos), mask(mask) {}
}nds[MAXN];
int cnt;

bool cmp(const Node &a, const Node &b) {
    return a.pos < b.pos;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    IO::begin();
    // scanf("%d", &n);
    IO::read(n);
    for (int i = 1; i <= n; i++) {
        IO::read(A[i]);
    }
    
    for (int i = 0; i < 32; i++) {
        int t[2];
        t[0] = n + 1, t[1] = n + 1;
        for (int j = n; j >= 1; j--) {
            t[(A[j] >> i) & 1] = j;
            last[i][j][0] = t[0];
            last[i][j][1] = t[1];
        }
    }


    ll ans = 0;
    for (int j = 1; j <= n; j++) {
        cnt = 0;
        for (int i = 0; i < 32; i++) {
            nds[cnt++] = Node(0, last[i][j][0], 1<<i);
            nds[cnt++] = Node(1, last[i][j][1], 1<<i);
        }
        sort(nds, nds + cnt, cmp);
        int t_last = j, mask = 0;
        ll sum = 0;
        for (int i = 0; i < cnt; i++) {
            sum = (sum + (ll)mask * (nds[i].pos - t_last)) % MOD;
            if(nds[i].flag == 0) {
                t_last = nds[i].pos;
                ans = (ans + sum * nds[i].mask) % MOD;
            } else {
                mask = mask ^ nds[i].mask;
                t_last = nds[i].pos;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

