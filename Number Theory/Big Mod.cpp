#include <bits/stdc++.h>
using namespace std;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long

int bigmod(ll a, ll b, ll c)
{
    if (b == 0)
        return 1;
    else if (b % 2 == 1)
    {
        int s = a % c;
        int eve = (bigmod(a, b - 1, c) % c) % c;
        return (s * eve) % c;
    }
    else
    {
        int eve = (bigmod(a, b / 2, c) % c) % c;

        return (eve * eve) % c;
    }
}

int main()
{

    FIO;
    ll a, b, c;

    int ans = bigmod(a, b, c);
    cout << ans << nl;
}
