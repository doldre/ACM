#include <cstdio>
#include <cstring>
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
