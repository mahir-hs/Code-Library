#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/TREE_policy.hpp>
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

struct node
{
    ll sum;
    ll prefix;
    ll suffix;
    ll maxsum;
};
node tree[mx << 4];
int a[mx];
node join(node left, node right)
{
    /*
    Maximum sum of a subarray, starting at the leftmost index of this range
    Maximum sum of a subarray, ending at the rightmost index of this range
    Maximum sum of any subarray in this range
    Sum of all elements in this range
    */
    node res;
    res.sum = left.sum + right.sum;
    res.prefix = max(left.prefix, left.sum + right.prefix);
    res.suffix = max(right.suffix, right.sum + left.suffix);
    res.maxsum = max(res.prefix, max(res.suffix, max(left.maxsum, max(right.maxsum, left.suffix + right.prefix))));

    return res;
}
void buildTree(int index, int s, int e)
{
    // base case
    if (s > e)
        return;
    // reached leaf node
    if (s == e)
    {
        // tree[index].m = tree[index].mr = tree[index].ml = tree[index].s = a[s];
        tree[index].maxsum = tree[index].prefix = tree[index].suffix = tree[index].sum = a[s];
        return;
    }
    // now build the segment tree in bottom up manner
    int m = (s + e) / 2;
    buildTree(2 * index, s, m);
    buildTree(2 * index + 1, m + 1, e);
    node left = tree[2 * index];
    node right = tree[2 * index + 1];
    tree[index] = join(left, right);
    return;
}

// function to query the segment tree for RSQ
node query(int index, int s, int e, int leftPoint, int rightPoint)
{
    // base case: if query range is outside the node range
    if (leftPoint > e || s > rightPoint)
        return node{ -INF, -INF, -INF, -INF};
    // complete overlap
    if (s >= leftPoint && e <= rightPoint)
        return tree[index];
    // now partial overlap case is executed
    int m = (s + e) / 2;
    node left = query(2 * index, s, m, leftPoint, rightPoint);
    node right = query(2 * index + 1, m + 1, e, leftPoint, rightPoint);
    return join(left, right);
}

void solve()
{
    /*
     */
    int n, c;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    buildTree(1, 1, n);
    scanf("%d", &c);
    while (c--)
    {
        int j, k;
        scanf("%d %d", &j, &k);
        printf("%lld\n", query(1, 1, n, j, k).maxsum);
    }

    // for (int i = 1; i <= 13; i++)
    // {
    //     cout << i << " :" << nl;
    //     cout << TREE[i].sum << " " << TREE[i].prefix << " " << TREE[i].suffix << " " << TREE[i].maxsum << nl;
    // }
}

int main()
{
    FIO;
    // startTime = clock();
    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    //}

    // fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - startTime) / CLOCKS_PER_SEC);
}