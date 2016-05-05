/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 四  5/ 5 10:01:15 2016
 *File Name*     : jy.cpp
**Problem**:
**Analyse**:
**Code**:
***********************1599664856@qq.com**********************/

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
typedef vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  "
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a));
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
const int mod = int(1e9) + 7, INF = 0x3fffffff;
const int maxn = 1e4 + 13;
const char char_st = 0;
const int max_word = 222;
const int max_charset = 128;
int id;



char word[max_word], text[maxn];

struct node {
    int cnt, id;            //单词的个数
    node *next[max_charset];     //叶子结点
    node *fail;         //失败指针
    node() {
        cnt = 0;
        id = -1;
        for (int i = 0; i < max_charset; i++) next[i] = NULL;
        fail = NULL;
    }
};

//Trie的构造
void insert(node *p, char *s) {
    for(int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - char_st;
        if(p -> next[idx] == NULL) p -> next[idx] = new node();
        p = p -> next[idx];
        pl(p);
    }
    p -> cnt++; //表示该单词出现过，并保存出现次数
    p -> id = id;
}

//Trie的内存回收
void callback(node *root) {
    getchar();
    pl(root);
    rep (i, 0, max_charset) {
        if ((root -> next)[i] != NULL) {
            pl(root->next[i]);
            callback((root->next)[i]);
        }
    }
    delete root;
}

void AC_Automation(node *root)
{
    queue <node* > q; //结点队列
    q.push(root);
    //得到fail指针
    while (!q.empty()) {
        node *p = q.front();  q.pop();
        for(int i = 0; i < max_charset; i++) {
           if(p -> next[i]) {
                //root下第一层结点的失败指针都指向root
                if(p == root) p -> next[i] -> fail = root;
                //当前结点的失败指针指向其失败结点的儿子结点
                else p -> next[i] -> fail = p -> fail -> next[i];
                q.push(p -> next[i]);
            } else { //trie树优化
                if(p == root)  p -> next[i] = root;
                else p -> next[i] = p -> fail -> next[i];
            }
        }
    }
}

int query(node *root, vi &bd) //text中有多少个是ac自动机中的串?
{
    int cnt = 0, len = strlen(text);
    node *p = root;
    for(int i = 0; i < len; i++) {
        int idx = text[i] - char_st;
        while (!(p -> next[idx]) && p != root) p = p -> fail;
        p = p -> next[idx];
        if(!p) p = root;
        node *tmp = p;
        while (tmp != root) {
            if(tmp -> cnt >= 0) {
                cnt += tmp -> cnt;
                if (tmp -> id != -1) bd.push_back(tmp -> id);
                tmp -> cnt = -1;
            }
            else break;
            tmp = tmp -> fail;
        }
    }
    return cnt;
}

int main(void)
{
#ifdef LOCAL
    //freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, m;
    while (~sa(n)) {
        node *root = new node;
        pl(root);
        rep (i, 0, n) {
            id = i + 1;
            scanf("%s", word);
            insert(root, word);
        }
        AC_Automation(root);
        sa(m);
        int total = 0;
        rep (i, 0, m) {
            scanf("%s", text);
            vi bd;
            query(root, bd);
            if (bd.size()) {
                sort(bd.begin(), bd.end());
                printf("web %d:", i + 1);
                total++;
                rep (i, 0, (int)bd.size()) printf(" %d", bd[i]);
                puts("");
            }
        }
        printf("total: %d\n", total);
        pl(root);
        getchar();
        callback(root);
    }
    return 0;
}
