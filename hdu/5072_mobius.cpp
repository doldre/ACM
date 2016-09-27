#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

const int MAXN = 1e5 + 5;
int mobius[MAXN], prime[MAXN], cnt_prime; 
bool is_prime[MAXN];

void Mobius() {
    cnt_prime = 0;
    memset(is_prime, true, sizeof(is_prime));
    mobius[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if(is_prime[i]) {
            prime[cnt_prime++] = i;
            mobius[i] = -1;
        }
        for (int j = 0; j < cnt_prime && i * prime[j] < MAXN; j++) {
            is_prime[i*prime[j]] = false;
            if(i % prime[j] == 0) {
                mobius[i * prime[j]] = 0;
                break;
            }
            mobius[i * prime[j]] = - mobius[i];
        }
    }
}

int ma;
int has[N], num[N], cp[N];
int A[N];
int n;
ll cal() {
    ll all = (ll) n * (n - 1) * (n - 2) / 6;
    memset(cp, 0, sizeof(cp));
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= ma; i++) {
        for (int j = i; j <= ma; j += i)
            num[i] += has[j];
        for (int j = i; j <= ma; j += i)
            cp[j] += mobius[i] * num[i];
    }
    ll no = 0;
    for (int i = 0; i < n; i++) {
        if(A[i] != 1) 
            no += (ll) cp[A[i]] * (n - cp[A[i]] - 1);
    }
    return all - no / 2;
}

int main() {
    Mobius();
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        memset(has, 0, sizeof(has));
        ma = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
            has[A[i]]++;
            ma = max(ma, A[i]);
        }
        printf("%lld\n", cal());
    }
    return 0;
}
