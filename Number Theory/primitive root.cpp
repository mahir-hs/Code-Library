#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define nl '\n'

template <class T> inline T bigmod(T p,T e,T M) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}



ll totient(ll a)
{
    double ans = a;

    for (ll i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            while (a % i == 0)
            {
                a /= i;
            }
            ans *= (1.0 - (1.0 / (double)i));
        }
    }
    if (a > 1)
    {
        ans *= (1.0 - (1.0 / (double)a));
    }
    return ans;
}


int primitive_root(int p) {
    vector<int> fact;
    int phis = totient(p),  n = phis;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    int ans = 0;
    if (n > 1) fact.push_back(n);
    for (int res = 1; res < p; ++res) { // this loop will run at most (logp ^ 6) times i.e. until a root is found
        bool ok = true;
        // check if this is a primitive root modulo p
        for (size_t i = 0; i < fact.size() && ok; ++i)
            ok &= bigmod(res, phis / fact[i], p) != 1;
        if (ok)  ans++;;
    }
    return ans;
}



void solve()
{
    /*
     */
    int a;
    cin>>a;
    int ans=primitive_root(a);
    cout<<ans<<nl;
}


int main()
{
    solve();
}



