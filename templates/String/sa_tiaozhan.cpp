#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 50000 + 5;
class SA {
public:
    static int n, k;
    static int rank[MAX_N + 1];
    static int tmp[MAX_N + 1];
    static int lcp[MAX_N + 1];

    static bool compare_sa(int i, int j) {
        if (rank[i] != rank[j]) return rank[i] < rank[j];
        else {
            int ri = i + k <= n ? rank[i + k]: -1;
            int rj = j + k <= n ? rank[j + k]: -1;
            return ri < rj;
        }
    }

    void construct_sa(char *S, int *sa) {
        n = strlen(S);
        for (int i = 0; i <= n; i++) {
            sa[i] = i;
            rank[i] = i < n ? S[i] : -1;
        }

        for (k = 1; k <= n; k *= 2) {
            sort(sa, sa + n + 1, SA::compare_sa);
            tmp[sa[0]] = 0;
            for (int i = 1; i <= n; i++) {
                tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
            }
            for (int i = 0; i <= n; i++) {
                rank[i] = tmp[i];
            }
        }
    }

    void construct_lcp(char *S, int *sa, int *lcp) {
        int n = strlen(S);
        for (int i = 0; i <= n; i++) rank[sa[i]] = i;

        int h = 0;
        lcp[0] = 0;
        for (int i = 0; i < n; i++) {
            int j = sa[rank[i] - 1];
            if(h > 0) h--;
            for (; j + h < n && i + h < n; h++) {
                if(S[j + h] != S[i + h]) break;
            }
            lcp[rank[i] - 1] = h;
        }
    }
};

int main() {
    return 0;
}
