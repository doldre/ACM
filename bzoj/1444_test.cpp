#include <algorithm>
#include <algorithm>
#include <iostream>
#include<string.h>
#include <fstream>
#include <math.h>
#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define exp 1e-8
#define fi first
#define se second
#define ll long long
#define INF 0x3f3f3f
#define lson l,mid,rt<<1
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define rson mid+1,r,(rt<<1)+1
#define all(a) a.begin(),a.end()
#define mm(a,b) memset(a,b,sizeof(a));
#define for1(a,b) for(int a=1;a<=b;a++)//1---(b)
#define rep(a,b,c) for(int a=b;a<=c;a++)//b---c
#define repp(a,b,c)for(int a=b;a>=c;a--)///
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
using namespace std;
void bug(string m="here"){cout<<m<<endl;}
template<typename __ll> inline void READ(__ll &m){__ll x=0,f=1;char ch=getchar();while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}m=x*f;}
template<typename __ll>inline void read(__ll &m){READ(m);}
template<typename __ll>inline void read(__ll &m,__ll &a){READ(m);READ(a);}
template<typename __ll>inline void read(__ll &m,__ll &a,__ll &b){READ(m);READ(a);READ(b);}
template<typename __ll>inline void read(__ll &m,__ll &a,__ll &b,__ll &c){READ(m);READ(a);READ(b);READ(c);}
template < class T > T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template < class T > T lcm(T a, T b) { return a / gcd(a, b) * b; }
template < class T > inline void rmin(T &a, const T &b) { if(a > b) a = b; }
template < class T > inline void rmax(T &a, const T &b) { if(a < b) a = b; }
template < class T > T pow(T a, T b) { T r = 1; while(b > 0) { if(b & 1) r = r * a; a = a * a; b /= 2; } return r; }
template < class T > T pow(T a, T b, T mod) { T r = 1; while(b > 0) { if(b & 1) r = r * a % mod; a = a * a % mod; b /= 2; } return r; }


const int maxn=100+10;  //字典树可能有的节点数量
int num_son=10;
char buf[20];
double pp[20];
double MAT[110][110];
int idx[20];
struct Trie{
    int next[maxn][10],fail[maxn];
    bool end[maxn];//分别是字典树、失败指针、是否为完整串标志
    int root,l;
    int newnode()
    {
        for(int i=0;i<num_son;i++)
            next[l][i]=-1;
        end[l++]=0;  //此处  当end[i]>0  意味这个从根到这个点是一个完整的串
        return l-1;
    }
    void init()
    {
        l=0;
        root=newnode();
    }
    void insert(char buf[],int kkk)
    {
        int len=strlen(buf);
        int now=root;
        for(int i=0;i<len;i++)
        {
            if(next[now][(buf[i]-'A')]==-1)
                next[now][(buf[i]-'A')]=newnode();
            now=next[now][(buf[i]-'A')];
        }
        end[now]=1;
        idx[kkk]=now;
    }
    void build()  //build了之后 之前的next[][]==-1的 统统转到失败节点的下一个~~~
    {
        queue<int>que;
        fail[root]=root;
        for(int i=0;i<num_son;i++)
            if(next[root][i]==-1)
                next[root][i]=root;
            else
            {
                fail[next[root][i]]=root;
                que.push(next[root][i]);
            }
        while(!que.empty())
        {
            int now=que.front();
            que.pop();
            for(int i=0;i<num_son;i++)
                if(next[now][i]==-1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    que.push(next[now][i]);
                }
        }
    }
    void matrix()
    {
        mm(MAT,0);
        for(int i=1;i<l;i++)MAT[i+1][i+1]=-1;//由于ac自动机的下标从0开始，与高斯的模板下标从1开始不一样~~~
        MAT[1][1]=MAT[1][l+1]=1;  //初始点特殊处理。
        for(int i=0;i<l;i++)
        {
            if(end[i])continue; //如果已经到了结束点，就不要转移了。
            for(int j=0;j<num_son;j++)
            {
                int to=next[i][j];
                // pr(i); prln(to);
                if(to!=0)MAT[to+1][i+1]+=pp[j+1];
                else MAT[to+1][i+1]-=pp[j+1];  //回到根节点需要减去。。
            }
        }
        // for (int i = 1; i <= l; i++) {
            // for (int j = 1; j <= l + 1; j++) {
                // printf("%.2f ", MAT[i][j]);
            // }
            // puts("");
        // }
    }
}ac;
void Gauss_Elimination(int n)//高斯消元模板
{
    int i,j,k,r;
    for(i=1;i<=n;++i)
    {
        r=i;
        for(j=i+1;j<=n;++j)
            if(fabs(MAT[j][i])>fabs(MAT[r][i]))r=j;
        if(r!=i)for(j=1;j<=n+1;++j)swap(MAT[r][j],MAT[i][j]);
        for(k=i+1;k<=n;++k)
        {
            double f=MAT[k][i]/MAT[i][i];
            for(j=i;j<=n+1;++j)MAT[k][j]-=f*MAT[i][j];
        }
    }
    for(i=n;i>=1;--i)
    {
        for(j=i+1;j<=n;++j)
            MAT[i][n+1]-=MAT[j][n+1]*MAT[i][j];
        MAT[i][n+1]/=MAT[i][i];
    }
}
int main()
{
#ifdef MATHON
    freopen("in.txt", "r", stdin);
#endif
    int n,l;
    read(n,l,num_son);
    int cnt=0;
    for1(i,num_son)
    {
        double p,q;
        scanf("%lf%lf",&p,&q);
        pp[i]=1.0*p/q;
        if(pp[i]<1e-8)cnt++;  
    }
    if(cnt==num_son) //概率很小都无法出现~~~
    {
        for1(i,n)puts("0.00");
        return 0;
    }
    ac.init();
    for1(i,n)
    {
        scanf("%s",buf);
        ac.insert(buf,i);
    }
    ac.build();
    ac.matrix();
    Gauss_Elimination(ac.l);
    for1(i,n)
    {
        double x=MAT[idx[i]+1][ac.l+1];
        if(x<1e-8)puts("0.00");  //防止出现-0
        else printf("%.2f\n",x);
    }
    return 0;
}
