#include <bits/stdc++.h>
using namespace std;
/*
  To list the strongly connected components(SCC) in a graph.
  Kosaraju Algorithm:
  dfs1: Like a Topological Sort but with the condensed Graph.
  dfs2: For each dfs we obtain a SCC.
  initGraph(n): Initialization of the Adjacency's List(Original and Transposed Graph).
  vis,orded,cnx: Visit vector,Topo over Condesed Graph and SCC vector respectively.
*/

vector<vector < int > > Adj,AdjT;
vector<int> vis,order,cnx;

void dfs1(int u)
{
  vis[u]=1;
  for(int v : Adj[u])
    {
      if(!vis[v])
	dfs1(v);
    }
  order.push_back(u);
}

void dfs2(int u)
{
  vis[u] = 1;
  cnx.push_back(u);
  for(int v : AdjT[u])
    {
      if(!vis[v])
	dfs2(v);
    }
}
void initGraph(int n)
{
  Adj.resize(n);
  AdjT.resize(n);
}

int main()
{
  int n,m; cin >> n >> m ;
  initGraph(n);
  for(int i = 0 ;i < m; ++i)
    {
      int l,r; cin>> l >> r;
      --l,--r;
      Adj[l].push_back(r);
      AdjT[r].push_back(l);
    }
  vis.assign(n,0);
  for(int i = 0 ; i < n; ++i)
    {
      if(!vis[i])
	dfs1(i);
    }
  vis.assign(n,0);
  for(int i = 0 ;i < n ; ++i)
    {
      int v = order[n-i-1];
      if(!vis[v])
	{
	  dfs2(v);
	  cout << "Strongly Connected Component\n";
	  for(int j = 0 ; j < cnx.size() ; ++j)
	    cout << cnx[j] << " ";
	  cout << "\n"	  ;
	  cnx.clear();
	}	
    }
}
