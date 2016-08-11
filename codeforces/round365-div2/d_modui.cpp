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

using IO::begin;
using IO::read;
const int maxn = 1e6 + 5;
int BLOCK = 1e3;
vector<int> vec;
int A[maxn];
int id[maxn];
struct Query {
    int l, r, num;
    Query() {};
}q[maxn];
int res[maxn];

bool cmp(const Query &a, const Query &b) {
    if(a.l / BLOCK != b.l / BLOCK) {
        return (a.l / BLOCK) < (b.l / BLOCK);
    } else {
        return a.r < b.r;
    }
}
int n, m;
int cnt[maxn];

void solve() {
    int l = 0, r = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        if(r <= q[i].r) {
            for (; r <= q[i].r; r++) {
                if(cnt[id[r]] > 0) {
                    ans ^= vec[id[r]];
                }
                cnt[id[r]]++;
            }
        } else if(r > q[i].r + 1){
            for (; r > q[i].r + 1; r--) {
                cnt[id[r-1]]--;
                if(cnt[id[r-1]] > 0) {
                    ans ^= vec[id[r-1]];
                }
            }
        }

        if(l < q[i].l) {
            for (; l < q[i].l; l++) {
                cnt[id[l]]--;
                if(cnt[id[l]] > 0) {
                    ans ^= vec[id[l]];
                }
            }
        } else if(l > q[i].l) {
            for (; l > q[i].l; l--) {
                if(cnt[id[l-1]] > 0) {
                    ans ^= vec[id[l-1]];
                }
                cnt[id[l-1]]++;
            }
        }
        // pr(q[i].l); prln(q[i].r);
        // prln(ans);
        res[q[i].num] = ans;
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    begin();
    read(n);
    BLOCK = sqrt(n) + 1;
    for (int i = 0; i < n; i++) {
        read(A[i]);
        vec.push_back(A[i]);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        id[i] = lower_bound(vec.begin(), vec.end(), A[i]) - vec.begin();
    }
    read(m);
    for (int i = 0; i < m; i++) {
        read(q[i].l); read(q[i].r);
        q[i].l--; q[i].r--;
        q[i].num = i;
    }
    sort(q, q + m, cmp);
    solve();
    for (int i = 0; i < m; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}
