#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
//复数结构体
struct complex
{
    double r,i;
    complex(double _r = 0.0,double _i = 0.0)
    {
        r = _r; i = _i;
    }
    complex operator +(const complex &b)
    {
        return complex(r+b.r,i+b.i);
    }
    complex operator -(const complex &b)
    {
        return complex(r-b.r,i-b.i);
    }
    complex operator *(const complex &b)
    {
        return complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
/*
 * 进行FFT和IFFT前的反转变换。
 * 位置i和 （i二进制反转后位置）互换
 * len必须去2的幂
 */
void change(complex y[],int len)
{
    int i,j,k;
    for(i = 1, j = len/2;i < len-1; i++)
    {
        if(i < j)swap(y[i],y[j]);
        //交换互为小标反转的元素，i<j保证交换一次
        //i做正常的+1，j左反转类型的+1,始终保持i和j是反转的
        k = len/2;
        while( j >= k)
        {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}
/*
 * 做FFT
 * len必须为2^k形式，
 * on==1时是DFT，on==-1时是IDFT
 */
void fft(complex y[],int len,int on)
{
    change(y,len);
    for(int h = 2; h <= len; h <<= 1)
    {
        complex wn(cos(on*2*PI/h),sin(on*2*PI/h));
        for(int j = 0;j < len;j+=h)
        {
            complex w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                complex u = y[k];
                complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}
const int MAXN = 5e4 + 5;;
int cntA[MAXN], cntB[MAXN];
ll ans[MAXN<<1];
complex A[MAXN<<2], B[MAXN<<2];
int n, m, q;

void solve(int l, int r) {
    if(l == r) {
        ans[0] += (ll)cntA[l] * cntB[l];
        return;
    }
    int m = (l + r) >> 1;
    int len = 1;
    while(len < (r - l + 1))  len <<= 1;
    for (int i = 0; i < len; i++) {
       A[i] = i + l <= m ?  cntA[i+l] : 0;
       B[i] = i + m + 1 <= r ? cntB[i+m+1] : 0;
    }
    fft(A, len, 1); fft(B, len, 1);
    for (int i = 0; i < len; i++) {
        A[i] = A[i] * B[i];
    }
    fft(A, len, -1);
    for (int i = 0; i < len; i++) {
        ans[i+m+1+l] += (ll)(A[i].r + 0.5);
    }
    for (int i = 0; i < len; i++) {
        A[i] = i + m + 1 <= r ? cntA[i+m+1]: 0;
        B[i] = i + l <= m ? cntB[m-i]: 0;
    }
    fft(A, len, 1); fft(B, len, 1);
    for (int i = 0; i < len; i++) {
        A[i] = A[i] * B[i];
    }
    fft(A, len, -1);
    for (int i = 0; i < len; i++) {
        ans[i+1] += (ll)(A[i].r + 0.5);
    }
    solve(l, m); solve(m + 1, r);
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        memset(ans, 0, sizeof(ans));
        memset(cntA, 0, sizeof(cntA));
        memset(cntB, 0, sizeof(cntB));
        scanf("%d%d%d", &n, &m, &q);
        int ma = 0;
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            ma = max(ma, x);
            cntA[x]++;
        }
        for (int i = 1; i <= m; i++) {
            int x; scanf("%d", &x);
            ma = max(ma, x);
            cntB[x]++;
        }
        solve(0, ma);
        while(q--) {
            int c; scanf("%d", &c);
            printf("%lld\n", ans[c]);
        }
    }
    return 0;
}

