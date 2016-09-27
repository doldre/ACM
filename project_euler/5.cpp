#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 50;
int cnt[MAXN];
int buf[MAXN];
void count(int x) {
    memset(buf, 0, sizeof(buf));
    for (int i = 2; i * i <= x; i++) {
        while(x % i == 0) {
            buf[i]++;
            x /= i;
        }
    }
    if(x > 1) buf[x]++;
    for (int i = 2; i <= 20; i++) {
        cnt[i] = max(cnt[i], buf[i]);
    }
}

int main() {
    for (int i = 2; i <= 20; i++) {
        count(i);
    }
    long long ans = 1;
    for (int i = 2; i <= 20; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            ans *= i;
        }
    }
    printf("%lld\n", ans);
    return 0;
}


