#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
class edge{
public:
    int v,nex;
};edge e[100005];
int n,m,k,head[100005];
int map[1501][1501],link[1501];
bool vis[1501];
void addedge(int b,int a){//向图中加边的算法，注意加上的是有向边//b为a的后续节点既是a---->b
    e[k].v=a;
    e[k].nex=head[b];
    head[b]=k;k++;
}
bool dfs(int u){
    for(int i = head[u]; i != 0; i = e[i].nex){
        int v = e[i].v;
        if(!vis[v]){
            vis[v] = true;
            if(link[v] == -1 || dfs(link[v])){
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int ans=0;
    for(int i = 0; i < n; i ++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
