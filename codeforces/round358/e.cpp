#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef pair<long long,long long> node;
long long cross(node a,node b,node c)
{
    return abs((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x));
}
vector<node>P;
int n;
long long s;
int main()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        node p;
        scanf("%lld%lld",&p.x,&p.y);
        P.push_back(p);
    }
    sort(P.begin(),P.end());
    P.erase(unique(P.begin(),P.end()),P.end());
    node a,b,c;
    a=P[0],b=P[1],c=P[2];
    long long ans = cross(a,b,c);
    int flag = 1;
    while(flag)
    {
        flag = 0;
        /* random_shuffle(P.begin(),P.end()); */
        for(int i=0;i<P.size();i++)
        {
            long long tmp = cross(P[i],b,c);
            if(tmp>ans)
            {
                ans=tmp;
                a=P[i];
                flag=1;
            }
        }
        for(int i=0;i<P.size();i++)
        {
            long long tmp = cross(a,P[i],c);
            if(tmp>ans)
            {
                ans=tmp;
                b=P[i];
                flag=1;
            }
        }
        for(int i=0;i<P.size();i++)
        {
            long long tmp = cross(a,b,P[i]);
            if(tmp>ans)
            {
                ans=tmp;
                c=P[i];
                flag=1;
            }
        }
    }
    cout<<a.x+b.x-c.x<<" "<<a.y+b.y-c.y<<endl;
    cout<<a.x+c.x-b.x<<" "<<a.y+c.y-b.y<<endl;
    cout<<b.x+c.x-a.x<<" "<<b.y+c.y-a.y<<endl;
}
