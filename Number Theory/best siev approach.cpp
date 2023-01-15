#include <bits/stdc++.h>
#define ll long long
#define mx 2000005
#define vll vector<ll>
#define pb push_back
using namespace std;
bool marked[mx + 50];
vll primes;
void sieve()
{
    marked[0] = marked[1] = true;
    primes.pb(2);
    for (int i = 3; i * i <= mx; i += 2)
    {
        if (marked[i]==false)
        {
            for (int j = i * i; j <= mx; j += i * 2)
            {
                marked[j] = true;
            }
        }
    }
    for (int k = 3; k <= mx; k += 2)
    {
        if (!marked[k])
        {
            primes.pb(k);
        }
    }
}
int main()
{
    FIO;
    sieve();
}
