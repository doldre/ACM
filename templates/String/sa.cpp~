#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <string>

using namespace std;

#define rst(a, b) memset(a, b, sizeof a)

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100005;

int wa[maxn], wb[maxn], wv[maxn], wws[maxn];
int cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(int *r, int *sa, int n, int m) {
    int i, j, p, *x = wa, *y = wb, *t;
    for(i=0;i<m;i++) wws[i] = 0;
    for(i=0;i<n;i++) wws[x[i]=r[i]]++;
    for(i=1;i<m;i++) wws[i]+=wws[i-1];
    for(i=n-1;i>=0;i--) sa[--wws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p) {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wws[i]=0;
        for(i=0;i<n;i++) wws[wv[i]]++;
        for(i=1;i<m;i++) wws[i]+=wws[i-1];
        for(i=n-1;i>=0;i--) sa[--wws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
        x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}
int rank[maxn], height[maxn];
void callheight(int *r, int *sa, int n) {
    int i,j,k=0;
    for(i=1;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
    for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    return;
}

int r[maxn], sa[maxn];

void solve() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        rst(r, 0);
        rst(sa, 0);
        rst(rank, 0);
        rst(height, 0);
        char str[maxn] = "";
        scanf("%s", str);
        int len = strlen(str);
        for(int i = 0; i < len; i++) {
            r[i] = str[i] - 'a' + 1;
        }
        da(r, sa, len+1, 27);
        callheight(r, sa, len);
        ll ans = 0;
        for(int i = 1; i <= len; i++) {
            ans += i - height[i];
        }
        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}
