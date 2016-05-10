/************************************************
 *Author        :mathon
 *Created Time  :一  5/ 9 15:10:37 2016
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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 500000 + 5;
int A[maxn];
ll sum[maxn];
ll dp[maxn];
int que[maxn], head, tail;
int N, M;
ll gety(int i) {
    return dp[i] + sum[i] * sum[i];
}
ll getx(int i) {
    return sum[i];
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(~scanf("%d%d", &N, &M)) {
        for (int i = 1; i <= N; i++) {
            sa(A[i]);
            sum[i] = sum[i - 1] + A[i];
        }
        head = tail = 0;
        que[tail++] = 0;
        for (int i = 1; i <= N; i++) {
            int qi, qj, qk; //qi < qj < qk;
            while(head + 1 < tail) {
            //        gety(head + 1) - gety(head) <= 2 *sum[i] * (getx(head+1) - getx(head))) head++;
                qi = que[head], qj = que[head + 1], qk = i;
                if(gety(qj) - gety(qi) <= 2*sum[qk] * (sum[qj] - sum[qi])) head++;
                else break;
            }
            int k = que[head];
            dp[i] = dp[k] + (sum[i] - sum[k]) * (sum[i] - sum[k]) + M;
            while(head + 1 < tail) {
                    /* (gety(i) - gety(tail - 1)) * (getx(tail - 1) - getx(tail - 2)) <= */
                    /* (gety(tail - 1) - gety(tail - 2)) * (getx(i) - getx(tail - 1))) tail--; */
                qi = que[tail-2], qj = que[tail-1], qk = i;
                if((gety(qk) - gety(qj)) * (getx(qj) - getx(qi)) <= (gety(qj) - gety(qi)) * (getx(qk) - getx(qj))) tail--;
                else break;
            }
            que[tail++] = i;
        }
        cout << dp[N] << endl;
    }
    return 0;
}
