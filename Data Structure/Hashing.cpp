#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pi acos(-1.0)
#define ll long long
#define ull unsigned ll
#define EPS 1e-12
#define MV 1e18
#define MX 10000008
#define mx 1000006
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mem(a, x) memset(a, x, sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define vii vector<int>
#define vll vector<ll>
#define vuu vector<ull>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pip pair<int, pii>
#define pul pair<ull, ull>
#define mii map<int, int>
#define mll map<ll, ll>
#define qii queue<int>
#define dii deque<int>
#define vip vector<pair<int, int>>
#define vlp vector<pair<ll, ll>>
#define djk priority_queue<pll, vlp, greater<pll>>
#define pb push_back
#define mp make_pair
#define nl endl
#define SP(x, y) fixed << setprecision((x)) << (y)
#define mod 1000000007
#define SZ(r) r.size()
const ll INF = LLONG_MAX;

int fx[] = {0, 1, 0, -1};
int fy[] = {-1, 0, 1, 0};
int kr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int kc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

// freopen("data.txt", "r", stdin);
// freopen("dataOut.txt", "w", stdout);
/// cout<<"Case "<<z++<<": "<<__<<endl;

typedef bool (*comp)(pii, pii);

//******************************** Template ***********************
template <class T>
istream &operator>>(istream &is, vector<T> &input)
{
    for (T &in : input)
        is >> in;
    return is;
}
//******************************** Template ***********************

//******************************** Function ***********************
ull toDecimal(string bin)
{
    unsigned long deci = std::bitset<16>(bin).to_ulong(); // binary string to decimal
    return deci;
}
string toBinary(ll decimal)
{
    std::string binary = std::bitset<16>(decimal).to_string(); // to binary
    return binary;
}
// bool isValid(int x, int y)
// {
//     if (x >= 0 && y >= 0 && x < x && y < y && vis[x][y] == false) // out of box or not
//         return true;
//     return false;
// }
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const ll MOD[] = {1000000007LL, 999999929LL};
const ll base[] = {1000000009LL, 999999937LL};
ll prePower0[mx], prePower1[mx], HASH0[mx], HASH1[mx];
ll revfirstPower[mx], revsecondPower[mx], revhash0[mx], revhash1[mx];

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

void solve()
{

    /*


     */
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 1; i <= s.size(); i++)
    {
        ll fh0 = GetForwardHash0(i, s.size());
        ll fh1 = GetForwardHash1(i, s.size());
        ll rh0 = revgetHash0(s.size(), i);
        ll rh1 = revgetHash1(s.size(), i);

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
