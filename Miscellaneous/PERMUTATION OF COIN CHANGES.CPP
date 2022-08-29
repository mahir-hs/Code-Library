#include <bits/stdc++.h>
//#define  FIO   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1.0)
#define ll long long
#define EPS 1e-12
#define MV 1e18
#define mx INT_MAX
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>
#define vip vector<pair<int, int>>
#define vlp vector<pair<ll, ll>>
#define pb push_back
#define mp make_pair
#define ull unsigned ll
const int INF = 0x3f3f3f3f;
using namespace std;
// freopen("data.txt", "r", stdin);
// freopen("dataOut.txt", "w", stdout);
///cout<<"Case "<<z++<<": "<<__<<endl;

int main()
{
    int x;
    while (~scanf("%d", &x))
    {
        int arr[] = {1, 5, 10, 25, 50};
        int dp[x + 1];
        for (int i = 0; i <= x; i++)
        {
            dp[i] = 0;
        }
        dp[0] = 1;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 1; j <= x; j++)
            {
                if (arr[i] <= j)
                {
                    dp[j] += dp[j - arr[i]];
                }
            }
        }
        cout << dp[x] << endl;
    }
}