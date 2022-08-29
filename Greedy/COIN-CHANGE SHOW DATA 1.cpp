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

int main()
{
    int k, c, n, i, rem, sum = 0;

    //scanning vlaues of k,c,n
    scanf("%d", &k);

    scanf("%d", &c);

    scanf("%d", &n);

    int change = k - c; //all bought items price

    //decalring arrays of size n
    int coin[n], res[n], di[n];
    float quotient[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &coin[i]); //scanning available coins

        //initialising values of array to 0
        res[i] = 0;
        di[i] = 0;
    }
    // 500 460 = 40
    // 4
    // 2 5 20 30

    for (; change > 0;)
    {
        for (i = n - 1; i >= 0; i--)
        {
            rem = change % coin[i]; //calculating remainder
            if (rem == 0)
            {
                change = change - coin[i]; //decreasing value of change
                res[i] = coin[i];          //storing perticular coin to use after
                di[i] += 1;                //counting perticular count of coin and storing to array
                break;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        sum = sum + di[i]; //calculating total number of coin required
    }
    printf("\n%d\n", sum); //printing number of coin required

    for (i = n - 1; i >= 0; i--)
    {
        if (res[i] != 0) //this condition will filterout zero coins required for that payment
        {
            printf("%d coins of %d\n", di[i], res[i]); //printing coin acc to output
        }
    }
    return 0;
}