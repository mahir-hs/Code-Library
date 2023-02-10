#include <bits/stdc++.h>
using namespace std;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define nl '\n'

const ll M1 = 1000000007 , M2 = 10000019 , h1 = 999983 , h2 = 99991 ;
char text[2000][2000],pattern[2000][2000];
ll hash_matrix[2000][2000];
int row,col,trow,tcol;

ll pattern_hash()
{
    // every row's hash values in the first column
    for (int i = 0; i<trow; i++)
    {
        ll p=0;
        for (int j = 0; j<tcol; j++)
        {
            p = (p*h1+pattern[i][j])%M1;
        }
        hash_matrix[i][0] = p;
    }

    // 1st columns hash value
    ll p = 0;
    for (int i = 0; i<trow; i++)
    {
        p = (p*h2+hash_matrix[i][0])%M2;
    }
    hash_matrix[0][0] = p;
    return hash_matrix[0][0];
}


void text_hash()
{
    ll d = 1;
    // no idea why the below for loop works
    for (int i=1; i<tcol; i++)
        d = (d*h1)%M1;

    // every rows hash value in every index only row wise
    for (int i = 0; i<row; i++)
    {
        ll p = 0;
        // pattern's col length hash value of each row
        for (int j = 0; j<tcol; j++)
        {
            p = (p*h1+text[i][j])%M1;
        }

        // sliding the hash in the same column after the 1st index
        for (int j = 0; j<=col-tcol; j++)
        {
            hash_matrix[i][j] = p;
            p = (((p-text[i][j]*d)%M1)*h1+text[i][j+tcol])%M1;
            p = (p+M1)%M1;
        }
    }
    d = 1;
    // again no idea how it's working
    for (int i=1; i<trow; i++)
        d = (d*h2)%M2;

    //every col hash value calculating
    for (int j = 0; j<=col-tcol; j++)
    {
        ll p = 0;
        //each col row's hash value calculating
        for (int i = 0; i<trow; i++)
        {
            p = (p*h2+hash_matrix[i][j])%M2;
        }
        // sliding row after the 1st index
        for (int i = 0; i<=row-trow; i++)
        {
            ll temp = p;
            p = (((p-hash_matrix[i][j]*d)%M2)*h2+hash_matrix[i+trow][j])%M2;
            p = (p+M2)%M2;
            hash_matrix[i][j] = temp;
        }
    }
}



void solve()
{
    /*
     */


    cin>>row>>col;
    for (int i=0; i<row; i++)
        cin>>text[i];
    cin>>trow>>tcol;
    for (int i = 0; i<trow; i++)
        cin>>pattern[i];

    ll h = pattern_hash();

    text_hash();

    int ans = 0;

    for (int i = 0; i<=row-trow; i++)
    {
        for (int j = 0; j<=col-tcol; j++)
        {
            if (hash_matrix[i][j]==h)
                ans++;
        }
    }
    cout<<ans<<nl;
}


int main()
{
    FIO;
    int t;
    cin >> t;
    while (t--)
        solve();
    //uva 11019
}



