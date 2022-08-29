#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pi acos(-1.0)
#define ll long long
#define EPS 1e-12
#define MV 1e18
#define mx 1000000000
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
struct str
{
    float weight;
    float profit;
    float kg;
};
bool cmp(str a, str b) //comaparing which one hold maximum profit for a KG
{
    return a.kg > b.kg;
}
float knapsack(str tri[], int size, int w)
{
    float totval = 0, totweight = 0;
    for (int i = 0; i < size; i++)
    {
        tri[i].kg = tri[i].profit / tri[i].weight; // per kg profit
    }
    sort(tri, tri + size, cmp);
    for (int i = 0; i < size; i++)
    {
        if (totweight + tri[i].weight <= w)
        {
            totweight += tri[i].weight;
            totval += tri[i].profit;
        }
        else
        {
            int remain = w - totweight; //last items kg value adding
            totweight += remain;
            totval += (remain * tri[i].kg);
            break;
        }
    }
    return totval;
}
int main()
{
    str tri[1000];
    int w;
    cin >> w;
    int sz;
    cin >> sz;
    for (int i = 0; i < sz; i++)
    {
        cin >> tri[i].weight >> tri[i].profit;
    }
    float ans = knapsack(tri, sz, w);
    cout << ans << endl;
}
