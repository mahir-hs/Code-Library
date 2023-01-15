#include <bits/stdc++.h>
using namespace std;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long



#define nl '\n'


int z = 1;

int lg2[550];
void lg()
{
    for (int i = 2; i <= 550; i++)
    {
        lg2[i] = lg2[i / 2] + 1;
    }
}
int sparse[11][510][510];

int getMax(int x, int y, int d)
{
    int k = lg2[d];
    int s = d - (1 << k);
    return max(max(sparse[k][x][y], sparse[k][x + s][y]), max(sparse[k][x][y + s], sparse[k][x + s][y + s]));
}

void solve()
{
    /*
    */

    int n,m;

    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>sparse[0][i][j];
        }
    }
    for (int k = 0; k <= 10; k++)
    {
        for (int i = 0; i + (1 << k+1) <= n; i++)
        {
            for (int j = 0; j + (1 << k+1) <= n; j++)
            {
                sparse[k+1][i][j] = max(
                                        max(
                                            sparse[k][i][j], sparse[k][i + (1 << (k))][j]),
                                        max(
                                            sparse[k][i][j + (1 << (k))], sparse[k][i + (1 << (k))][j + (1 << (k))]
                                        )
                                    );

                // cout<<k<<" "<<i<<" "<<j<<nl;
                // cout<<sparse[k][i][j]<<" "<<sparse[k][i + (1 << (k))][j]<<nl;
                // cout<<sparse[k][i][j + (1 << (k))]<<" "<<sparse[k][i + (1 << (k))][j + (1 << (k))]<<nl;
                // cout<<sparse[k+1][i][j]<<nl<<nl;
            }
            //cout<<nl;
        }
        //cout<<nl;
    }

    cout<<"Case "<<z++<<":"<<nl;

    while (m--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        l--;
        r--;
        cout<<getMax(l,r,k)<<nl;
    }


    for (int k = 0; k<10; k++)
    {
        for (int i=0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
                sparse[k][i][j]=0;
        }
    }

}




int main()
{

    FIO;

    lg();
    solve();
}



