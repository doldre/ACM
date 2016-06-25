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
const int maxn = 1e6 + 5;
char ops[3][10] = {
    "insert",
    "getMin",
    "removeMin",
};
int res[maxn], num[maxn];
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > que;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);
        if(strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            que.push(x);
           res[cnt] = 0, num[cnt++] = x;
        } else if(strcmp(op, "removeMin") == 0) {
            if(que.empty()) {
                que.push(1);
                res[cnt] = 0, num[cnt++] = 1;
            }
            que.pop();
            res[cnt++] = 2;
        } else if(strcmp(op,"getMin") == 0) {
            int x;
            scanf("%d", &x);
            while(!que.empty() && que.top() < x) {
                res[cnt++] = 2;
                que.pop();
            }
            if(que.empty() || que.top() > x) {
                que.push(x);
                res[cnt] = 0, num[cnt++] = x;
            }
            res[cnt] = 1, num[cnt++] = x;
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%s ", ops[res[i]]);
        if(res[i] < 2) {
            printf("%d", num[i]);
        }
        cout << endl;
    }
    return 0;
}
