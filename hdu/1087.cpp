#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;
int A[maxn];
ll dp[maxn];

int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            dp[i] = A[i];
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if(A[i] > A[j]) {
                    dp[i] = max(dp[j] + A[i], dp[i]);
                    ans = max(ans, dp[i]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
