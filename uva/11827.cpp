/************************************************
 *Author        :mathon
 *Created Time  :2016年04月14日 星期四 15时10分18秒
 ***********************************************/
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
#include <sstream>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 1e5 + 12;
int A[maxn];

int gcd(int a, int b) {
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
	int N;
	scanf("%d", &N);
	getchar();
	while(N--) {
		string str;
		getline(cin, str);
		stringstream os(str);
		int cnt = 0;
		while(os >> A[cnt]) {
			cnt++;
		}
		//cout << cnt << endl;
		int ans = 0;
		for (int i = 0; i < cnt; i++) {
			for (int j = i + 1; j < cnt; j++) {
				ans = max(ans, gcd(A[i], A[j]));
			}
		}
		cout << ans << endl;
	}
    return 0;
}
