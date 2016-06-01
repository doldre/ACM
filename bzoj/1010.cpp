/**************************************************************
    Problem: 1010
    User: mathon
    Language: C++
    Result: Accepted
    Time:160 ms
    Memory:3032 kb
****************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<queue>
#include<cmath>
#include<algorithm>
#define inf 1000000000
#define ll long long
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
ll L,c[50005],f[50005],sum[50005];
struct data{
    int l,r,p;
}q[50005];
ll sqr(ll x)
{
    return x*x;
}
ll cal(int j,int i)
{
    return f[j]+sqr(sum[i]-sum[j]+i-j-1-L);
}
int find(data t,int q)
{
    int l=t.l,r=t.r,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(cal(q,mid)<cal(t.p,mid))r=mid-1;
        else l=mid+1;
    }
    return l;
}
void dp()
{
    int head=1,tail=0;
    q[++tail]=(data){0,n,0};
    for(int i=1;i<=n;i++)
    {
        if(i>q[head].r)head++;
        f[i]=cal(q[head].p,i);
        if(head>tail||cal(i,n)<cal(q[tail].p,n))
        {
            while(head<=tail&&cal(i,q[tail].l)<cal(q[tail].p,q[tail].l))
                tail--;
            if(head<=tail)
            {
                int t=find(q[tail],i);
                q[tail].r=t-1;
                q[++tail]=(data){t,n,i};
            }
            else q[++tail]=(data){i,n,i};
        }
    }
}
int main()
{
    scanf("%d%lld", &n, &L);
    for(int i=1;i<=n;i++)scanf("%lld", &c[i]);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+c[i];
    dp();
    printf("%lld\n",f[n]);
    return 0;
}
