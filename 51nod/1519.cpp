#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
int H[MAXN];
int L[MAXN], R[MAXN];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &H[i]);
    }
    for (int i = 1; i <= n; i++) {
        L[i] = min(L[i-1] + 1, H[i]);
    }
    for (int i = n; i >= 1; i--) {
        R[i] = min(R[i+1] + 1, H[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, min(L[i], R[i]));
    }
    printf("%d\n", ans);
}
