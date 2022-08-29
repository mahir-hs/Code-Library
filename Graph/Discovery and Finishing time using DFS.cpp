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
int t = 1;
int stime[100];
int ftime[100];
int vis[100];
void dfs_visit(int x, vii v[])
{
    vis[x] = gray;
    stime[x] = t;
    ++t;
    for (auto k : v[x])
    {
        if (vis[k] == white)
        {
            dfs_visit(k, v);
        }
    }
    vis[x] = black;
    ftime[x] = t;
    ++t;
}
void dfs(int n, vii v[])
{
    for (int i = 0; i < 10; i++)
    {
        vis[i] = white;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == white)
        {
            dfs_visit(i, v);
        }
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    vii v[edge + 1];
    for (int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
    }
    dfs(node, v);
    for (int i = 1; i <= node; i++)
    {
        cout << i << ": " << stime[i] << " " << ftime[i] << endl;
    }
}
//5 7
//1 2 1 4 3 1 3 4 2 5 4 2 4 5