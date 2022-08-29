#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/Tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>

// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
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

ll tree[2][mx];
ll a;

void update(ll i, ll idx, ll val)
{
    while (idx <= a)
    {
        tree[i][idx] += val;

        idx += (idx & (-idx));
    }
}

ll query(int i, int idx)
{
    ll ans = 0;

    while (idx > 0)
    {
        ans += tree[i][idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

ll prefix_sum(int idx)
{
    return (query(0, idx) * idx) - query(1, idx);
}

void solve()
{
    /*
     */

    ll b;
    cin >> a >> b;

    for (int i = 1; i <= a; i++)
    {
        ll x;
        cin >> x;
        update(0, i, x);
        update(0, i + 1, -x);
        update(1, i, -x * (i - 1));
        update(1, i + 1, i * x);
    }

    while (b--)
    {

        int x;
        cin >> x;
        if (x == 0)
        {
            int l, r, k;
            cin >> l >> r >> k;
            l++;
            r++;

            update(0, l, k);
            update(0, r + 1, -k);
            update(1, l, -k * (l - 1));
            update(1, r + 1, r * k);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l++;
            r++;

            cout << query(0, r) * r + query(1, r) - query(0, l - 1) * (l - 1) - query(1, l - 1) << nl;
        }
    }

    for (int i = 1; i <= a; ++i)
    {
        /* code */
        tree[0][i] = 0;
        tree[1][i] = 0;
    }
    // cout << nl;
}

int main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.in", "r", stdin);
    //     freopen("output.out", "w", stdout);
    // #endif

    FIO;
    startTime = clock();

    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    //}

    fprintf(stderr, "\n>> Runtime: % .10fs\n", (double)(clock() - startTime) / CLOCKS_PER_SEC);
}