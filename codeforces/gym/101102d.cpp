#include <cstdio>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#define prln(x) cout << #x << " = " << x << endl
#define pr(x) cout << #x << " = " << x " " 
typedef long long ll;

const int MAXC = 1e3 + 5;
int A[MAXC][MAXC];
int H[MAXC][MAXC];
int r, c;
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        memset(A, 0, sizeof(A));
        memset(H, 0, sizeof(H));
        scanf("%d%d", &r, &c);
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                scanf("%d", &A[i][j]);
            }
        }
        for (int j = 1; j <= c; j++) {
            for (int i = 1; i <= r; i++) {
                H[i][j] = A[i][j] == A[i-1][j] ? H[i-1][j] + 1: 1;
            }
        }
        ll ans = 0;
        for (int i = 1; i <= r; i++) {
            stack<pair<int, int> > sta;
            ll sum_in_sta = 0;
            for (int j = 1; j <= c; j++) {
                if(A[i][j] != A[i][j-1]) {
                    while(!sta.empty()) sta.pop();
                    sum_in_sta = 0;
                }
                int x = H[i][j];
                int len = 0;
                while(!sta.empty() && sta.top().first >= x) {
                    sum_in_sta -= (ll)sta.top().first * sta.top().second;
                    len += sta.top().second;
                    sta.pop();
                }
                sta.push(make_pair(x, len+1));
                sum_in_sta += (ll)x * (len + 1);
                // prln(sum_in_sta);
                ans += sum_in_sta;
            }
        }
        printf("%lld\n", ans);
    }
}
