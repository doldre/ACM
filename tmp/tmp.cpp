#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
#define   MAX           100005
#define   MAXN          1000005
#define   maxnode       105
#define   sigma_size    30
#define   lson          l,m,rt<<1
#define   rson          m+1,r,rt<<1|1
#define   lrt           rt<<1
#define   rrt           rt<<1|1
#define   middle        int m=(r+l)>>1
#define   LL            long long
#define   ull           unsigned long long
#define   mem(x,v)      memset(x,v,sizeof(x))
#define   lowbit(x)     (x&-x)
#define   pii           pair<int,int>
#define   bits(a)       __builtin_popcount(a)
#define   mk            make_pair
#define   limit         10000

//const int    prime = 999983;
const int    INF   = 0x3f3f3f3f;
const LL     INFF  = 0x3f3f;
const double pi    = acos(-1.0);
const double inf   = 1e18;
const double eps   = 1e-8;
const LL     mod   = 1e9+7;
const ull    mx    = 133333331;

/*****************************************************/
inline void RI(int &x) {
      char c;
      while((c=getchar())<'0' || c>'9');
      x=c-'0';
      while((c=getchar())>='0' && c<='9') x=(x<<3)+(x<<1)+c-'0';
 }
/*****************************************************/

int sum[MAX];
LL dp[MAX];
map<int ,int> ma;
int main(){
    int n;
    cin>>n;
    sum[0]=0;
    ma.clear();
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        sum[i]=sum[i-1]+a;
    }
    dp[0]=1;
    ma[0]=1;
    LL all=1;
    for(int i=1;i<=n;i++){
        if(!ma.count(sum[i])){
            dp[i]=all;
            ma[sum[i]]=dp[i];
        }
        else{
            dp[i]=((all-ma[sum[i]])%mod+mod)%mod;
            ma[sum[i]]=(ma[sum[i]]+dp[i])%mod;
        }
        all=(all+dp[i])%mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}
