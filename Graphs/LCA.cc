#include <bits/stdc++.h>
#define NEUTRO -1
using namespace std;
int n;
vector<int> st,height,vis,preorder,first;
vector< vector< int > > Adj;

int lca_dfs(int u, int h=1)
{
  vis[u] = 1;
  // height.push_back(h);
  height[u] = h;
  preorder.push_back(u);
  for(int v : Adj[u])
    {
      if(!vis[v])
	{
	  lca_dfs(v,h+1);
	  preorder.push_back(v);
	  // height.push_back(h);
	}
    }
}

int oper(int a , int b)
{
  return min(a,b);
}

void build()
{
  for(int i = n-1 ; i >= 0 ; --i) st[i] = oper( st[i<<1] ,st[i<<1|1] ) ;
  // st[i] = st[2*i] + st[2*i+1]
}

void modify(int key, int value)
{
  for(st[key+=n]  = value ; key > 1 ; key >>= 1)
    st[key>>1] = oper(st[key],st[key^1]);
  // Se asigna el nuevo valor a st[key+=n], y se refresca todos los padres.
}

int query(int l , int r )
{
  int ans = NEUTRO,idx;
  for(l += n , r += n  ;  l < r ; l>>=1 , r>>=1) 
    {
      // cout << ans << "\n";
      // cout << r << "\n";
      if(l&1) {
	if(ans < height[ st[l] ])
	  {
	    ans = height[st[l]];
	    idx = st[l++];
	  }
      }
      if(r&1) {
	if(ans < height[ st[--r] ])
	  {
	    ans = height[st[r]];
	    idx = st[r];
	  }
      }
    }
  return idx;
}

void printST()
{
  for(int i = 0 ; i < 2*n ; ++i)
    {
      cout << st[i] << " ";
    }
  cout << "\n";  
}


// the preprocessing function
void lca_prepare(int root)
{
    int p = (int) Adj.size();
    height.resize(p);
    preorder.reserve(p*2);
    vis.assign(p, 0);
    lca_dfs(root);

    int m = (int) preorder.size();
    n = m;
    st.assign(m * 2 + 1, -1);
    for(int i = 0 ; i < m ; ++i) // los elementos ingresan al piso(hojas).
      st[i+m] = preorder[i];
    build();
    printST();
    first.assign(n, -1);
    for (int i = 0; i < m; ++i)
    {
        int v = preorder[i];
        if (first[v] == -1)
            first[v] = i;
    }
}



int lca(int a, int b)
{
    int left = first[a], right = first[b];
    if (left > right) swap(left, right);
    return query(left,right);
}


int main()
{
  int n,m,root; cin >> n  >> m >> root;
  Adj.resize(n);
  for(int i = 0 ; i < m ; ++i)
    {
      int l , r; cin >> l >> r;
      --l; --r;
      Adj[l].push_back(r);
      Adj[r].push_back(l);
    }
  lca_prepare(root);
  while(true)
    {
      int v1,v2;
      cin >> v1 >> v2 ;
      --v1;--v2;
      cout << lca(v1,v2);
    }
  return 0;
}
