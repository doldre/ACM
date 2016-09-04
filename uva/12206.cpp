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

const int MAXN = 4e5 + 5;
const int seed = 1331;
char str[MAXN];
int m, n;

ull _hash[MAXN];
int ind[MAXN];

bool cmp(int a, int b) {
    return _hash[a] < _hash[b] || (_hash[a] == _hash[b] && a < b);
}
int check(int x) {
    // prln(x);
    ull L = 1;
    for (int i = 0; i < x - 1; i++) L *= seed;
    ull cur = 0;
    for (int i = 0; i < x; i++) {
        cur = cur * seed + str[i];
    }
    _hash[0] = cur;
    // prln(cur);
    for (int i = 1; i + x - 1 < n; i++) {
        cur -= str[i-1] * L;
        cur = cur * seed + str[i + x - 1];
        _hash[i] = cur;
        // prln(cur);
    }
    for (int i = 0; i < n - x + 1; i++) ind[i] = i;
    // for (int i = 0; i < n - x + 1; i++) prln(_hash[i]);
    sort(ind, ind + n - x + 1, cmp);
    int m_last = -1;
    int c = 0;
    for (int i = 0; i < n - x + 1; i++) {
        if(i == 0 || _hash[ind[i]] != _hash[ind[i-1]]) c = 0;
        if(++c >= m) m_last = max(m_last, ind[i]);
    }
    return m_last;
}

void solve() {
    int l = 0, r = n + 1;
    int ans = -1;
    while(l < r - 1) {
        int m = (l + r) >> 1;
        int t = check(m);
        if(t != -1) {
            l = m;
            ans = t;
        } else {
            r = m;
        }
    }
    if(ans != -1) {
        printf("%d %d\n", l, ans);
    } else printf("none\n");
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &m) == 1 && m) {
        scanf("%s", str);
        n = strlen(str);
        solve();
    }
    return 0;
}

