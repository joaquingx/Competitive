#include <bits/stdc++.h>
#define MAX int(5*1e6+100) // Numero Maximo de la cadena.
#define MOD 5000002 // Modulo primo que usariamos xD
#define PRIME 7 // El primo por el que multiplicaremos continuamente!.
using namespace std;
typedef unsigned long long ull;
int med,n,medb,a,b;
ull ihash[MAX],rhash[MAX],POWS[MAX]; // ihash , hasheamos la cadena normalmente, rhash , hasheo inverso
string pattern;

inline void init()
{
  ihash[0] = 0;
  rhash[0] = 0;
  POWS[0] = 1;
  for(int i = 1 ;  i <= n ; ++i )
    {
      // deberia ir bajo un modulo, en este caso es ull
      ihash[i] = (ihash[i-1] * PRIME + pattern[i-1]) ; 
      rhash[i] = (rhash[i-1] * PRIME + pattern[n-i]) ;
      POWS[i] = (POWS[i-1] * PRIME);
    }
}

inline ull GetHash(int a, int b)
{
  return ihash[b] - ihash[a] * POWS[b-a];// da un segmento del hash en O(1)
}

inline ull GetRHash(int a , int b)
{
  return rhash[b] - rhash[a] *  POWS[b-a];
}

void PowiPrint()
{
  cout << "Powis:" << "\n";
  for(int i = 0 ; i <= n ; ++i)
    cout << POWS[i] << "\n";
}
void imprime()
{
  cout << "Hashes:\n";
  for(int i = 0 ; i <= n ; ++i )
    cout << ihash[i] << "\n";
  cout << "RHashes\n";
  for(int i = 0 ; i <= n ; ++i )
    cout << rhash[i] << "\n";
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin >> pattern;
  n = pattern.size();
  init();
  imprime();
  return 0;
}
