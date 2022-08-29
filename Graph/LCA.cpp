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
#define MX 100000009
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
#define sz(r) r.size()
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
}
string toBinary(ll decimal)
{
    string t = "";
    for (int i = 31; i >= 0; i--)
    {
        ll k = decimal >> i;
        if (k & 1)
            t += "1";
        else
            t += "0";
    }
    return t;
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

vll g[10000];
ll parent[10000][15];
ll depth[10000];
int z = 1;

void dfs(ll node)
{
    for (auto k : g[node])
    {
        depth[k] = depth[node] + 1;
        parent[k][0] = node;
        for (ll i = 1; i < 15; i++)
        {
            parent[k][i] = parent[parent[k][i - 1]][i - 1]; // going up from the current node
        }
        dfs(k);
    }
}

ll lca(ll a, ll b)
{
    if (depth[a] < depth[b])
    {
        swap(a, b);
    }

    ll dis = depth[a] - depth[b]; // distance between A and B, more formally, how much A have to climbe up to catch B

    for (ll i = 15 - 1; i >= 0; i--)
    {
        if (dis & (1 << i)) // checking binary value, if 1&1, then we will go up
        {
            a = parent[a][i];
        }
    }

    if (a == b)
    {
        return a;
    }

    for (ll j = 15 - 1; j >= 0; j--) //  going down from the top to the least common node
    {
        if (parent[a][j] != parent[b][j]) // until a certain node is found whose both children is A and B
        {
            a = parent[a][j];
            b = parent[b][j];
        }
    }
    return parent[a][0]; // a er parent node answer
}

void solve()
{
    /*
     */

    ll aa;
    cin >> aa;
    for (ll i = 0; i < aa; i++)
    {
        ll bb;
        cin >> bb;
        for (ll j = 0; j < bb; j++)
        {
            int c;
            cin >> c;
            g[i].pb(c);
        }
    }
    dfs(0);
    int t;
    cin >> t;

    while (t--)
    {
        ll aa, bb;
        cin >> aa >> bb;
        cout << lca(aa, bb) << nl;
    }

    for (ll i = 0; i < aa; i++)
    {
        g[i].clear();
        depth[i] = 0;
    }

    mem(parent, 0);
}

int main()
{
    FIO;

    solve();
}