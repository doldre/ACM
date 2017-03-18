#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;
#define prln(x) cout << #x << " = " << x << endl
#define pr(x)  cout << #x << " = " << x << " "
const int MAXN = 2016 + 5;
int n;
bool judge(vector<int> G[MAXN], bitset<MAXN> em[MAXN]) {
    for (int i = 0; i < n; i++) {
        bitset<MAXN> mask = em[i];
        for (auto v: G[i]) {
            mask |= em[v];
            if(mask != em[i]) return false;
        }
    }
    return true;
}

char str[MAXN];
int main() {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        vector<int> PG[MAXN], QG[MAXN];
        bitset<MAXN> pem[MAXN], qem[MAXN];
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            for (int j = 0; j < n; j++) {
                if(str[j] == 'P') {
                    PG[i].push_back(j);
                    pem[i][j] = true;
                } else if(str[j] == 'Q') {
                    QG[i].push_back(j);
                    qem[i][j] = true;
                }
            }
        }
        if(judge(PG, pem) && judge(QG, qem)) {
            puts("T");
        } else {
            puts("N");
        }
    }
    return 0;
}
