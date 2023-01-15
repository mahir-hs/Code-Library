#include <bits/stdc++.h>
using namespace std;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define mx 2000056
#define vii vector<int>

#define nl '\n'

int d;
struct MO
{
    int l, r, idx;
} m[mx];
int arr[mx];
int mm[mx];
int cur_left, cur_right, ans;

bool ccc(MO a, MO b)
{
    if ((a.l / d) == (b.l / d))
        return a.r < b.r;
    return (a.l / d) < (b.l / d);
}

void solve()
{

    /*

    */

    int a;
    cin >> a;
    vii v(a + 1);
    for (int i = 1; i <= a; i++)
        cin >> v[i];
    int b;
    cin >> b;

    for (int i = 1; i <= b; i++)
    {
        int p, q;
        cin >> p >> q;
        m[i].l = p;
        m[i].r = q;
        m[i].idx = i;
    }
    d = sqrt(b);
    sort(m + 1, m + b + 1, ccc);

    for (int i = 1; i <= b; i++)
    {
        int l = m[i].l;
        int r = m[i].r;
        while (cur_left < l)
        {
            mm[v[cur_left]]--;
            if (mm[v[cur_left]] == 0)
            {
                ans--;
            }
            cur_left++;
        }
        while (cur_right > r)
        {
            mm[v[cur_right]]--;
            if (mm[v[cur_right]] == 0)
            {
                ans--;
            }
            cur_right--;
        }

        while (cur_left > l)
        {
            cur_left--;
            mm[v[cur_left]]++;
            if (mm[v[cur_left]] == 1)
            {
                ans++;
            }
        }
        while (cur_right < r)
        {
            cur_right++;
            mm[v[cur_right]]++;
            if (mm[v[cur_right]] == 1)
                ans++;
        }

        arr[m[i].idx] = ans;
    }

    for (int i = 1; i <= b; i++)
    {
        cout << arr[i] << nl;
    }
}

int main()
{

    FIO;

    solve();


}