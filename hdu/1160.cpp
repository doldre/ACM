#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 5;
const int inf = 0x3f3f3f3f;
pair<pair<int, int>, int > mices[maxn];
int dp[maxn], path[maxn];

void output(int i, int cnt) {
    if(i == 0) {
        printf("%d\n", cnt);
        return;
    }
    output(path[i], cnt + 1);
    printf("%d\n", mices[i].second);
}
int main() {
//    freopen("in.txt", "r", stdin);
    int w, s;
    int cnt = 0;
    mices[cnt++] = make_pair(make_pair(0, inf), -1);
    while(scanf("%d%d", &w, &s) == 2) {
        mices[cnt] = make_pair(make_pair(w, s), cnt);
        cnt++;
    }
    sort(mices, mices + cnt);
    dp[0] = 0;
    int last = 0;
    for (int i = 1; i <= cnt; i++) {
        for (int j = 0; j < i; j++) {
            if(mices[i].first.first > mices[j].first.first && mices[i].first.second < mices[j].first.second) {
                if(dp[i] <= dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    path[i] = j;
                    if(dp[i] > dp[last]) {
                        last = i;
                    }
                }
            }
        }
    }
    output(last, 0);
    return 0;
}
