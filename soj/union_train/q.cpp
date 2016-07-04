#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#define maxn 1000

using namespace std;

bool Map[maxn][maxn];
int c[maxn],r[maxn];
bool vis[maxn];

int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i = 0 ;i <m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			Map[u][v] =1; Map[v][u] = -1;
			c[u]++;c[v]++;
			r[u]++;r[v]--;
		}
		int flag = 1 ;
		memset(vis,0,sizeof(vis));
		queue<int> q;
		int cnt = 0;
		for (int i = 0 ; i<n;i++){
			if(!vis[i]){
				q.push(i);
				while (q.size()){
					int qq = q.front();
					q.pop();
					for (int j = 0 ;j< n;j++)
						if(!vis[j] && Map[i][j]){
							q.push(j);
							vis[j] = 1;
						}
				}
				cnt ++;
				if(cnt > 1){
					break;
					flag = 0;
				}
			}
		}
		if (!flag){
			printf("!No No\n");
			continue;
		}
		else {
			int p = 0;
			for (int i = 0 ; i< n;i++)
				if(c[i] != 0)
					p++;
			if(p==2 || p==0)
				printf("Yes ");
			else 
				printf("No ");
			p = 0;
			int p2,p3;
			for (int i = 0 ;i< n;i++){
				if(r[i] == 1)
					p++;
				else if(r[i] == -1)
					p2++;
				if (abs(r[i]) > 1){
						p3++;
						break;
				}
				if( p3 == 0 && (( p== 0 && p2 ==0) || (p == 1&& p2 == 1))) 
					printf("Yes\n");
				else 
					printf("No\n");

			}
		}
	}
	return 0;
}
