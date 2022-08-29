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

///cout<<"Case "<<z++<<": "<<__<<endl;

int main()
{
    //Kadane's algorithm looks for largest positive subarray sum O(n)

    vii v = {-2, -3, 4, -1, -2, 1, 5, -3};
    int start = 0, end = 0, s = 0;
    int max_val_till_now = INT_MIN;
    int now_val = 0;
    for (int i = 0; i < v.size(); i++)
    {
        now_val += v[i];
        if (now_val > max_val_till_now)
        {
            max_val_till_now = now_val;
            start = s;
            end = i; //if the now_val is greater then the previous max_till
                     //ending index should be i
        }
        if (now_val < 0)
        {
            now_val = 0;
            s = i + 1; //if now_val become less then zero, then the starting index probably next one
        }
    }
    cout << start << " " << end << " " << max_val_till_now;
}