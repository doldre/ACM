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
const int maxn = 1e4 + 5;
pair<pii, int> A[maxn];
pii buf[maxn];
int pos[maxn], sta[maxn];
int L, T, n;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Case; scanf("%d", &Case);
    for (int Cas = 1; Cas <= Case; Cas++) {
        scanf("%d%d%d", &L, &T, &n);
        for (int i = 0; i < n; i++) {
            int x; char ch;
            cin >> x >> ch;
            A[i].xx.xx = x;
            A[i].yy = i;
            A[i].xx.yy = (ch == 'R' ? 1 : -1);
        }
        sort(A, A + n);
        for (int i = 0; i < n; i++) {
            buf[i].xx = A[i].xx.xx + A[i].xx.yy * T;
            buf[i].yy = A[i].xx.yy;
        }
        sort(buf, buf + n);
        printf("Case #%d:\n", Cas);

        for (int i = 0; i < n; i++) {
            pos[A[i].yy] = buf[i].xx;
            // prln(A[i].yy);
            if(buf[i].xx < 0 || buf[i].xx > L) {
                sta[A[i].yy] = 1;
            } else {
                // printf("%d ", buf[i].xx);
                if((i > 0 && buf[i].xx == buf[i-1].xx) ||
                        (i < n - 1 && buf[i].xx == buf[i+1].xx)) {
                    sta[A[i].yy] = 2;
                } else {
                    if(buf[i].yy == 1) {
                        sta[A[i].yy] = 3;
                    } else {
                        sta[A[i].yy] = 4;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if(sta[i] == 1) {
                printf("Fell off\n");
            } 
            if(sta[i] == 2) {
                printf("%d Turning\n", pos[i]);
            }
            if(sta[i] == 3) {
                printf("%d R\n", pos[i]);
            }
            if(sta[i] == 4) {
                printf("%d L\n", pos[i]);
            }
        }
        puts("");
    }
    return 0;
}

