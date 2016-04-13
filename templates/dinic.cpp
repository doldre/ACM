#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 5005
#define M 10005
#define inf 999999999
using namespace std;

int n,m,s,t,num,adj[N],dis[N],q[N];
struct edge
{
	int v,w,pre;
}e[M];
void insert(int u,int v,int w)
{
	e[num]=(edge){v,w,adj[u]};
	adj[u]=num++;
	e[num]=(edge){u,0,adj[v]};
	adj[v]=num++;
}
int bfs()
{
	int i,x,v,tail=0,head=0;
	memset(dis,0,sizeof(dis));
	dis[s]=1;
	q[tail++]=s;
	while(head<tail)
	{
		x=q[head++];
		for(i=adj[x];i!=-1;i=e[i].pre)
			if(e[i].w&&dis[v=e[i].v]==0)
			{
				dis[v]=dis[x]+1;
				if(v==t)
					return 1;
				q[tail++]=v;
			}
	}
	return 0;
}
int dfs(int s,int limit)
{
	if(s==t)
		return limit;
	int i,v,tmp,cost=0;
	for(i=adj[s];i!=-1;i=e[i].pre)
		if(e[i].w&&dis[s]==dis[v=e[i].v]-1)
		{
			tmp=dfs(v,min(limit-cost,e[i].w));
			if(tmp>0)
			{
				e[i].w-=tmp;
				e[i^1].w+=tmp;
				cost+=tmp;
				if(limit==cost)
					break;
			}
			else dis[v]=-1;
		}
	return cost;
}
int Dinic()
{
	int ans=0;
	while(bfs())
		ans+=dfs(s,INT_MAX);
	return ans;
}
int main ()
{
	while(~scanf("%d%d",&m,&n))
	{
		int u,v,w;
		memset(adj,-1,sizeof(adj));
		num=0;
		s=1;
		t=n;
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			insert(u,v,w);
		}
		printf("%d\n",Dinic());
	}
}
