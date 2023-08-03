#include <bits/stdc++.h>
#define ll long long
#define vii vector<int>
#define qii queue<int>
#define pb push_back
#define mx (int)1e5+10

using namespace std;

int degree[mx];
vii G[mx];
vii done;
qii q;
int a, b;
void topsort()
{
    for (int i = 1; i <= a; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int primary_node = q.front();
        q.pop();
        done.pb(primary_node);
        for (int i = 0; i < G[primary_node].size(); i++)
        {
            int cur_node = G[primary_node][i];
            degree[cur_node]--;
            if (degree[cur_node] == 0)
            {
                q.push(cur_node);
            }
        }
    }
}
int main()
{

    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
        {
            break;
        }
        memset(degree, 0, sizeof degree);
        done.clear();
        for (int i = 0; i < b; i++)
        {
            int u, v;
            cin >> u >> v;
            degree[v]++;
            G[u].pb(v);
        }

        topsort();
        for (int i = 0; i < done.size() - 1; i++)
        {
            cout << done[i] << " ";
        }
        cout << done[done.size() - 1] << endl;
        for (int i = 1; i <= a; i++)
            G[i].clear();
    }

    //https://vjudge.net/problem/UVA-10305
}