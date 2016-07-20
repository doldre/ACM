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
const int maxn = 1e7 + 5;
char str[maxn];
int cnt[10];
char ans[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", str);
        memset(cnt, 0, sizeof(cnt));
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            cnt[str[i] - '0']++;
        }
        int b = 0;
        int tot = 0;
        for (int i = 1; i <= 9; i++) {
            if(b == 0 && cnt[i] > 0) {
                b = i;
                cnt[i]--;
            }
            tot += cnt[i];
        }
        if(tot == 0 || b == 0) {
            printf("Uncertain\n");
        } else {
            int len = 0;
            for (int i = 9; i >= 0; i--) {
                while(cnt[i] > 0) {
                    ans[len++] = i + '0';
                    cnt[i]--;
                }
            }
            int up = b;
            ans[len] = '\0';
            for (int i = len - 1; i >= 0; i--) {
                int t = ans[i] - '0';
                ans[i] = (t + up) % 10 + '0';
                up = (t + up) / 10;
            }
            if(up > 0) {
                printf("%d", up);
            }
            printf("%s\n", ans);
        }
    }
    return 0;
}

