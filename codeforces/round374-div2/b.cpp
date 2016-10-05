#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100 + 5;
int cnt[MAXN];
char buf[MAXN];
int n, k;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        cnt[(int)strlen(buf)]++;
    }
    scanf("%s", buf);
    int len = strlen(buf);
    int mi = 0;
    for (int i = 0; i < len; i++) {
        mi += cnt[i];
    }
    int ma = mi + cnt[len];
    mi++;
    mi = mi + (mi - 1) / k * 5;
    ma = ma + (ma - 1) / k * 5;
    printf("%d %d\n", mi, ma);
    return 0;
}

