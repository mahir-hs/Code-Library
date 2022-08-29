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

int main()
{
    //LIS algorithm and restoring

    vii v = {10, 2, 3, 4, 5, 1, 4, 5, 2, 4, 5};
    int s = v.size();
    vii store_max_length(s, -1);
    vii lis(s, 1);
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j] && lis[j] + 1 > lis[i])
            {
                lis[i] = lis[j] + 1;
                store_max_length[i] = j;
            }
        }
    }

    int ans = *max_element(lis.begin(), lis.end());
    int pos = 0;
    for (int i = 0; i < s; i++)
    {
        if (lis[i] == ans)
        {
            pos = i;
        }
    }

    vii subseq;
    while (pos != -1)
    {
        subseq.pb(v[pos]);
        pos = store_max_length[pos];
    }
    reverse(subseq.begin(), subseq.end());
    for (auto k : subseq)
    {
        cout << k << " ";
    }
}