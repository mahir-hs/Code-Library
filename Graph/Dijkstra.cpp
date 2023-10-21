#include <bits/stdc++.h>
using namespace std;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define mx 100009
#define vll vector<ll>
#define pll pair<ll, ll>
#define vlp vector<pair<ll, ll>>
#define djk priority_queue<pll, vlp, greater<pll>>
#define pb push_back
#define mp make_pair
#define nl '\n'


int z = 1;
vlp G[mx];
vll dis(mx, LLONG_MAX);
vll parent(mx);
djk pq;
void clr()
{


    for (int i = 0; i<mx; i++)
    {
        G[i].clear();
        dis[i] = LLONG_MAX;
        parent[i] = 0;
    }

}

void dijkstra(int start)
{
    pq.push(mp(0, start));
    dis[start] = 0;
    while (!pq.empty())
    {
        int primary_node = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if(dis[primary_node]<w)
            continue;
        
        for (int i = 0; i < G[primary_node].size(); i++)
        {
            int cur_node = G[primary_node][i].first;
            int cur_weight = G[primary_node][i].second;
            if (cur_weight + dis[primary_node] < dis[cur_node])
            {
                dis[cur_node] = cur_weight + dis[primary_node];
                parent[cur_node] = primary_node;
                pq.push({dis[cur_node], cur_node});
            }
        }
    }
}


void solve()
{
    /*
    */
    clr();
    int node,edge;
    cin>>node>>edge;
    for (int i = 0; i<edge; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[u].pb({v,w});
        G[v].pb({u,w});
    }
    dijkstra(1);
    if (dis[node]==LLONG_MAX)
    {
        cout<<"Impossible"<<nl;
    }
    else
    {
        cout<<dis[node]<<nl;
    }
}




int main()
{

    FIO;
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif

    solve();
}
