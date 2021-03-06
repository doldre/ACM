#include <cstdio>
#include <algorithm>
#define ll long long

const int N = 5e5+9;

int n, a, b, T;
ll pre[N+9];
ll suf[N+9];
char str[N+9];
int ans;

int main() {
    scanf("%d%d%d%d%s", &n, &a, &b, &T, str+1);
    for(int i = 1; i <= n; ++i)
        pre[i] = pre[i-1]+a*(i>1)+(str[i]=='w')*b+1;
    for(int i = n; i >= 1; --i)
        suf[i] = suf[i+1]+a+(str[i]=='w')*b+1;
    int x = 1, y = 2;
    while(x <= n && pre[x] <= T) {
        while(y <= n && pre[x]+std::min(x-1, n-y+1)*a+suf[y] > T) y++;
        while(y <= x) y++;
        ans = std::max(ans, x+n-y+1);
        ++x;
    }
    printf("%d\n", ans);
    return 0;
}
