#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 2000056
#define pb push_back
#define nl '\n'
int v[mx];
struct ST {
    ll Tree[mx * 4], lazy[mx * 4];
    ST()
    {
        memset(Tree, 0LL, sizeof(Tree));
        memset(Tree, 0LL, sizeof(lazy));
    }

    void push(int node, int lx, int rx)
    {
        if (lx == rx) // node is the leaf
            return;

        int mid = (lx + rx) >> 1;
        lazy[node * 2 ] += lazy[node];
        lazy[node * 2 + 1 ] += lazy[node];
        Tree[node * 2] += (mid - lx + 1) * lazy[node];
        Tree[node * 2 + 1 ] += (rx - mid) * lazy[node];
        lazy[node] = 0;

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

    ll query(int node, int lx, int rx, int l, int r)
    {

        if (lazy[node] != 0)
        {
            push(node, lx, rx);
        }
        if (lx > r or rx < l)
            return 0; //বাইরে চলে গিয়েছে
        if (lx >= l and r >= rx)
        {
            return Tree[node]; //রিলেভেন্ট সেগমেন্ট
        }

        int left = node * 2; //আরো ভাঙতে হবে
        int right = node * 2 + 1;
        int mid = (lx + rx) / 2;

        ll leftQ = query(left, lx, mid, l, r);
        ll rightQ = query(right, mid + 1, rx, l, r);

        return leftQ + rightQ; //বাম এবং ডান পাশের যোগফল
    }

    void update(int node, int lx, int rx, int l, int r, int val)
    {
        if (lazy[node] != 0)
            push(node, lx, rx);
        if (lx > r or rx < l)
            return; //বাইরে চলে গিয়েছে
        if (lx >= l and rx <= r)
        {

            Tree[node] += ((rx - lx + 1) * val); //রিলেভেন্ট সেগমেন্ট
            lazy[node] += val;
            return;
        }

        int left = node * 2; //আরো ভাঙতে হবে
        int right = node * 2 + 1;
        int mid = (lx + rx) / 2;
        update(left, lx, mid, l, r, val);
        update(right, mid + 1, rx, l, r, val);
        Tree[node] = Tree[left] + Tree[right];
    }
} st;

void solve()
{
    /*

     */

    int a, b;
    cin >> a >> b;

    st.init(1, 1, a);

    while (b--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int l, r, val;
            cin >> l >> r >> val;
            l++;
            st.update(1, 1, a, l, r, val);
        }
        else
        {
            int l;
            cin >> l;
            l++;
            cout << st.query(1, 1, a, l, l) << nl;
        }
    }


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