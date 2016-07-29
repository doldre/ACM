typedef long long ll;

ll Extended_Euclid(ll a,ll b,ll &x,ll &y)    //扩展欧几里得算法  
{  
    ll d;  
    if(b==0)  
    {  
        x=1;y=0;  
        return a;  
    }  
    d= Extended_Euclid(b,a%b,y,x);  
    y-=a/b*x;  
    return d;  
}  

ll mod_multipy(ll a, ll b, ll mod) {
    ll res = 0;
    while(b > 0) {
        if(b & 1) {
            res = (res + a) % mod;
        }
        b >>= 1;
        a = (a + a) % mod;
    }
    return res;
}

ll Chinese_Remainder(ll a[],ll w[],ll len)    //中国剩余定理  a[]存放余数  w[]存放两两互质的数  
{  
    ll i,d,x,y,m,n,ret;  
    ret=0;  
    n=1;  
    for (i=0;i<len;i++)  
        n*=w[i];  
    for (i=0;i<len;i++)  
    {  
        m = n/w[i];  
        d=Extended_Euclid(w[i],m,x,y);  
        ret=(ret+(__int128)y*m*a[i])%n;  
        // ret = (ret + mod_multipy(mod_multipy(y, m, n), a[i], n)) % n;
    }  
    return (n+ret%n)%n;  
}  
