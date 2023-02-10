// #include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const long long MOD [] = {1000000007LL, 2117566807LL, 1000000007LL, 1000000037LL};
const long long BASE[] = {1572872831LL, 1971536491LL, 1000003LL, 31};

class FrontHash
{

private:
    long long base,mods,len;
    vector<long long> hashing,powers;
public:
    void init(const string &s ,const long long &_base,const long long _mods)
    {
        this->base = _base;
        this->mods = _mods;
        this->len = s.size();
        this->powers.assign(len+10,0);
        this->hashing.assign(len+10,0);
        long long calculateHash = 0;
        powers[0] = 1;
        for (int i = 1; i <= len; ++i)
        {
            powers[i] = (powers[i-1]*this->base)%this->mods;
        }

        for (int i = 0; i<len; i++)
        {
            calculateHash = (calculateHash*this->base)+s[i];
            calculateHash%=this->mods;
            this->hashing[i] = calculateHash;

        }
    }

    long long getFrontHash(int l,int r)
    {
        long long ret = this->hashing[r];
        if (l>0)
        {
            ret = (ret-this->powers[r-l+1]*this->hashing[l-1])%this->mods;
            if (ret<0)
                ret+=this->mods;
        }
        return ret;
    }

};



class BackHash
{
private:
    long long base,mods,len;
    vector<long long> hashing,powers;
public:
    void init(const string &s ,const long long &_base,const long long _mods)
    {
        this->base = _base;
        this->mods = _mods;
        this->len = s.size();
        this->powers.assign(len+10,0);
        this->hashing.assign(len+10,0);
        long long calculateHash = 0;
        powers[0] = 1;
        for (int i = 1; i <= len; ++i)
        {
            powers[i] = (powers[i-1]*this->base)%this->mods;
        }

        for (int i = len-1; i>=0; i--)
        {
            calculateHash = (calculateHash*this->base)+s[i];
            calculateHash%=this->mods;
            this->hashing[i] = calculateHash;

        }
    }

    long long getBackHash(int l,int r)
    {
        long long ret = this->hashing[l];
        if (r+1<len)
        {
            ret = (ret-this->powers[r-l+1]*this->hashing[r+1])%this->mods;
            if (ret<0)
                ret+=this->mods;
        }
        return ret;
    }

};

void solve()
{
    /*
        0'based index'd hashing
     */
    string s = "abcddcbxxyyxxabc";
    FrontHash F;
    BackHash B;
    F.init(s,BASE[0],MOD[0]);
    B.init(s,BASE[0],MOD[0]);
    ///for "abcd"
    cout<<(F.getFrontHash(0,3)==B.getBackHash(0,3))<<endl;
    //bcddcb
    cout<<(F.getFrontHash(1,6)==B.getBackHash(1,6))<<endl;
}


int main()
{
    FIO;
    solve();
}



