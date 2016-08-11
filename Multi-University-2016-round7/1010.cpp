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

set<pair<int, int> > sa, sb;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Cas = 0;
    int n;
    char opt[20], c;
    int x;
    set<pii> *A = &sa, *B = &sb;
    while(scanf("%d", &n) == 1 && n) {
        printf("Case #%d:\n", ++Cas);
        A->clear(), B->clear();
        for (int i = 1; i <= n; i++) {
            scanf("%s %c", opt, &c);
            if(opt[1] == 'u') {
                scanf("%d", &x);
                if(c == 'A') {
                    A->insert(pii(i, x));
                } else {
                    B->insert(pii(i, x));
                }
            }
            if(opt[1] == 'o') {
                int ans;
                if(c == 'A') {
                    pii t = *A->rbegin();
                    ans = t.yy;
                    A->erase(t);
                } else {
                    pii t = *B->rbegin();
                    ans = t.yy;
                    B->erase(t);
                }
                printf("%d\n", ans);
            }
            if(opt[1] == 'e') {
                scanf("%s", opt);
                if(A->size() < B->size()) {
                    swap(A, B);
                }
                while(!B->empty()) {
                    A->insert((*B->rbegin()));
                    B->erase(--B->end());
                }
                if(c == 'B') {
                    swap(A, B);
                }
            }
        }
    }
    return 0;
}

