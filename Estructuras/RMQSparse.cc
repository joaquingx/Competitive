#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector< vector<int> > vii;
vii M;
vector<int> A;

int BinaryLog(int N)
{
  return N ? 31 - __builtin_clz(N) : -10;
}

ll PreRMQ()
{
  int N = A.size();
  for(int i = 0 ; i < N ;++i) // Para tams de 2^0 , de cada pos. O(N)
    M[i][0] = i;
  for(int j = 1 ; 1  << j <= N ; ++j)
    {
      for(int i = 0 ; i + (1 << j ) - 1 < N ; ++i)
	{
	  if(A[M[i][j-1]] < A[M[i + (1 << (j-1))][j-1]])
	    M[i][j] = M[i][j-1];
	  else
	    M[i][j] = M[i + (1 << (j-1))][j-1];
	}
    }
  return 0;
}

ll GetMin(int i , int j)
{
  int k = BinaryLog(j-i+1);
  return A[M[i][k]] <= A[M[j - (1 << k) + 1][k]] ? M[i][k] : M[j-(1<<k)+1][k] ;
  //Devuelve la primera o segunda mitad del sgmetno .
}

int main()
{
  int n; cin >> n;A.resize(n);
  for(int i = 0 ; i < n ;++i)
    cin >> A[i];
  M.resize(n);
  for(int i = 0 ; i < n ;++i)
    M[i].resize(BinaryLog(n));
  PreRMQ();
  while(1)
    {
      int i,j ;  cin >> i >> j;
      cout << GetMin(i,j) << endl;
    }
  return 0;
}

