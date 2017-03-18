#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
 
#define ll long long
#define mod 1000000007
 
ll mod_pow(ll a, ll n, ll mo)
{
    ll ret = 1;
    while (n){
        if (n & 1) ret = ret*a%mo;
        a = a*a%mo;
        n >>= 1;
    }
    return ret;
}
 
ll inv2 = mod_pow(2, mod - 2, mod);
 
void fwt_xor(ll a[], int l, int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    fwt_xor(a, l, mid);
    fwt_xor(a, mid + 1, r);
    int len = mid - l + 1;
    for (int i = l; i <= mid; ++i){
        ll x1 = a[i];
        ll x2 = a[i + len];
        a[i] = (x1 + x2) % mod;
        a[i + len] = (x1 - x2 + mod) % mod;
    }
}
 
void ifwt_xor(ll a[], int l, int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    int len = mid - l + 1;
    for (int i = l; i <= mid; ++i){
        // y1=x1+x2
        // y2=x1-x2
        ll y1 = a[i];
        ll y2 = a[i + len];
        a[i] = (y1 + y2)*inv2 % mod;
        a[i + len] = ((y1 - y2 + mod) % mod*inv2) % mod;
    }
    ifwt_xor(a, l, mid);
    ifwt_xor(a, mid + 1, r);
}
 
void fwt_and(ll a[], int l, int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    fwt_and(a, l, mid);
    fwt_and(a, mid + 1, r);
    int len = mid - l + 1;
    for (int i = l; i <= mid; ++i){
        ll x1 = a[i];
        ll x2 = a[i + len];
        a[i] = (x1 + x2) % mod;
        a[i + len] = x2 % mod;
    }
}
 
void ifwt_and(ll a[], int l, int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    int len = mid - l + 1;
    for (int i = l; i <= mid; ++i){
        // y1=x1+x2
        // y2=x2
        ll y1 = a[i];
        ll y2 = a[i + len];
        a[i] = (y1 - y2 + mod ) % mod;
        a[i + len] = y2 % mod;
    }
    ifwt_and(a, l, mid);
    ifwt_and(a, mid + 1, r);
}
 
void fwt_or(ll a[], int l, int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    fwt_or(a, l, mid);
    fwt_or(a, mid + 1, r);
    int len = mid - l + 1;
    for (int i = l; i <= mid; ++i){
        ll x1 = a[i];
        ll x2 = a[i + len];
        a[i] = x1 % mod;
        a[i + len] = (x2+x1) % mod;
    }
}
 
void ifwt_or(ll a[], int l, int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    int len = mid - l + 1;
    for (int i = l; i <= mid; ++i){
        // y1=x1
        // y2=x2+x1
        ll y1 = a[i];
        ll y2 = a[i + len];
        a[i] = y1 % mod;
        a[i + len] = (y2 - y1 + mod) % mod;
    }
    ifwt_or(a, l, mid);
    ifwt_or(a, mid + 1, r);
}
