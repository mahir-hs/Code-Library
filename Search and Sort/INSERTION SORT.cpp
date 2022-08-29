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

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && key < arr[j]) //check previous value is greater the current or not
        {
            arr[j + 1] = arr[j]; // if greter,then it will move up from the current position
            j--;
        }
        arr[j + 1] = key; // go to the left-most position where all the left value is less
    }
}
int main()
{
    int arr[] = {7, 2, 1, 4, 5, 3};
    insertion_sort(arr, 6);
    for (auto k : arr)
    {
        cout << k << " ";
    }
    cout << endl;
}
