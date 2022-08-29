#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pi acos(-1.0)
#define ll long long
#define ull unsigned ll
#define EPS 1e-12
#define MV 1e18
#define MX 1000000000
#define mx 200005
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define MEM(a, x) memset(a, x, sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pul pair<ull, ull>
#define mii map<int, int>
#define mll map<ll, ll>
#define vip vector<pair<int, int>>
#define vlp vector<pair<ll, ll>>
#define djk priority_queue<pll, vlp, greater<pll>>
#define pb push_back
#define mp make_pair
const int INF = 0x3f3f3f3f;
using namespace std;
int cnt = 0;
int partion(int *arr, int start, int end)
{
    int pivot = arr[start];
    while (start != end)
    {
        if (pivot == arr[start])
        {
            if (arr[end] > pivot)
            {
                end--;
            }
            else
            {
                swap(arr[start], arr[end]);
                pivot = arr[end];
                start++;
            }
        }
        else if (pivot == arr[end])
        {
            if (arr[start] < pivot)
            {
                start++;
            }
            else
            {
                swap(arr[start], arr[end]);
                pivot = arr[start];
                end--;
            }
        }
    }

    return start;
}
void quick(int *arr, int start, int end)
{

    if (start < end)
    {
        int partion_index = partion(arr, start, end);
        quick(arr, start, partion_index - 1);
        quick(arr, partion_index + 1, end);
        cnt++;
    }
}
int main()
{
    int x;
    cin >> x;
    int arr[x];
    for (auto &k : arr)
    {
        cin >> k;
    }

    quick(arr, 0, x - 1);
    cout << cnt << endl;
    for (int i = 0; i < x; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}