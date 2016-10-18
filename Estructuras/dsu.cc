#include <bits/stdc++.h>
using namespace std;
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
