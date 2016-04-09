#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;
const ll mod = (ll)1e9 + 7;
char str[maxn];
ll buf[maxn];
int cnt[26];

ll fast_pow(ll x, int n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

ll work(int a, int b) {
    memset(buf, 0, sizeof(buf));
    for (int i = a; i >= a - b + 1; i--) {
        int t = i;
        for (int j = 2; j <= t; j++) {
            while(t % j == 0) {
                buf[j]++;
                t /= j;
            }
        }
    }
    for (int i = 1; i <= b; i++) {
        int t = i;
        for (int j = 2; j <= t; j++) {
            while(t % j == 0) {
                buf[j]--;
                t /= j;
            }
        }
    }
    ll res = 1;
    for (int i = 1; i <= maxn; i++) {
        res = (res * fast_pow(i, buf[i])) % mod;
    }
    return res;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", str);
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            cnt[str[i] - 'a']++;
        }
        int odd_num = 0;
        for (int i = 0; i < 26; i++) {
             if(cnt[i] % 2 == 1) odd_num++;
        }
        if (odd_num > 1) {
            printf("0\n");
        } else {
            ll ans = 1;
            int t = len / 2;
            for (int i = 0; i < 26; i++) {
                 ans = (ans * work(t, cnt[i] / 2)) % mod;
                 t -= cnt[i] / 2;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
