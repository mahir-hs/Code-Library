
//DISJOINT SET
/*
  operations: 
  1. find(u) -> in which set u belongs to
  2. union(u,v) -> merge sets of u and v
  3. MakeSet(u) -> initialize u as a set
  4. isSameSet(u,v) -> check if u and v belongs to the same set or not(isFriend)

  how does it work:
  1. Identification -> Every set has a representative (that's why we need uniq set)
  2. Relation -> parent - child
  
  simulation:
  1. initially we make all element as its own parent 
  2. then we wil do union by find function, if the representative are NOT SAME,
     then we will merge or union them.
*/

#include <bits/stdc++.h>
using namespace std;

#define mx 100

int parent[mx];

void init() // initialize
{
    for (int i = 1; i <= 8; i++)
    {
        parent[i] = i;
    }
}

int Find(int u) // Finding the parent
{
    if (u == parent[u])
    {
        return u;
    }
    return parent[u] = Find(parent[u]); // path compresion
}

void show()
{
    for (int i = 1; i <= 8; i++)
    {
        cout << "parent of " << i << " is " << parent[i] << endl;
    }
}

void Union(int u, int v)
{
    int p = Find(u);
    int q = Find(v);

    if (p != q)
    {
        parent[q] = p;
    }
}

bool isFriend(int u, int v)
{
    int p = Find(u);
    int q = Find(v);
    return (p == q);
}

int main()
{
    init();
}