#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000009

int main()
{
// Binary Expo

	ll result = 1;
	ll base,power;
	cin>>base>>power;
	while (power)
		if (power%2==1)
		{
			result = (result * base)%mod;
			power--;
		}
		else
		{
			power/=2;
			base = (base*base)%mod;
		}

	if (result<0)
		result+=mod;
	cout<<(result%mod)<<nl;
}
