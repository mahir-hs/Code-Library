const int mx = (int)1e5+10;
int timer;
int start[mx],end[mx],flatTree[2*mx+10];
vector<int> v[mx];

void dfs(int node,int par)
{
    start[node] = timer;
    flatTree[timer] = node;
    timer++;

    for (auto k:v[node])
    {
        if (k!=par)
        {
            dfs(k,node);
        }
    }
    end[node] = timer;
    flatTree[timer] = node;
    timer++;
}
