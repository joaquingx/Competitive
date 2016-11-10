#include <bits/stdc++.h>
#define MAXN int(1e5)
using namespace std;
/*
  Finding the bridges in a graph.
  dfs(): Searching for edges that goes to the ancesters, if one of that exists
  then that edge isn't a bridge.
  Vars:
  bridges: Save the edges that are bridges.
  used: mark the nodes that are used.
*/

vector< vector< int> >  Adj;
vector< pair< int , int > > bridges;
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];

void dfs (int u, int p = -1) {
  used[u] = true;
  tin[u] = fup[u] = timer++;
  for(int v : Adj[u])
    {
      if(p == v) continue;
      if(used[v])
	fup[u] = min( fup[u] , tin[v]);
      else
	{
	  dfs(v,u);
	  fup[u] = min( fup[u] , fup[v] ) ;
	  if(fup[v] > tin[u])
	    bridges.push_back( { u,v } );
	}
    }
}

void find_bridges(int n) {
  int timer = 0;
  for (int i = 0; i < n; ++i)
    used[i] = false;
  for (int i = 0; i < n; ++i)
    if (!used[i])
      dfs(i);
}


int main()
{
  int n , m ; cin >> n >> m;
  Adj.resize(n);
  for(int i = 0 ; i < m ; ++i)
    {
      int l,r; cin >> l >> r;
      --l;--r;
      Adj[l].push_back(r);
      Adj[r].push_back(l);
    }
  find_bridges(n);
  for(int i= 0 ;i < bridges.size() ; ++i)
    cout << bridges[i].first+1 << " " << bridges[i].second+1 << "\n";
  return 0;
}
