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

const int maxn = 100 + 5;
bool isprime[maxn];
int primes[maxn];
int cnt;
void init() {
    memset(isprime, true, sizeof(isprime));
    for (int i = 2; i < maxn; i++) {
        if(isprime[i]) {
            for (int j = i + i; j < maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
    cnt = 0;
    for (int i = 2; i <= 50; i++) {
        if(isprime[i]) {
            primes[cnt++] = i;
        }
    }
}
int main(void)
{
#ifdef LOCAL
   //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    int ispri = 0;
    for (int i = 0; i < cnt; i++) {
        if(ispri >= 2) break;
        printf("%d\n", primes[i]);
        fflush(stdout);
        char response[4];
        cin >> response;
        if(strcmp(response, "yes") == 0) {
            ispri++;
            if(primes[i] * primes[i] <= 100) {
                printf("%d\n", primes[i] * primes[i]);
                cin >> response;
                if(strcmp(response, "yes") == 0) {
                    ispri++;
                }
            }
        }
    }
    if(ispri >= 2) {
        printf("composite\n");
    } else {
        printf("prime\n");
    }
    fflush(stdout);
    return 0;
}
