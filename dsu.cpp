#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
public: 
   vector<int> rank, parent;
    DisjointSet(int n)
    {
        rank.resize(n+1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <=n; i++)
        {
            parent[i] = i;
        }
    }
    int findparent(int u)
    {
        // if the parent is himself
        if (u == parent[u])
        {
            return u;
        }
        return /*this is where we are doing parh compressin*/ parent[u] = /*this is normal findparent function*/ findparent(parent[u]);
    }
    void unionByrank(int u, int v)
    {
        int up = findparent(u);
        int uv = findparent(v);
        if(up==uv)return;
        if (rank[up] < rank[uv])
        {
            parent[up] = uv;
        }
        else if(rank[up]>rank[uv])
        {
            parent[uv] = up;
        }
        else{
            parent[uv]=up;
            rank[up]++;
        }
    }
};
int main()
{
    DisjointSet ds(7);
    ds.unionByrank(1, 2);
    ds.unionByrank(2, 3);
    ds.unionByrank(4, 5);
    ds.unionByrank(6, 7);
    ds.unionByrank(5, 6);
    ds.unionByrank(3,7);
    if(ds.findparent(3)==ds.findparent(7))cout<<"Same\n";
    else cout<<"Not Same\n";

    return 0;
}