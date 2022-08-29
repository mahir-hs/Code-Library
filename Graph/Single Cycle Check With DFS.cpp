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
#define mx 2000056
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define MEM(a, x) memset(a, x, sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define vii vector<int>
#define vll vector<ll>
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
const int INF = INT_MAX;
int fx[] = {+1, -1, +0, +0};
int fy[] = {+0, +0, +1, -1};

// freopen("data.txt", "r", stdin);
// freopen("dataOut.txt", "w", stdout);
///cout<<"Case "<<z++<<": "<<__<<endl;

typedef bool (*comp)(pii, pii);
enum Color
{
    white,
    gray,
    black
};
bool cycleCheck(int node, vii g[], int vis[])
{
    vis[node] = gray;

    for (auto k : g[node])
    {
        if (vis[k] == gray)
        {
            return true;
        }
        if (vis[k] == white && cycleCheck(k, g, vis))
        {
            return true;
        }
    }
    vis[node] = black;
    return false;
}

bool isCycle(int n, vii g[])
{
    int vis[n + 1];
    for (int i = 0; i <= n; i++)
    {
        vis[i] = white;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == white)
        {
            if (cycleCheck(i, g, vis) == true)
            {
                return true;
            }
        }
    }

    return false;
}
int main()
{

    int v, w;
    cin >> v >> w;
    vii g[v + 1];
    for (int i = 0; i < w; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    cout << isCycle(v, g) << endl;
}

//9 10 1 2 2 3 3 4 3 6 4 5 6 5 7 2 7 8 8 9 9 7