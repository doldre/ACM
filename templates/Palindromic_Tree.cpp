const int MAXN = 100005;
const int N = 26;

struct Palindromic_Tree {
    int next[MAXN][N]; //next指针，指向当前串两端加上同一个字符构成的回文串
    int fail[MAXN]; //fail指针，失配后跳转到fail指针指向的节点
    int cnt[MAXN]; //表示节点i表示的回文串的个数
    //表示节点i表示的最长回文串的最右端点为回文串结尾的回文串个数
    int num[MAXN]; 
    int len[MAXN]; 
};
