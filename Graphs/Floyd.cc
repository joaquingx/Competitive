#include <bits/stdc++.h>
using namespace std;
struct edge
{
  int to,from,weight;
  edge(){}
  edge(int a, int b , int c){
    to = a ; from = b ; weight = c;
  }
};

void init(int m, vector< edge > &  aristas) // If exists an edge, then d[to][from] = weight
{
  for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j)
      d[i][j] = 0;
  for(int i = 0 ; i < m ; ++i)
    {
      int to = aristas[i].to, from = aristas[i].from, weight = aristas[i].weight;
      d[to][from] =  d[from][to]  = weight;
    }
}

void floyd( int d[][])
{
  for(int k = 0 ; k < n ; ++k)
    for(int i = 0 ; i < n ; ++i)
      for(int j = 0 ; j < n ; ++j)
	d[i][j] = min( d[i][j] , d[i][k] + d[k][j]);
}



int main()
{
  return 0;
}
