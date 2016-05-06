/************************************************
 *Author        :mathon
 *Created Time  :五  5/ 6 01:00:05 2016
 *Problem class:
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
vector<int> vi;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 5000000 + 10;

struct node {
    char c;
    int pre, next, pair;
}list[maxn];

char str[maxn];
char op[maxn];
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, m, p;
    cin >> n >> m >> p;
    scanf("%s", str + 1);
    scanf("%s", op + 1);
    stack<int> sta;
    list[0].pre = -1;
    list[0].next = 1;
    for (int i = 1; i <= n; i++) {
        list[i].pre = i - 1;
        list[i].next = i + 1;
        list[i].c = str[i];
        if(str[i] == '(') {
            sta.push(i);
        } else {
            int t = sta.top(); sta.pop();
            list[i].pair = t;
            list[t].pair = i;
        }
    }
    for (int i = 1; i <= m; i++) {
        if(op[i] == 'R') {
            p = list[p].next;
        } else if(op[i] == 'L') {
            p = list[p].pre;
        } else if(op[i] == 'D') {
            int a = p, b = list[p].pair;
            if(a > b) swap(a, b);
            list[list[a].pre].next = list[b].next;
            list[list[b].next].pre = list[a].pre;
            p = list[b].next;
            if(p == n + 1) {
                p = list[p].pre;
            }
        }
    }
    int t = list[0].next;
    while(t <= n) {
        printf("%c", list[t].c);
        t = list[t].next;
    }
    printf("\n");
    return 0;
}
