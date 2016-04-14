#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;
const int N = 40005;

bool vis[N];
int link[N],head[N];
int cnt,n;

struct Edge
{
    int to;
    int next;
};

Edge edge[N*20];

void Init()
{
    cnt = 0;
    memset(head,-1,sizeof(head));
}

void add(int u,int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

bool dfs(int u)
{
    for(int i=head[u];~i;i=edge[i].next)
    {
        int v = edge[i].to;
        if(!vis[v])
        {
            vis[v] = 1;
            if(link[v] == -1 || dfs(link[v]))
            {
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}

int match()
{
    int ans = 0;
    memset(link,-1,sizeof(link));
    for(int i=0;i<n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;
    }
    return ans;
}
const int maxv = 500000 + 5;
bool isprime[maxv];
vector<int> prime;
int flag[maxv];
int A[N];
int main()
{
    memset(isprime, true, sizeof(isprime));
    for (int i = 2; i < maxv; i++) {
        if(isprime[i]) {
            prime.push_back(i);
            for (int j = i + i; j < maxv; j += i) {
                isprime[j] = false;
            }
        }
    }
    int T;
    scanf("%d", &T);
    while(T--)
    {
        Init();
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            flag[x] = i;
            A[i] = x;
        }
        for (int i = 1; i <= n; i++) {
            int x = A[i];
            for (int j = 0; j < (int)prime.size() && prime[j] * i < maxv; j++) {
                if(flag[x * prime[j]]) {
                    add(i, flag[x * prime[j]]);
                    add(flag[x * prime[j]], i);
                }
            }
        }
        /* for (int i = 1; i < maxv; i++) { */
        /*     if(flag[i]) { */
        /*         for (int j = 0; j < (int)prime.size() && prime[j] * i < maxv; j++) { */
        /*             if(flag[j]) { */
        /*                 cout << "debug" << j << endl; */
        /*                 add(i, j); */
        /*                 add(j, i); */
        /*             } */
        /*         } */
        /*     } */
        /* } */
        printf("%d\n",n - (match()>>1));
    }
    return 0;
}
