#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/Tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>

// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
using namespace std;
using u128 = __uint128_t;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pi acos(-1.0)
#define ll long long
#define ull unsigned ll int
#define EPS 1e-12
#define MV 1e18
#define MX 100000009
#define mx 2000056
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mem(a, x) memset(a, x, sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define vii vector<int>
#define vll vector<ll>
#define vul vector<ull>
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
#define mp mate_pair
#define nl '\n'
#define SP(x, y) fixed << setprecision((x)) << (y)
#define mod 1000000007
#define INF 0x3F3F3F3F

clock_t startTime;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
double getCurrentTime()
{
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

int fx[] = {0, 1, 0, -1};
int fy[] = {-1, 0, 1, 0};
int tr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int tc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

/// cout<<"Case "<<z++<<": "<<__<<endl;

// typedef bool (*comp)(pii, pii);

//******************************** Template ***********************
template <class T>
inline T bitOn(T n, T pos) { return n | ((T)1 << pos); }
template <class T>
inline T bitOff(T n, T pos) { return n & ~((T)1 << pos); }
template <class T>
inline T isOn(T n, T pos) { return (bool)(n & ((T)1 << pos)); }

template <class T>
istream &operator>>(istream &is, vector<T> &input)
{
    for (T &in : input)
        is >> in;
    return is;
}

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(?) : return count of values which is < ?
// find_by_order(?): access the ? index in set

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
// bool is(int x, int y)
// {
//     if (x >= 0 && y >= 0 && vis[x][y] == false) // out of box or not
//         return true;
//     return false;
// }
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

ull modularExpo(ull a, ull d, ull n)
{
    ull res = 1LL;
    a %= n; // (a^d)%n === (a%n)^d
    while (d)
    {
        if (d & 1) // First bit and the last bit
            res = (u128)res * a % n;

        d = d >> 1; // d=/2
        a = (u128)a * a % n;
    }
    return res;
}

bool miller(ull d, ull n)
{
    ull a = 2 + rand() % (n - 4); // random number picking

    ull b0 = modularExpo(a, d, n);

    if (b0 == 1LL or b0 == n - 1)
        return false;

    while (d != n - 1)
    {
        b0 = (u128)b0 * b0 % n; // a^((2^r)*d) = (a^d)^*2r
        d *= 2;                 // (2^r)*d  = n-1 or it
        if (b0 == n - 1)
            return false;
    }
    return true;
}

bool isPrime(ull n)
{
    if (n <= 1LL or n == 4LL)
        return false;
    if (n <= 3LL)
        return true;

    ll d = n - 1;
    int it = 1;
    while (d % 2LL == 0LL)
    {
        d /= 2LL;
        it++;
    }

    for (int i = 1; i <= it; i++)
    {
        if (miller(d, n) == true)
            return false;
    }
    return true;
}

void solve()
{

    /*
999999999999999989
    */

    ull a;
    cin >> a;
    if (a % 2 == 0LL and a != 2)
    {
        cout << "NO" << nl;
        return;
    }
    cout << (isPrime(a) ? "YES" : "NO") << nl;
}

int main()
{

    FIO;
    // startTime = clock();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    // fprintf(stderr, "\n>> Runtime: % .10fs\n", (double)(clock() - startTime) / CLOCKS_PER_SEC);
}