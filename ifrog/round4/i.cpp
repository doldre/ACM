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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const int MAXN = 1000000 + 5;
char s[MAXN];
int n;

bool check(int len) {
   int p1 = 0, p2 = 0, flag = 0;
   while(p2 < n) {
       if(s[p1] == s[p2]) p1++,p2++;
       else if(flag == 0) flag = 1, p2++;
       else {
           flag = 2; break;
       }
       if(p1 == len) p1 = 0;
   }
   if(flag <= 1) return true;
   p1 = n - len, p2 = 0, flag = 0;
   while(p2 < n) {
       if(s[p1] == s[p2]) p1++, p2++;
       else if(flag == 0) flag = 1, p2++;
       else {flag = 2; break;}
       if(p1 == len) p1 = n - len;
   }
    if(flag <= 1) return true;
    return false;
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        scanf("%s", s);
        int len = n - 1;
        int ans = 0;
        for (int i = 1; i * i <= len; i++) {
            if(len % i == 0) {
                if(check(i)) {
                    ans = max(ans, len / i);
                }
                if(check(len / i)) {
                    ans = max(ans, i);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

