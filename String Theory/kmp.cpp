#include <bits/stdc++.h>
using namespace std;
#define vii vector<int>
#define nl '\n'

vii build(string pattern)
{
    vii lps(pattern.length());
    int index = 0;

    for (int i = 1; i<(int)pattern.length();)
    {
        if (pattern[i]==pattern[index])
        {
            lps[i] = index + 1;
            index++;
            i++;
        }
        else
        {
            if (index)
            {
                index = lps[index-1];
            }
            else
            {
                lps[i] = index;
                i++;
            }
        }
    }
    return lps;

}


void kmp(string text,string pattern)
{
    vii lps = build(pattern);
    bool found = false;

    int i = 0,j = 0;
//   i--> text, j--> pattern
    while (i<(int)text.length())
    {
        if (text[i]==pattern[j])
            i++,j++;
        else
        {
            if (j)
            {
                j = lps[j-1];
            }
            else
                i++;
        }

        if (j==(int)pattern.length())
        {
            cout<<"Found Match: "<<(i-pattern.length())<<nl;
            j = lps[j-1];
            found = true;
        }
    }

    if (found==false)
        cout<<"not found!"<<nl;

}


void solve()
{
    /*
     */

    string text,pattern;
    cin>>text>>pattern;
    kmp(text,pattern);
}


int main()
{
    solve();
}



