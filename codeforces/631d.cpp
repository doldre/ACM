#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, char> plc;
const int maxn = 200000 + 5;
plc t[maxn], s[maxn], ms[maxn];
int Next[maxn];
int read(int len, plc *A) {
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        plc cur;
        scanf("%lld-%c", &cur.first, &cur.second);
        if(cnt > 0 && cur.second == A[cnt-1].second) {
            A[cnt-1].first += cur.first;
        } else A[cnt++] = cur;
    }
    return cnt;
}

void get_next(plc *A, int len) {
    int i, k;
    Next[0] = k = -1;
    for (i = 0; i < len;) {
        if(k == -1 || A[i] == A[k]) {
            i++; k++;
            Next[i] = k;
        } else {
            k = Next[k];
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int tlen = read(n, t);
    int slen = read(n, s);
    for (int i = 1; i < slen - 1; i++) {
        ms[i-1] = s[i];
    }
    int mslen = slen - 2;
    get_next(ms, mslen);
    ll res = 0;
    if (slen == 1) {
        for (int i = 0; i < tlen; i++) {
            if(s[0].second == t[i].second && s[0].first <= t[i].first) {
                res += t[i].first - s[0].first + 1;
            }
        }
    } else if(slen == 2) {
        for (int i = 0; i < tlen - 1; i++) {
            if(t[i].second == s[0].second && t[i].first >= s[0].first &&
                    t[i+1].second == s[1].second && t[i+1].first >= s[1].first) {
                res++;
            }
        }
    } else {
        int i = 1, j = 0;
        while(i < tlen - 1) {
            if(j == -1 || ms[j] == t[i]) {
                i++; j++;
            } else {
                j = Next[j];
            }
            if(j == mslen && t[i].second == s[j + 1].second &&
                    t[i].first >= s[j+1].first && t[i-slen+1].second == s[0].second &&
                    t[i-slen+1].first >= s[0].first) {
                 res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
