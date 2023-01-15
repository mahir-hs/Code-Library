#include <bits/stdc++.h>
using namespace std;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define mx 1000006
#define all(v) v.begin(), v.end()
#define mem(a, x) memset(a, x, sizeof(a))
#define nl endl
#define SZ(r) r.size()
const ll INF = LLONG_MAX;

const ll MOD[] = {1000000007LL, 999999929LL};
const ll base[] = {1000000009LL, 999999937LL};
ll prePower0[mx], prePower1[mx];
ll revfirstPower[mx], revsecondPower[mx];

void init()
{
    prePower0[0] = 1;
    prePower1[0] = 1;
    for (int i = 1; i < mx; i++)
    {
        prePower0[i] = (prePower0[i - 1] * base[0]) % MOD[0];
        prePower1[i] = (prePower1[i - 1] * base[1]) % MOD[1];
    }

    revfirstPower[mx - 1] = 1;
    revsecondPower[mx - 1] = 1;

    for (int i = mx - 2; i >= 1; i--)
    {
        revfirstPower[i] = (revfirstPower[i + 1] * base[0]) % MOD[0];
        revsecondPower[i] = (revsecondPower[i + 1] * base[1]) % MOD[1];
    }
}

struct Hashing
{

    ll HASH0[mx], HASH1[mx], revhash0[mx], revhash1[mx];
    Hashing()
    {
        mem(HASH0, 0);
        mem(HASH1, 0);
        mem(revhash0, 0);
        mem(revhash1, 0);
    }
    void Construct(string &s)
    {
        HASH0[0] = 0;
        HASH1[0] = 0;
        for (int i = 1; i <= s.size(); i++)
        {
            HASH0[i] = (HASH0[i - 1] * base[0] + s[i - 1]) % MOD[0];
            HASH1[i] = (HASH1[i - 1] * base[1] + s[i - 1]) % MOD[1];
        }

        revhash0[SZ(s) + 1] = 0;
        revhash1[SZ(s) + 1] = 0;

        for (int i = SZ(s); i > 0; i--)
        {
            revhash0[i] = (revhash0[i + 1] * base[0] + s[i - 1]) % MOD[0];
            revhash1[i] = (revhash1[i + 1] * base[1] + s[i - 1]) % MOD[1];
        }
    }

    ll GetForwardHash0(int l, int r)
    {
        ll hash0 = (HASH0[r] - HASH0[l - 1] * prePower0[r - l + 1]) % MOD[0];
        if (hash0 < 0)
            hash0 += MOD[0];
        return hash0;
    }

    ll GetForwardHash1(int l, int r)
    {
        ll hash1 = (HASH1[r] - HASH1[l - 1] * prePower1[r - l + 1]) % MOD[1];
        if (hash1 < 0)
            hash1 += MOD[1];
        return hash1;
    }

    ll revgetHash0(int l, int r)
    {
        ll now = (revhash0[r] - revhash0[l + 1] * revfirstPower[r - l + 1]) % MOD[0];
        if (now < 0)
        {
            now += MOD[0];
        }
        return now;
    }

    ll revgetHash1(int l, int r)
    {
        ll now = (revhash1[r] - revhash1[l + 1] * revsecondPower[r - l + 1]) % MOD[1];
        if (now < 0)
        {
            now += MOD[1];
        }
        return now;
    }
} HUSH[2];

void solve()
{

    /*
       This hashing is based on 1 indexing.
       for substring hash, just use getforwardhash and  give range in 1 indexed base

     */
    init();
    string s;
    cin >> s;
    HUSH[0].Construct(s);
    int cnt = 0;
    for (int i = 1; i <= s.size(); i++)
    {
        ll fh0 = HUSH[0].GetForwardHash0(i, s.size());
        ll fh1 = HUSH[0].GetForwardHash1(i, s.size());
        ll rh0 = HUSH[0].revgetHash0(s.size(), i);
        ll rh1 = HUSH[0].revgetHash1(s.size(), i);

        if (fh0 == rh0 and fh1 == rh1)
        {
            cnt = i;
            break;
        }
    }
}

int main()
{
}
