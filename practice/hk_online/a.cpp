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

const int offset = 5e4;
const int MAXN = (1<<22) + 5;
int cnt[MAXN];
int n;

const double PI = acos(-1.0);
//复数结构体
struct complex
{
    long double r,i;
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

complex A[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        cnt[x+offset]++;
    }
    for (int i = 0; i <= 2 * offset; i++) {
        A[i] = complex(cnt[i], 0);
    }
    int len = 1<<20;
    fft(A, len,1);
    for (int i = 0; i < len; i++) {
        A[i] = A[i] * A[i];
    }
    fft(A, len, -1);
    ll ans = 0;
    for (int i = offset; i <= 3*offset; i++) {
        ll t = A[i].r + 0.5;
        ans += t * cnt[i - offset];
    }
    for (int i = 0; i <= 2*offset; i++) {
        if(i + i - offset >= 0 && i != offset) {
            ans -= (ll)cnt[i] * cnt[i+i-offset];
        }
        if(i != offset) ans -= (ll)cnt[i] * cnt[offset] * 2;
        if(i == offset) {
            ans -= (ll)cnt[i] * (cnt[i] - 1) * 3;
            ans -= (ll)cnt[i];
        }
    }
    cout << ans << endl;
    return 0;
}

