#include <bits/stdc++.h>
//#define  FIO   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1.0)
#define ll long long
#define EPS 1e-12
#define MV 1e18
#define mx 1000000 + 10
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
using namespace std;
// freopen("data.txt", "r", stdin);
// freopen("dataOut.txt", "w", stdout);
///cout<<"Case "<<z++<<": "<<__<<endl;
int a[1000], b[1000], f[1000];
int main()
{
    int answer = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        f[i] = lower_bound(b + 1, b + answer + 1, a[i]) - b; //saving the i'th index number for which a[i] fit in

        answer = max(answer, f[i]); //maximum size
        b[f[i]] = a[i];             //updating the seaching index
    }
    cout << "LIS length - \n"
         << answer;

    vector<int> T;
    int require = answer;
    for (int i = n; i >= 1; i--)
        if (f[i] == require)
        {
            T.push_back(a[i]);
            require--;
        }

    int i = T.size();
    while (i--)
        cout << T[i] << " ";
    printf("\n");
}
