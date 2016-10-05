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

map<string, pii> mp;
map<pii, string> mpv;
set<pii> work, idle;
vector<pii> V;
int tot, cnt20, tim;

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &tot);
    for (int i = 0; i < tot; i++) {
        string name;
        int mot;
        cin >> name >> mot;
        mp[name] = pii(mot, tim);
        mpv[pii(mot, tim)] = name;
        V.push_back(pii(mot, tim));
        tim++;
    }
    cnt20 = tot * 0.2;
    sort(V.begin(), V.end(), greater<pii>());
    for (int i = 0; i < (int)V.size(); i++) {
        if(i < cnt20) work.insert(V[i]);
        else idle.insert(V[i]);
    }
    int M; scanf("%d", &M);
    while(M--) {
        char op[20];
        string name;
        cin >> op >> name;
        if(op[0] == '-') {
            tot--;
            cnt20 = tot*0.2;
            pii cur = mp[name];
            mp.erase(mp.find(name)); 
            mpv.erase(mpv.find(cur));
            if(cur > *idle.rbegin()) {
                work.erase(cur);
                if((int)work.size() < cnt20) {
                    name = mpv[*idle.rbegin()];
                    work.insert(*idle.rbegin());
                    idle.erase(*idle.rbegin());
                    printf("%s is working hard now.\n", name.c_str());
                }
            } else {
                idle.erase(cur);
                if((int)work.size() > cnt20) {
                    name = mpv[*work.begin()];
                    idle.insert(*work.begin());
                    work.erase(*work.begin());
                    printf("%s is not working now.\n", name.c_str());
                }
            }
        } else if(op[0] == '+') {
            int mot; cin >> mot;
            pii cur = pii(mot, tim); tim++;
            tot++;
            cnt20 = tot*0.2;
            mp[name] = cur;
            mpv[cur] = name;
            if((int)work.size() == cnt20) {
                if(!work.empty() && cur > *work.begin()) {
                    string nname = mpv[*work.begin()];
                    idle.insert(*work.begin());
                    work.erase(*work.begin());
                    work.insert(cur);
                    printf("%s is working hard now.\n", name.c_str());
                    printf("%s is not working now.\n", nname.c_str());
                } else {
                    idle.insert(cur);
                    printf("%s is not working now.\n", name.c_str());
                }
            } else if((int)work.size() < cnt20) {
                if(cur > *idle.rbegin()) {
                    work.insert(cur);
                    printf("%s is working hard now.\n", name.c_str());
                } else {
                    string nname = mpv[*idle.rbegin()];
                    work.insert(*idle.rbegin());
                    idle.erase(*idle.rbegin());
                    idle.insert(cur);
                    printf("%s is not working now.\n", name.c_str());
                    printf("%s is working hard now.\n", nname.c_str());
                }
            }
        }
    }
    return 0;
}

