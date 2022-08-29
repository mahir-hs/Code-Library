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
const int INF = 0x3f3f3f3f;
using namespace std;
// freopen("data.txt", "r", stdin);
// freopen("dataOut.txt", "w", stdout);
///cout<<"Case "<<z++<<": "<<__<<endl;

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int a = s;
    int b = mid + 1;
    int temp = s;
    int store[10];
    while (a <= mid && b <= e)
    {
        if (arr[a] < arr[b])
        {
            store[temp++] = arr[a++];
        }
        else
        {
            store[temp++] = arr[b++];
        }
    }
    while (a <= mid)
    {
        store[temp++] = arr[a++];
    }
    while (b <= e)
    {
        store[temp++] = arr[b++];
    }
    for (int k = s; k <= e; k++)
    {
        arr[k] = store[k];
    }
}

void mergesort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, e);
}
int main()
{
    int arr[10];
    int i = 0;
    while (~scanf("%d", &arr[i]))
    {
        ++i;
    }
    for (auto p : arr)
    {
        cout << p << " ";
    }
    cout << endl;
    mergesort(arr, 0, i - 1);

    for (auto p : arr)
    {
        cout << p << " ";
    }
}
