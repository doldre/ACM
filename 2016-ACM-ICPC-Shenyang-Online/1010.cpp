#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cassert>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
typedef long long ll;
typedef long double ld;

int get_root2(ll a){
	ll b = sqrt(a);
	while((b + 1LL)*(b + 1LL)<=a) {
        ++b;
    }
	return b;
}

int get_root3(ll a){
	ll b = cbrt(a);
	while((b+1LL)*(b+1LL)*(b+1LL)<=a) ++b;
	return b;
}

vector<int> primes;
vector<int> d;

void getPrimes(int n){
	d.assign(n+1, 0);
	primes.clear();
	for(int i=2;i<=n;++i){
		if(!d[i]) primes.push_back(d[i]=i);
		for(int p : primes){
			if(p>d[i] || 1LL*p*i>n) break;
			d[p*i] = p;
		}
	}
}

ll cnt = 0;

ll f(ll,int);
ll pi(ll);

vector<vector<int>> dp;

ll f(ll n, int m){
	if(m==0) return n;
	if(m<(int)dp.size() && n<(int)dp[m].size()) return dp[m][(int)n];
	if(n<1LL*primes[m]*primes[m]) return pi(n)-m+1;
	return f(n, m-1) - f(n/primes[m-1], m-1);
}

ll pi(ll n){
	if(n<=primes.back()) return upper_bound(ALL(primes), (int)n) - primes.begin();
	int y = get_root3(n-1)+1, d = pi(y);
	ll res = f(n,d) + d - 1;
	for(int i = d; ; ++i){
		ll p = primes[i];
		if(p*p>n) break;
		res-=pi(n/p) - pi(p) + 1;
	}
	return res;
}

void init(ll n){
	getPrimes(get_root2(n+1)*2);
	int sn = 1<<17, sm = min((int)primes.size(), 1<<6);
	dp.assign(sm, vector<int>(sn));
	for(int j=0;j<sm;++j)
	for(int i=0;i<sn;++i){
		if(j == 0) dp[j][i] = i; else
		dp[j][i] = dp[j-1][i] - dp[j-1][i/primes[j-1]];
	}
}



int main() {
    ll n = 1e12;
    init(n);
    while(cin >> n) {
        cout << pi(n) << endl;
    }
    return 0;
}
