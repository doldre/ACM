#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=51000*2;
char s[N];
int n,rk[N],sa[N],ht[N],r[N],pro[N];
pair<PII,int> pos[N];
VI vec[N];

void buildSA(char *p) {
	rep(i,0,n) rk[i]=p[i];
	rep(j,0,19) {
		rep(i,0,n) pos[i]=mp(mp(rk[i],rk[i+(1<<j)]),i);
		sort(pos,pos+n);
		int cnt=0;
		rep(i,0,n) {
			rk[pos[i].se]=cnt+1;
			cnt+=(pos[i].fi!=pos[i+1].fi);
		}
		if (cnt==n) break;
	}
	rep(i,0,n) sa[rk[i]]=i;
}
void height() {
	int k=0;
	rep(i,0,n) {
		if (rk[i]==1) continue;
		k=max(0,k-1);
		for (int j=sa[rk[i]-1];s[i+k]==s[j+k];k++);
		ht[rk[i]]=k;
	}
}
int main() {
    int T;
	scanf("%d",&T);
    rep(i, 0, T) {
        memset(sa, 0, sizeof(sa));
        memset(ht, 0, sizeof(ht));
        memset(rk, 0, sizeof(rk));
        scanf("%s", s);
        n = strlen(s);
        buildSA(s);
        height();
        ll ans = 0;
        rep(i, 1, n + 1) {
//            printf("%d %d\n", sa[i], ht[i]);
            ans += n - sa[i] - ht[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
