/************************************************
 *Author        :mathon
 *Created Time  :四  4/28 14:41:15 2016
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

const int maxn = 5e6 + 10;

int nxt[maxn];
char s[maxn], A[maxn], B[maxn];

void getNxt(char *s) {
    int len = strlen(s);
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < len) {
        if(j == -1 || s[i] == s[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

char stk[maxn];
int top;

int main(void)
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s%s%s", s, A, B);
        getNxt(A);
        int len = strlen(s);
        int lena = strlen(A), lenb = strlen(B);
        top = 0;
        for (int i = 0, j = 0; i < len; ++i) {
            stk[top++] = s[i];
            while(j >= 0 && stk[top-1] != A[j]) j = nxt[j];
            j++;
            if(j == lena) {
                top -= lena;
                for (int k = 0; k < lenb; k++) {
                    stk[top++] = B[k];
                }
                j = 0;
            }
        }
        for (int i = 0; i < top; i++) putchar(stk[i]);
        puts("");
    }
    return 0;
}
