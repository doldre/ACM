#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#define prln(x) cout << #x << " = " << x << endl
using namespace std;

const int maxn = 1e5 + 5;

int A[maxn];

struct node {
    int l, r, sum;
}T[maxn*40];

int root[maxn];
int n, m;
int cnt;
vector<int> v;

int getid(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin()+ 1;
}

void update(int l, int r, int &x, int y, int pos) {
    T[++cnt] = T[y];
    x = cnt;
    T[x].sum++;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(pos <= mid) update(l, mid, T[x].l, T[y].l, pos);
    else update(mid + 1, r, T[x].r, T[y].r, pos);
}

int query(int l, int r, int x, int y, int k) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    int sum = T[T[y].l].sum - T[T[x].l].sum;
    if (k <= sum) return query(l, mid, T[x].l, T[y].l, k);
    else return query(mid + 1, r, T[x].r, T[y].r, k - sum);
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    v.resize(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        v[i-1] = A[i];
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n; i++) {
        int id = getid(A[i]);
        update(1, n, root[i], root[i-1], id);
    }
    for (int i = 1; i <= m; i++) {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        printf("%d\n", v[query(1, n, root[x-1], root[y], k) - 1]);
    }
    return 0;
}
