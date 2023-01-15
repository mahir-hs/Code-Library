#include <bits/stdc++.h>
using namespace std;

vii factors;
void Factors(int n)
{
	for (int i = 1; i*i <=n; ++i)
	{
		if (n%i==0)
		{
			factors.push_back(i);
			if (i!=n/i)
			{
				factors.push_back(n/i);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */

	Factors(12);
	return 0;
}