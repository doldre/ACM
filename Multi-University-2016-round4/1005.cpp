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

ll Extended_Euclid(ll a,ll b,ll &x,ll &y)    //扩展欧几里得算法  
{  
    ll d;  
    if(b==0)  
    {  
        x=1;y=0;  
        return a;  
    }  
    d= Extended_Euclid(b,a%b,y,x);  
    y-=a/b*x;  
    return d;  
}  

ll mod_multipy(ll a, ll b, ll mod) {
    ll res = 0;
    while(b > 0) {
        if(b & 1) {
            res = (res + a) % mod;
        }
        b >>= 1;
        a = (a + a) % mod;
    }
    return res;
}

ll Chinese_Remainder(ll a[],ll w[],ll len)    //中国剩余定理  a[]存放余数  w[]存放两两互质的数  
{  
    ll i,d,x,y,m,n,ret;  
    ret=0;  
    n=1;  
    for (i=0;i<len;i++)  
        n*=w[i];  
    for (i=0;i<len;i++)  
    {  
        m = n/w[i];  
        d=Extended_Euclid(w[i],m,x,y);  
        ret=(ret+(__int128)y*m*a[i])%n;  
        // ret = (ret + mod_multipy(mod_multipy(y, m, n), a[i], n)) % n;
    }  
    return (n+ret%n)%n;  
}  

ll cal(ll x, ll y, ll m, ll a) {
    ll ans1 = (x - 1) / m + ((x - 1) % m >= a);
    ll ans2 = y / m + (y % m >= a);
    return ans2 - ans1;
}

const int maxn = 25;
int n;
ll x, y;
int p[maxn], a[maxn];
ll A[maxn], M[maxn];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%lld%lld", &n, &x, &y);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p[i], &a[i]);
        }
        __int128 ans = 0;
        M[0] = 7, A[0] = 0;
        int cnt_n = 1;
        for (int mask = 0; mask < (1<<n); mask++) {
            int cnt_one = __builtin_popcount(mask);
            cnt_n = 1;
            ll tot = 7;
            for (int i = 0; i < n; i++) {
                if((mask>>i) & 1) {
                    M[cnt_n] = p[i];
                    A[cnt_n++] = a[i];
                    tot *= p[i];
                }
            }
            ll rem = Chinese_Remainder(A, M, cnt_n);
            if(cnt_one & 1) {
                ans -= cal(x, y, tot, rem);
            } else {
                ans += cal(x, y, tot, rem);
            }
            // pr(mask);
            // prln(ans);
        }
        printf("Case #%d: %lld\n", Cas, (ll)ans);
    }
    return 0;
}

