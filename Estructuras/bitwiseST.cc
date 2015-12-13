#include <bits/stdc++.h>
#define N int(1e5)
#define NEUTRO 0
using namespace std;
int n; // tama;o del vector
// definicion ST.
int st[2*N]; // solo se necesita 2*N.

// int oper(int a,int b)
// {
//   return a+b);
// }

int oper(int a , int b)
{
  return a+b;
}

void build()
{
  for(int i = n-1 ; i >= 0 ; --i) st[i] = oper( st[i<<1] ,st[i<<1|1] ) ;
  // st[i] = st[2*i] + st[2*i+1]
}

void modify(int key, int value)
{
  for(st[key+=n]  = value ; key > 1 ; key >>= 1) st[key>>1] = oper(st[key],st[key^1]);
  // Se asigna el nuevo valor a st[key+=n], y se refresca todos los padres.
}

int query(int l , int r )
{
  int ans = NEUTRO;
  for(l += n , r += n  ;  l < r ; l>>=1 , r>>=1) 
    {
      // cout << ans << "\n";
      cout << r << "\n";
      if(l&1) ans= oper(ans,st[l++]);
      if(r&1) ans= oper(ans,st[--r]);
    }
  return ans;
}

void printST()
{
  for(int i = 0 ; i < 2*n ; ++i)
    {
      cout << st[i] << " ";
    }
  cout << "\n";  
}

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; ++i) // los elementos ingresan al piso(hojas).
    cin >> st[i+n];
  build();
  printST();
  cout << query(3,16) << "\n";
  return 0;
}



