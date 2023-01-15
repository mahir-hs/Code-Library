#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 200005
#define pb push_back
#define nl '\n'
#define mod 1000000009
#define vll vector<ll>
#define vvl vector<vll>



void mul(vvl &A,vvl &B,ll n)
{
	ll i,j,k;
	vector<vector<ll>> R;
	R.resize(n+10,vector<ll>(n+10,0LL));

	for (i=1; i<=n; i++)
	{
		for (j=1; j<=n; j++)
		{
			R[i][j]=0;
			for (k=1; k<=n; k++)
			{
				ll x = (A[i][k]*B[k][j])%mod;
				R[i][j]=(R[i][j]+x)%mod;
			}
		}
	}
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=n; j++)
		{
			A[i][j]=R[i][j];
		}
	}
}




void solve()
{
	/*
	*/

	int n,p;

	cin>>n>>p;
	// int origin[100][100],identity[100][100];
	vector<vector<ll>> origin;
	vector<vector<ll>> identity;
	origin.resize(n+10,vector<ll>(n+10,0LL));
	identity.resize(n+10,vector<ll>(n+10,0LL));

	for (int i = 1; i<=n; i++)
	{
		for (int j = 1; j<=n; j++)
		{
			cin>>origin[i][j];
			if (i==j)
				identity[i][j] = 1;

		}
	}
	while (p)
	{
		if (p%2==1)
		{
			mul(identity,origin,n);
			p--;
		}
		else {
			mul(origin,origin,n);
			p/=2;
		}
	}
	for (int i = 1; i<=n; i++)
	{
		for (int j = 1; j<=n; j++)
			cout<<identity[i][j]<<" ";
		cout<<nl;
	}





}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.out", "w", stdout);
#endif
	solve();
}
