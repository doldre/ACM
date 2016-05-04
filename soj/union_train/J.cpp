/************************************************
 *Author        :mathon
 *Created Time  :2016年05月04日 星期三 11时24分12秒
 ***********************************************/
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
vector<int> vi;
#define xx first
#define yy second
#define lowbit(x) (x&-x)
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

char str[maxn];
int p[maxn * 2];
char buf[maxn * 2];
int P[maxn];
int pre[maxn];

int len, m; 

ll mod_pow(ll x, ll n) {
    ll res = 1;
    while(n > 

void manacher() {
    memset(p, 0, sizeof(p)); 
    int mx = 0, id = 0;
    for (int i = 1; i < m; i++) {
        p[i] = mx > i ? min(mx - i, p[2 * id - i]) : 1;
        while(buf[i + p[i]] == buf[i - p[i]]) p[i]++;
        if(i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
}


struct Trie {
    struct Node {
        int nxt[2], v;
    }nds[maxn * 20];
    
    int cnt;
    int newnode() {
        cnt++;
        memset(nds[cnt], -1, sizeof(nds[cnt]));
        return cnt;
    }

    void init() {
        cnt = -1;
        newnode();
    }

    void insert(int x) {
        int p = 0;
};

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    while(T--) {
        scanf("%s", str);
        len = strlen(str);
        m = 0;
        buf[m++] = '$';
        buf[m++] = '#';
        for (int i = 0; i < len; i++) {
            buf[m++] = str[i];
            buf[m++] = '#';
        }
        buf[m] = '\0';
        manacher();
        int MZ = 0;
        for (int i = 0; i < len; i++) {
            P[i] = p[(i+1)*2];
            MZ = max(MZ, P[i]);
        }
        for (int i = 1; i <= len; i++) {
            pre[i] = pre[i-1] ^ P[i];
        }
    
        int
    }
    return 0;
}
