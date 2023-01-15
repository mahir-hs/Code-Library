#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 2000056
#define vll vector<ll>
#define pb push_back
#define nl '\n'


int lg2[mx];
void lg()
{
    for (int i = 2; i <= mx; i++)
    {
        lg2[i] = lg2[i / 2] + 1;
    }
}

void solve()
{

    /*
     O(n(log*n)+Q)
    */

    int a, b;
    cin >> a >> b;

    ll v[a];
    memset(v, 0, sizeof(v));
    for (int i = 0; i < a; i++)
        cin >> v[i];

    ll arr[a + 10][24] = {{0}};
    for (int i = 0; i < a; i++)
    {
        arr[i + 1][0] = v[i];
    }
    for (int j = 1; j < 18; j++)
    {
        for (int i = 1; i + (1 << j) <= a + 1; i++)
        {
            arr[i][j] = min(arr[i][j - 1], arr[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (b--)
    {
        int f, l;
        cin >> f >> l;
        int k = 32 - __builtin_clz(l - f + 1) - 1;
        cout << min(arr[f][k], arr[l - (1 << (k)) + 1][k]) << nl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}