#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
#define vip vector<pair<int, int>>
#define vlp vector<pair<ll, ll>>
#define djk priority_queue<pll, vlp, greater<pll>>
#define pb push_back
#define mp make_pair
const int INF = INT_MAX;
int fx[] = {+1, -1, +0, +0};
int fy[] = {+0, +0, +1, -1};
using namespace std;

// freopen("data.txt", "r", stdin);
// freopen("dataOut.txt", "w", stdout);
///cout<<"Case "<<z++<<": "<<__<<endl;

typedef bool (*comp)(pii, pii);

vii v;
int sz, x;
int firstfit()
{
    int result = 0;
    int bin[x];
    for (int i = 0; i < x; i++)
    {
        int j;
        for (j = 0; j < result; j++)
        {
            if (bin[j] >= v[i])
            {
                bin[j] = bin[j] - v[i];
                break;
            }
        }
        if (j == result)
        {
            bin[result] = sz - v[i];
            result++;
        }
    }
    return result;
}
int main()
{

    cin >> x;
    for (int i = 0; i < x; i++)
    {
        int a;
        cin >> a;
        v.pb(a);
    }

    cin >> sz;
    sort(v.rbegin(), v.rend());
    int ans = firstfit();
    cout << ans << endl;
}