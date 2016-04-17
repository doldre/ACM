const int N=501000*2;
char s[N];
int n,rk[N],sa[N],ht[N],r[N],pro[N];
pair<PII,int> pos[N];
VI vec[N];

void buildSA(char *p) {
	rep(i,0,n) rk[i]=p[i];
	rep(j,0,19) {
		rep(i,0,n) pos[i]=mp(mp(rk[i],rk[i+(1<<j)]),i);
		sort(pos,pos+n);
		int cnt=0;
		rep(i,0,n) {
			rk[pos[i].se]=cnt+1;
			cnt+=(pos[i].fi!=pos[i+1].fi);
		}
		if (cnt==n) break;
	}
	rep(i,0,n) sa[rk[i]]=i;
}
