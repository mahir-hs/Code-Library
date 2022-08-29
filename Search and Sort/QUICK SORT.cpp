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

int Partition(int *arr, int start, int end)
{
    int pivot = arr[end];      //taking the last element
    int partion_index = start; // the index which we are going to swap to the left
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot) //if arr[i] is less or equal to the pivot we will swap it with the
                             // left most partion index
        {
            swap(arr[i], arr[partion_index]);
            ++partion_index;
        }
    }
    swap(arr[partion_index], arr[end]); //swap the first greater element with the pivot value
    return partion_index;
}

void quick_sort(int *arr, int start, int end)
{
    if (start < end)
    {
        int partion_index = Partition(arr, start, end); //finding the middle value first
        quick_sort(arr, start, partion_index - 1);      //left side
        quick_sort(arr, partion_index + 1, end);        //right side
    }
}

int main()
{
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    quick_sort(arr, 0, 7);
    for (auto k : arr)
    {
        cout << k << " ";
    }
    cout << endl;
}
