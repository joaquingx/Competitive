#include <bits/stdc++.h>
using namespace std;
vector<vector < int > > Adj;
vector<int> vis,Topo;

void dfs(int u )
{
  vis[u] = 1;
  for(int v : Adj[u])
    {
      if( !( vis[v]) )
	dfs(v);
    }
  Topo.push_back(u);
}


int main()
{
  int n,m; cin >> n >> m ;
  Adj.resize(n);
  for(int i = 0 ;i < m; ++i)
    {
      int l,r; cin>> l >> r;
      --l;--r;
      Adj[l].push_back(r);
    }
  vis.assign(n,0);
  Topo.clear();
  for(int i = 0 ; i < n; ++i) // if does not exist cycles
    {
      if(!vis[i])
	dfs(i);
    }
  reverse(Topo.begin(),Topo.end());
  for(int i = 0 ; i < Topo.size() ; ++i)
    {
      cout << Topo[i]+1 << " ";
    }
  cout << "\n";
  return 0;
}
