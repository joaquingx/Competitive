#include <bits/stdc++.h>
using namespace std;

/*
  Create,Find and Merge Disjoints Sets in ~O(1) for operation.
  Disjoint Set Union:
  dsuCreate: Inicialization of the Dsu.
  dsuFind(v): Answer the identifier of the set of v belongs using Path Compression.
  dsuUnion(u,v): Merge u and v, using rank for overcome complexity.

*/

vector<int> p,rating;

void dsuCreate(int u)
{
  p[u] = u;
  rating[u] = 0;
}

int dsuFind(int v)
{
  return (v == p[v] ? v : p[v] = (dsuFind(p[v]) ) );
}

void dsuUnion(int u , int v)
{
  u = dsuFind(u);
  v = dsuFind(v);
  if(rating[u] > rating[v])
    p[v] = u;
  else
    if(rating[u] == rating[v])
      {
	p[u] = v;
	++rating[u];
      }
    else
      p[u] = v;  
}


int main()
{
  
  return 0;
}
