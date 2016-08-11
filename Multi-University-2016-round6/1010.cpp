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
typedef int INT;
#define int long long
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

int dfs(int S, int T, int step, int stop) {
    if(S <= T) return step + T - S;
    int x = 0;
    while(S - (1 << x) + 1 > T) x++;
    int up = T - max(0ll, S - (1 << x) + 1);
    int tmp = x + max(0ll, up - stop);
    if(x == 1) return step + tmp;
    return min(step + tmp, dfs(S - (1 << (x - 1)) + 1, T, step + x, stop + 1));
}

char str[1000000];
INT main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    IO::begin();
    int T; IO::read(T);
    while(T--) {
        int p, q;
        IO::read(p); IO::read(q);
    }
    return 0;
}

