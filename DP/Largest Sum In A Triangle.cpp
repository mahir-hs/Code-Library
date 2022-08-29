#include <iostream>
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
int arr[1000][1000] = {0};
int main()
{
    int x;
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = i + 1; j < x; j++)
        {
            arr[i][j] = 0;
        }
    }
    for (int i = x - 2; i > -1; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[i + 1][j] > arr[i + 1][j + 1])
            {
                arr[i][j] += arr[i + 1][j];
            }
            else
            {
                arr[i][j] += arr[i + 1][j + 1];
            }
        }
    }
    cout << arr[0][0] << endl;
}
