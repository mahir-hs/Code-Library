#include <bits/stdc++.h>
using namespace std;

int ternarysearch(int a[], int left, int right , int target)
{
    int mid1 = left + (right - left)/3;
    int mid2 = left + 2*(right - left)/3;
    if (target == a[mid1]) {
        return mid1;
    }
    else if (target == a[mid2]) {
        return mid2;
    }
    else if (mid1 >= mid2) {
        return -1;
    }
    if (target < a[mid1]) {
        return ternarysearch(a, left, mid1-1, target);
    }
    if (target > a[mid2]) {
        return ternarysearch(a, mid2+1, right, target);
    }
    else {
        return ternarysearch(a, mid1+1, mid2-1, target);
    }
}
int a,b;




// unimodal function
double f(int x)
{
    double val =(b*x)+ ((double)(a*1.0)/sqrt(x+1));
    return val;
}
void solve()
{
    /*

    */

    cin>>a>>b;
    int l = 0,r = a;
    while (r-l>2)
    {
        int m1 = l+(r-l)/3;
        int m2 = r-(r-l)/3;
        if (f(m1)<f(m2))
        {
            r = m2;
        }
        else if (f(m1)>f(m2))
        {
            l = m1;
        }
        else
        {
            l = m1;
            r = m2;
        }
    }

    double ans =  (a*1.0)/sqrt(1);
    for (int i=l; i<=r; i++)
    {
        ans = min(ans,f(i));
    }
    cout<<SP(10,ans)<<nl;
}

int main()
{
    int a[9]= {1,2,3,4,5,6,7,8,9};
    int x=ternarysearch(a,0,8,9);
    cout<<x;
}