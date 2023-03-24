#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
   vector<int> rank, parent,size;
public: 
    DisjointSet(int n)
    {
        rank.resize(n+1, 0);
        parent.resize(n + 1);
        size.resize(n+1,0);
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
    void unionBysize(int u, int v)
    {
        int up = findparent(u);
        int uv = findparent(v);
        if(size[up]>size[uv]){
            parent[uv]=up;
            size[up]+=size[uv];
        }
        else{
            parent[up]=uv;
            size[uv]+=size[up];
        }
    }
};
int main()
{
    DisjointSet ds(7);
    // ds.unionBysize(1, 2);
    // ds.unionBysize(2, 3);
    // ds.unionBysize(4, 5);
    // ds.unionBysize(6, 7);
    // ds.unionBysize(5, 6);
    // ds.unionBysize(3,7);
    ds.unionBysize(1, 2);
    ds.unionBysize(2, 3);
    ds.unionBysize(4, 5);
    ds.unionBysize(6, 7);
    ds.unionBysize(5, 6);
    if(ds.findparent(3)==ds.findparent(7))cout<<"Same\n";
    else cout<<"Not Same\n";
    ds.unionBysize(3,7);
    return 0;
}