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
const int maxn = 1e5 + 5;
const int maxm = 5e3 + 5;
char s[maxn], p[maxm]; 
char buf[maxm];
bool used[maxm];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s%s", s, p);
        for (int i = 0; i < n; i++) {
           memcpy(buf, p, m + 1);
           memset(used, false,  m + 1);
           // prln("ok");
           if(i + m <= n) {
               bool ok = true;
               for (int j = 0; j < m - 1; j++) {
                   if(s[i+j] != buf[j] && used[j]) {
                       ok = false;
                       break;
                   } else if(s[i+j] != buf[j] && !used[j]) {
                       if(s[i+j] == buf[j+1]) {
                           swap(buf[j], buf[j+1]);
                           used[j+1] = true;
                       } else {
                           ok = false;
                           break;
                       }
                   }
               }
               if(s[i+m-1] != buf[m-1]) ok = false;
               if(ok) printf("1");
               else printf("0");
           } else printf("0");
        } 
        puts("");
    }
    return 0;
}
