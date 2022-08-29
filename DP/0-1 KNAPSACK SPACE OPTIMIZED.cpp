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
    //basic 0/1 knapsack algorithm
    //Finding the maximum value amongst random weights until
    int target = 7;                         //The targeted weight or capacity
    int weight[] = {1, 2, 3, 4, 5, 6};      //random objects weights
    int value[] = {10, 25, 10, 30, 15, 20}; //random objects weights value
    int dp[2][target];                      //memorization
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (i % 2 == 0)
            {
                if (weight[i - 1] <= j)
                {
                    dp[0][j] = max(value[i - 1] + dp[1][j - weight[i - 1]], dp[1][j]);
                }
                else
                {
                    dp[0][j] = dp[1][j];
                }
            }
            else
            {
                if (weight[i - 1] <= j)
                {
                    dp[1][j] = max(value[i - 1] + dp[0][j - weight[i - 1]], dp[0][j]);
                }
                else
                {
                    dp[1][j] = dp[0][j];
                }
            }
        }
    }
    cout << dp[1][target] << endl;
}

// int main()
// {
//     //basic 0/1 knapsack algorithm
//     //Finding the maximum value amongst random weights until
//     int target = 7;                         //The targeted weight or capacity
//     int weight[] = {1, 2, 3, 4, 5, 6};      //random objects weights
//     int value[] = {10, 25, 10, 30, 15, 20}; //random objects weights value
//     int dp[target + 1];                     //memorization
//     memset(dp, 0, sizeof(dp));
//     for (int i = 0; i < 6; i++)
//     {
//         for (int j = target; j >= weight[i]; j--)
//         {
//             dp[j] = max(dp[j], value[i] + dp[j - weight[i]]);
//         }
//     }
//     cout << dp[7] << endl;
// }