#include <bits/stdc++.h>
using namespace std;
#define INF 2*1e12
typedef long long ENTERO;
struct edge{ENTERO to, length;};
typedef vector< vector< edge > > Adjacency;

Adjacency List;
vector<ENTERO> who;

// Dijkstra con Colas de Prioridad O( (n + m) * logn )
vector<ENTERO> NiceDijkstra(Adjacency &Grafo, ENTERO source)
{
  vector<ENTERO> dist(Grafo.size(),INF); // VECTOR DE DISTANCIAS.
  dist[source] = 0; // Init de distancias.
  set< pair <ENTERO, ENTERO > > now; // distancia , indice
  now.insert( {0,source} ); // Cola de Prioridad que elige el vertice siguiente a escoger.
  while(!(now.empty()))
    {
      ENTERO where = now.begin()->second; // Escoge el nodo mas conveniente.
      now.erase(now.begin());
      for(auto edge : Grafo[where])
	{
	  if(dist[edge.to] > dist[where] + edge.length) // si existe una arista mas conveniente go.
	    {
	      now.erase( {dist[edge.to],edge.to} ); // borramos el que existia.
	      dist[edge.to] = dist[where] + edge.length ; //actualizamos vector de dist.
	      now.insert( { dist[edge.to] , edge.to  } ); // actualizamos priority queue.
	    }
	}
    }
  return dist;
}

void initGrafo()
{
  int n,m; cin >> n >> m;
  List.resize(n);
  for(int i = 0 ; i < m ; ++i)
    {
      ENTERO ini,fin,peso;
      cin >> ini >> fin >> peso;
      ini -=1;fin-=1;
      List[ini].push_back({fin,peso});
      List[fin].push_back({ini,peso});
    }
  vector<ENTERO> distancias = NiceDijkstra(List,0);
  for(int i = 0 ; i < distancias.size() ; ++i)
    cout << distancias[i] << " ";
  cout << "\n";
}

int main()
{
  initGrafo();
  return 0;
}
