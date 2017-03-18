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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const int MAXN = 5e4 + 5;
const int MAXK = 1e6 + 5;
const int BLOCK = 200;
int cnt_man[MAXK], cnt_woman[MAXK];
int cnt_min[MAXK];
int n, m, k;
struct Seg {
    int l, r, id;
    int block;
}segs[MAXN];

int A[MAXN], B[MAXN];
int res[MAXN];
bool cmp(const Seg &a, const Seg &b) {
    if(a.block != b.block) {
        return a.block < b.block;
    } else return a.r < b.r;
}

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &segs[i].l, &segs[i].r);
        segs[i].id = i;
        segs[i].block = segs[i].l / BLOCK;
    }
    
    sort(segs, segs + m, cmp);
    int l = 0, r = -1;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        while(l < segs[i].l) {
            cnt_man[A[l]]--;
            ans += min(cnt_man[A[l]], cnt_woman[A[l]]) - cnt_min[A[l]];
            cnt_min[A[l]] = min(cnt_man[A[l]], cnt_woman[A[l]]);
            cnt_woman[B[l]]--;
            ans += min(cnt_man[B[l]], cnt_woman[B[l]]) - cnt_min[B[l]];
            cnt_min[B[l]] = min(cnt_man[B[l]], cnt_woman[B[l]]);
            l++;
        }
        while(l > segs[i].l) {
            l--;
            cnt_man[A[l]]++;
            ans += min(cnt_man[A[l]], cnt_woman[A[l]]) - cnt_min[A[l]];
            cnt_min[A[l]] = min(cnt_man[A[l]], cnt_woman[A[l]]);
            cnt_woman[B[l]]++;
            ans += min(cnt_man[B[l]], cnt_woman[B[l]]) - cnt_min[B[l]];
            cnt_min[B[l]] = min(cnt_man[B[l]], cnt_woman[B[l]]);
        }
        while(r < segs[i].r) {
            r++;
            cnt_man[A[r]]++;
            ans += min(cnt_man[A[r]], cnt_woman[A[r]]) - cnt_min[A[r]];
            cnt_min[A[r]] = min(cnt_man[A[r]], cnt_woman[A[r]]);
            cnt_woman[B[r]]++;
            ans += min(cnt_man[B[r]], cnt_woman[B[r]]) - cnt_min[B[r]];
            cnt_min[B[r]] = min(cnt_man[B[r]], cnt_woman[B[r]]);
        }
        while(r > segs[i].r) {
            cnt_man[A[r]]--;
            ans += min(cnt_man[A[r]], cnt_woman[A[r]]) - cnt_min[A[r]];
            cnt_min[A[r]] = min(cnt_man[A[r]], cnt_woman[A[r]]);
            cnt_woman[B[r]]--;
            ans += min(cnt_man[B[r]], cnt_woman[B[r]]) - cnt_min[B[r]];
            cnt_min[B[r]] = min(cnt_man[B[r]], cnt_woman[B[r]]);
            r--;
        }
        res[segs[i].id] = ans;
    }
    for (int i = 0; i < m; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}

