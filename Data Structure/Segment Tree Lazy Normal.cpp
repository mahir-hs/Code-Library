#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 2000056
#define pb push_back
#define nl '\n'



int v[mx];
struct ST {
    ll Tree[mx * 4], prop[mx * 4];
    ST()
    {
        memset(Tree, 0LL, sizeof(Tree));
        memset(Tree, 0LL, sizeof(prop));
    }
    void init(int node, int b, int e)
    {
        if (b == e)
        {
            Tree[node] = v[b];
            return;
        }

        int left = 2 * node;
        int right = 2 * node + 1;
        int mid = (b + e) / 2;
        init(left, b, mid);
        init(right, mid + 1, e);
        Tree[node] = Tree[left] + Tree[right];
    }

    ll query(int node, int b, int e, int i, int j, int carry)
    {
        if (i > e or j < b)
            return 0; //বাইরে চলে গিয়েছে
        if (b >= i and j >= e)
        {
            return Tree[node] + carry * (e - b + 1); //রিলেভেন্ট সেগমেন্ট
        }

        int left = node * 2; //আরো ভাঙতে হবে
        int right = node * 2 + 1;
        int mid = (b + e) / 2;

        ll leftQ = query(left, b, mid, i, j, carry + prop[node]);
        ll rightQ = query(right, mid + 1, e, i, j, carry + prop[node]);

        return leftQ + rightQ; //বাম এবং ডান পাশের যোগফল
    }

    void update(int node, int b, int e, int i, int j, ll val)
    {
        if (j < b or i > e)
            return; //বাইরে চলে গিয়েছে
        if (b >= i and e <= j)
        {
            Tree[node] += ((e - b + 1) * val); //রিলেভেন্ট সেগমেন্ট
            prop[node] += val;
            return;
        }

        int left = node * 2; //আরো ভাঙতে হবে
        int right = node * 2 + 1;
        int mid = (b + e) / 2;
        update(left, b, mid, i, j, val);
        update(right, mid + 1, e, i, j, val);
        Tree[node] = Tree[left] + Tree[right] + (e - b + 1) * prop[node];
    }
} st[2];

void solve()
{
    /*

     */


}
void init()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();



}