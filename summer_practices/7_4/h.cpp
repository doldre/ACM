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
const int maxn = 250;
const int maxm = 25005;
const int inf= 0x3f3f3f3f;
char s[200];
int a[maxn],mat[maxn][maxn];
struct Edge{
	int to,next,cap,flow,cost;
}edge[maxm];
int head[maxn],tot;
int pre[maxn],dis[maxn];
bool vis[maxn];int N;
void init(int n){
	N=n;
	tot=0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int cap,int cost){
	edge[tot].to=v;
	edge[tot].cap=cap;
	edge[tot].cost=cost;
	edge[tot].flow=0;
	edge[tot].next=head[u];
	head[u]=tot++;
	edge[tot].to=u;
	edge[tot].cap=0;
	edge[tot].cost=-cost;
	edge[tot].flow=0;
	edge[tot].next=head[v];
	head[v]=tot++; 
} 
bool spfa(int s,int t){
	queue<int> q;
	for(int i=0;i<N;i++){
		dis[i]=inf;
		vis[i]=false;
		pre[i]=-1;
	} dis[s]=0;
	vis[s]=true;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=head[u];i!=-1;i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].cap>edge[i].flow&&dis[v]>dis[u]+edge[i].cost){
				dis[v]=dis[u]+edge[i].cost;
				pre[v]=i;
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}if(pre[t]==-1) return false;
	else return true;
}
int mincostmaxflow(int s,int t,int &cost){
	int flow=0;
	cost=0;
	while(spfa(s,t)){
		int Min=inf;
		for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
			if(Min>edge[i].cap-edge[i].flow) Min=edge[i].cap-edge[i].flow;
		}for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
			edge[i].flow+=Min;
			edge[i^1].flow-=Min;
			cost+=edge[i].cost*Min;
		}flow+=Min;
	}return flow;
}

char str[maxn];

int A[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    while(scanf("%d", &n) == 1 && n) {
        int s = 0, t = 2 * n + 1;
        init(2*n + 2);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        
        for (int i = 1; i <= n; i++) {
            addedge(s, i, 1, 0);
            addedge(i, t, 1, 0);
            addedge(i + n, t, 1, 0);
        }
        
        for (int i = 1; i <= n; i++) {
            scanf("%s", str + 1);
            for (int j = 1; j <= n; j++) {
                if(str[j] == '1') {
                    addedge(i, j + n, 1, -(A[i]^A[j]));
                }
            }
        }
        int cost;
        mincostmaxflow(s, t, cost);
        printf("%d\n", -cost);
    }
    return 0;
}
