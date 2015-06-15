#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector< pair<int,pii> > vii;

// union find structure
vector<int> father,rank;//en c++11 se caga por el nombre rank
inline void initUF(int n)
{
  rank.resize(n);
  father.resize(n);
  for(int i = 0  ; i < n; ++i)
    father[i] = i;
}

int find(int x)
{
  if(x == father[x])
    return x;
  return find(father[x]);
}

inline int join(int x,int y) // path compression.
{
  int xroot = find(x), yroot = find(y);
  if(rank[x] > rank[y])
    father[y] = father[x];
  else 
    {
      if(rank[y] > rank[x])
	father[x] = father[y];
      else
	{
	  father[y] = father[x];
	  ++rank[x];
	}
    }
}

// union find structure
//kruskal

inline long long Kruskal(vii Graph,int n) // vector< weight, pair<from,to> >
{
  sort(Graph.begin(),Graph.end());
  initUF(n);
  int u = 0;
  long long tweight = 0;
  for(int i = 0 ; i < Graph.size() ; ++i)
    {
      if(find(Graph[i].second.first) != find(Graph[i].second.second) )
	{
	  ++u;
	  tweight+=Graph[i].first;
	  if(u == n-1)
	    return tweight;
	  join(Graph[i].second.first,Graph[i].second.second);	  
	}
    }
  return -1;
}
//Kruskal


int main()
{
  int weight,from,to,n,e;
  vii grafo;
  cin >> n >> e;
  for(int i = 0 ; i < e ; ++i)  
    {
      cin >> weight >> from >> to;
      grafo.push_back(make_pair(weight,make_pair(from,to)));
      grafo.push_back(make_pair(weight,make_pair(to,from)));
    }
  cout << Kruskal(grafo,n) << "\n"; 
  return 0;
}
