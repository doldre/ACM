/************************************************
 *Author        :mathon
 *Created Time  :2016年04月20日 星期三 19时50分00秒
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
const int maxn = 200 + 5;
char str[maxn]; 
stack<int> A, B;

void solve(int x, int cnt, int n, stack<int> &ans) {
    while(cnt--) {
        int t = min(n, x - cnt);
        ans.push(t);
        x -= t;
    }
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
   
    int n;
    int cnt = 0;
    char c;
    int a = 1, b = 0;
    while((c = getchar()) != '=') {
        if(c == '+') {
            str[cnt++] = '+';
            a++;
        } else if(c == '-') {
            str[cnt++] = '-';
            b++;
        }
    }
    scanf("%d", &n);
    
    if(n * a  - b >= n && a - n * b <= n) {
        printf("Possible\n");
        int x = max(a, b + n);
        int y = x - n;
        solve(x, a, n, A);
        solve(y, b, n, B);
        printf("%d ", A.top());
        A.pop();
        for (int i = 0; i < cnt; i++) {
            if(str[i] == '+') {
                printf("+ %d ", A.top()); A.pop();
            } else {
                printf("- %d ", B.top()); B.pop();
            }
        }
        printf("= %d\n", n);
    } else {
        printf("Impossible\n");
    }
    return 0;
}
