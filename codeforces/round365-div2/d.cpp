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
    const int MT = 1e8; //1e7占用内存11000kb
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
using IO::read;
using IO::begin;
const int MAXN = 1e6 + 5;
const int MAXM = 1e6 + 5;
struct BIT {
    int bit[MAXN], n;
    void init(int n) {
        this->n = n;
        memset(bit, 0, sizeof(bit));
    }
    
    void update(int i, int x) {
        for(; i > 0; i -= lowbit(i)) {
            bit[i] ^= x;
        }
    }

    int query(int i) {
        int res = 0;
        for (; i <= n; i += lowbit(i)) {
            res ^= bit[i];
        }
        return res;
    }
}bit;

struct Query {
    int l, r, num;
    bool operator < (const Query &b) const {
        return r < b.r;
    }
}q[MAXM];
int n, m;
int A[MAXN], B[MAXN];
int ans[MAXM];
map<int, int> mp;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    begin();
    read(n);
    for (int i = 1; i <= n; i++) {
        read(A[i]);
        B[i] = B[i-1] ^ A[i];
    }
    read(m);
    for (int i = 0; i < m; i++) {
        read(q[i].l); read(q[i].r);
        q[i].num = i;
    }
    sort(q, q + m);
    bit.init(n + 1);
    int j = 1;
    for (int i = 0; i < m; i++) {
        while(j <= q[i].r) {
            if(mp[A[j]]) {
                bit.update(mp[A[j]], A[j]);
            }
            bit.update(j, A[j]);
            mp[A[j]] = j;
            j++;
        }
        ans[q[i].num] = bit.query(q[i].l) ^
            B[q[i].r] ^ B[q[i].l-1];
    }
    for (int i = 0; i < m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}

